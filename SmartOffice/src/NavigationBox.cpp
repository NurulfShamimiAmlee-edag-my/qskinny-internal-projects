#include "NavigationBox.h"
#include <QskLinearBox.h>
#include <qnamespace.h>

NavigationBox::NavigationBox() : QskLinearBox()
{
    this->setOrientation(Qt::Horizontal);
    this->setFixedHeight(50);
    this->addItem(m_previousButton);
    this->addItem(m_nextButton);
}