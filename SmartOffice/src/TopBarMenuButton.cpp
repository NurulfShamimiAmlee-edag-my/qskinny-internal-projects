#include "TopBarMenuButton.h"

QSK_SUBCONTROL(TopBarMenuButton, Panel)
QSK_SUBCONTROL(TopBarMenuButton, Text)

TopBarMenuButton::TopBarMenuButton(): QskPushButton()
{
    setSubcontrolProxy(QskPushButton::Panel, Panel);
};