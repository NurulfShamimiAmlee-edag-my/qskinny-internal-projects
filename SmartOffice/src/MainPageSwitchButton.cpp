#include "MainPageSwitchButton.h"
#include <QskSwitchButton.h>

QSK_SUBCONTROL(MainPageSwitchButton, Groove)
QSK_SUBCONTROL(MainPageSwitchButton, Handle)
QSK_SUBCONTROL(MainPageSwitchButton, Icon)

MainPageSwitchButton::MainPageSwitchButton(QQuickItem* parent) : QskSwitchButton(parent)
{
    setSubcontrolProxy(QskSwitchButton::Groove, Groove);
    setSubcontrolProxy(QskSwitchButton::Handle, Handle);
    setSubcontrolProxy(QskSwitchButton::Icon, Icon);
    this->setLayoutAlignmentHint((Qt::AlignCenter));
}