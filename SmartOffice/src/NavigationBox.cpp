#include "NavigationBox.h"
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <qnamespace.h>

NavigationBox::NavigationBox() : QskLinearBox()
{
    this->setOrientation(Qt::Horizontal);
    this->setFixedHeight(50);
    m_previousButton->setColor(QskPushButton::Panel, QColor("#82f5d4"));
    m_previousButton->setColor(QskPushButton::Text, QColor("#5a756e"));
    m_nextButton->setColor(QskPushButton::Panel, QColor("#82f5d4"));
    m_nextButton->setColor(QskPushButton::Text, QColor("#5a756e"));
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