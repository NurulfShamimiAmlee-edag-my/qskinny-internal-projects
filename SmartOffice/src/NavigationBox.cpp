#include "NavigationBox.h"
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <qnamespace.h>

NavigationBox::NavigationBox() : QskLinearBox()
{
    this->setOrientation(Qt::Horizontal);
    this->setFixedHeight(50);
    m_previousButton->setColor(QskPushButton::Panel, QColor("#8e8b63"));
    m_nextButton->setColor(QskPushButton::Panel, QColor("#8e8b63"));
    this->addItem(m_previousButton);
    this->addItem(m_nextButton);
}

QskPushButton* NavigationBox::getNextButton()
{
    return m_nextButton;
}

QskPushButton* NavigationBox::getPreviousButton()
{
    return m_previousButton;
}