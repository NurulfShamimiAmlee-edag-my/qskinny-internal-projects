#ifndef MAINPAGESWITCHBUTTON_H
#define MAINPAGESWITCHBUTTON_H

#include <QskSwitchButton.h>

class MainPageSwitchButton : public QskSwitchButton
{
    public:
        QSK_SUBCONTROLS(Groove, Handle, Icon);

        MainPageSwitchButton(QQuickItem* parent);
};


#endif //MAINPAGESWITCHBUTTON_H