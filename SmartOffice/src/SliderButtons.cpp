#include "SliderButtons.h"
#include <QskAspect.h>
#include <QskPushButton.h>

QSK_SUBCONTROL(SliderButtons, Panel)
QSK_SUBCONTROL(SliderButtons, Icon)

SliderButtons::SliderButtons() : QskPushButton()
{
    setSubcontrolProxy(QskPushButton::Panel, Panel);
    setSubcontrolProxy(QskPushButton::Icon, Icon);
    setFixedSize(50,50);
}