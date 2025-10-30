#include "NavigationBox.h"
#include <QskAspect.h>
#include <QskBoxShapeMetrics.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <qnamespace.h>


NavigationBox::NavigationBox() : QskLinearBox()
{
    this->setOrientation(Qt::Horizontal);
    // this->setFixedHeight(50); --> previously was set because the it became to big when the size of the window was big... something to consider in the future
    m_previousButton->setFixedWidth(75);

    m_nextButton->setFixedWidth(75);
    m_nextButton->setLayoutAlignmentHint(Qt::AlignRight);

    this->addItem(m_previousButton);
    this->addItem(m_nextButton);
}

NavigationButton* NavigationBox::getNextButton()
{
    return m_nextButton;
}

NavigationButton* NavigationBox::getPreviousButton()
{
    return m_previousButton;
}