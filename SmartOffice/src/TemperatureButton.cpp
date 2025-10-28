#include "TemperatureButton.h"
#include <QskGraphicIO.h>
#include <QskGraphic.h>
#include <QskPushButton.h>
#include <qquickitem.h>

QSK_SUBCONTROL(TemperatureButton, Panel)
QSK_SUBCONTROL(TemperatureButton, Icon)

TemperatureButton::TemperatureButton() : QskPushButton()
{
    setSubcontrolProxy(QskPushButton::Panel, Panel);
    setSubcontrolProxy(QskPushButton::Icon, Icon);

    setIcon(QskGraphicIO::read(QString("assets/qvg/air-conditioner.qvg")));;
    setFixedSize(50,50);
    // setBoxShapeHint(50);
}
