#pragma once

#include <QskPushButton.h>

class SliderButtons : public QskPushButton
{
    public:
        QSK_SUBCONTROLS(Panel, Icon)
        SliderButtons();
};