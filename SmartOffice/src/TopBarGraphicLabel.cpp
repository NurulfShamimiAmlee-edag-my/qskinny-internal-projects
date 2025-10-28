#include "TopBarGraphicLabel.h"

QSK_SUBCONTROL(TopBarGraphicLabel, Panel)
QSK_SUBCONTROL(TopBarGraphicLabel, Graphic)

TopBarGraphicLabel::TopBarGraphicLabel(): QskGraphicLabel()
{
    setSubcontrolProxy(QskGraphicLabel::Panel, Panel);
    setSubcontrolProxy(QskGraphicLabel::Graphic, Graphic);
};
