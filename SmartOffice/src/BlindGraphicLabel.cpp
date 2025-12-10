#include "BlindGraphicLabel.h"

#include <QskGraphicIO.h>
#include <QskGraphic.h>

BlindGraphicLabel::BlindGraphicLabel() : QskGraphicLabel()
{
    setGraphic(QskGraphicIO::read(QString(":/assets/qvg/window.qvg")));
    setStrutSizeHint(QskGraphicLabel::Graphic, QSizeF(15,15));
}