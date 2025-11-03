#include "LightButton.h"
#include "SliderButtons.h"

#include <QskGraphicIO.h>
#include <QskGraphic.h>

LightButton::LightButton() : SliderButtons()
{
    setIcon(QskGraphicIO::read(QString("assets/qvg/lamp.qvg")));;
}