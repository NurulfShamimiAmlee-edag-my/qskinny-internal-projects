#include "PageViewer.h"
#include "TopBar.h"
#include "BottomSection.h"
#include "NavigationBox.h"

#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <qobject.h>

PageViewer::PageViewer() : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);
    this->setPanel(true);
    
    this->setColor(QskLinearBox::Panel, QColor("#82d6f5"));
    auto* topBar = new TopBar();
    auto* bottomSection = new BottomSection();
    auto* navigationBox = new NavigationBox();
    m_totalPage = bottomSection->itemCount(); //calculate the number of items placed in a QskStackBox

    QObject::connect(topBar->getMenuButton(), &QskPushButton::clicked, [bottomSection, this]()
    {
        int currentPageNumber = bottomSection->currentIndex();
        if (currentPageNumber != m_totalPage - 1)
        {
            bottomSection->setCurrentIndex(m_totalPage - 1);
        }

    });

    QObject::connect(navigationBox->getNextButton(), &QskPushButton::clicked, [bottomSection, this]()
    {
        int currentPageNumber = bottomSection->currentIndex();
        if (currentPageNumber >= 0 && currentPageNumber < m_totalPage - 1)
        {
            bottomSection->setCurrentIndex(currentPageNumber + 1);
        }

    });

    QObject::connect(navigationBox->getPreviousButton(), &QskPushButton::clicked, [bottomSection, this]()
    {
        int currentPageNumber = bottomSection->currentIndex();
        if (currentPageNumber >= 1 && currentPageNumber < m_totalPage)
        {
            bottomSection->setCurrentIndex(currentPageNumber - 1);
        }
    });

    this->addItem(topBar);
    this->addItem(bottomSection);
    this->addItem(navigationBox);
}