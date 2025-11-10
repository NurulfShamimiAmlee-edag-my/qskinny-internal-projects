#include "MasterSwitchButton.h"
#include <QskSwitchButton.h>

QSK_SUBCONTROL(MasterSwitchButton, Groove)
QSK_SUBCONTROL(MasterSwitchButton, Handle)
QSK_SUBCONTROL(MasterSwitchButton, Icon)

MasterSwitchButton::MasterSwitchButton(QQuickItem* parent) : QskSwitchButton(parent)
{
    setSubcontrolProxy(QskSwitchButton::Groove, Groove);
    setSubcontrolProxy(QskSwitchButton::Handle, Handle);
    setSubcontrolProxy(QskSwitchButton::Icon, Icon);
    setIconMode(ShowIconAlways);
}