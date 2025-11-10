#include "MainPageGraphicLabel.h"
#include <QskGraphicLabel.h>
#include <qquickitem.h>

QSK_SUBCONTROL(MainPageGraphicLabel, Panel)

MainPageGraphicLabel::MainPageGraphicLabel(const QskGraphic& graphic, QQuickItem* parent) : QskGraphicLabel(graphic, parent)
{
    setSubcontrolProxy(QskGraphicLabel::Panel, Panel);
    setSubcontrolProxy(QskGraphicLabel::Graphic, Graphic);
    // this->setFixedSize(200,200);
    this->setFixedSize(QSizeF(100,100));
    this->setLayoutAlignmentHint(Qt::AlignCenter);
}

MainPageGraphicLabel::MainPageGraphicLabel(QQuickItem* parent) : QskGraphicLabel(parent)
{
    
}