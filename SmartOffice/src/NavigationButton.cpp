#include "NavigationButton.h"

QSK_SUBCONTROL(NavigationButton, Panel)
QSK_SUBCONTROL(NavigationButton, Text)

NavigationButton::NavigationButton(QString text) : QskPushButton(text)
{
    setSubcontrolProxy(QskPushButton::Panel, Panel);
    setSubcontrolProxy(QskPushButton::Text, Text);
}