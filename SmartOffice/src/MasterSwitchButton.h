#pragma once

#include <QskAspect.h>
#include <QskSwitchButton.h>

class MasterSwitchButton : public QskSwitchButton
{
    public:
        QSK_SUBCONTROLS(Groove, Handle, Icon);

        MasterSwitchButton(QQuickItem* parent);
};