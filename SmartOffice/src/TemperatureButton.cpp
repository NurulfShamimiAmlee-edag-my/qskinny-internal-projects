#include "TemperatureButton.h"
#include <QskGraphicIO.h>
#include <QskGraphic.h>
#include <QskPushButton.h>
#include <qquickitem.h>


TemperatureButton::TemperatureButton() : SliderButtons()
{
    setIcon(QskGraphicIO::read(QString("assets/qvg/air-conditioner.qvg")));;
}
