#include "NavigationBox.h"
#include <QskAspect.h>
#include <QskBoxShapeMetrics.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <qnamespace.h>


NavigationBox::NavigationBox() : QskLinearBox()
{
    this->setOrientation(Qt::Horizontal);
    this->setFixedHeight(50);

    m_previousButton->setFixedSize(75,25);

    m_nextButton->setFixedSize(75,25);
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