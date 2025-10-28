#include "MainPagePushButton.h"

QSK_SUBCONTROL(MainPagePushButton, Panel)
QSK_SUBCONTROL(MainPagePushButton, Text)

MainPagePushButton::MainPagePushButton(const QString& text, QQuickItem* parent) : QskPushButton(text, parent)
{
    setSubcontrolProxy(QskPushButton::Panel, Panel);
    setSubcontrolProxy(QskPushButton::Text, Text);
}