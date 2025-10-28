#include "MainPageTextLabel.h"

QSK_SUBCONTROL(MainPageTextLabel, Panel)
QSK_SUBCONTROL(MainPageTextLabel, Text)

MainPageTextLabel::MainPageTextLabel(const QString& text, QQuickItem* parent) : QskTextLabel(text, parent)
{
    setSubcontrolProxy(QskTextLabel::Panel, Panel);
    setSubcontrolProxy(QskTextLabel::Text, Text);
}