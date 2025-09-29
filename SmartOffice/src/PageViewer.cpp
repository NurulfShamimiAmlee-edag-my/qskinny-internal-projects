#include "PageViewer.h"
#include "MainPage.h"
#include "TopBar.h"
#include "NavigationBox.h"

#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <qobject.h>

PageViewer::PageViewer() : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);
    this->setPanel(true);
    this->setColor(QskLinearBox::Panel, QColor("#d6d4ad"));
    auto* topBar = new TopBar();
    auto* bottomSection = new BottomSection();
    auto* navigationBox = new NavigationBox();

    QObject::connect(topBar->m_menuButton, &QskPushButton::clicked, [bottomSection]()
    {
        int currentPageNumber = bottomSection->currentIndex();
        if (currentPageNumber != 3)
        {
            bottomSection->setCurrentIndex(3);
        }

    });

    QObject::connect(navigationBox->m_nextButton, &QskPushButton::clicked, [bottomSection]()
    {
        int currentPageNumber = bottomSection->currentIndex();
        if (currentPageNumber >= 0 && currentPageNumber < 3)
        {
            bottomSection->setCurrentIndex(currentPageNumber + 1);
        }

    });

    QObject::connect(navigationBox->m_previousButton, &QskPushButton::clicked, [bottomSection]()
    {
        int currentPageNumber = bottomSection->currentIndex();
        if (currentPageNumber >= 1 && currentPageNumber < 4)
        {
            bottomSection->setCurrentIndex(currentPageNumber - 1);
        }
    });

    this->addItem(topBar);
    this->addItem(bottomSection);
    this->addItem(navigationBox);
}