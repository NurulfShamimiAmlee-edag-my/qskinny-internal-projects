#ifndef TOPBAMENUBUTTON_H
#define TOPBAMENUBUTTON_H

#include <QskPushButton.h>

class TopBarMenuButton : public QskPushButton
{
    public:
        QSK_SUBCONTROLS(Panel, Text);

        TopBarMenuButton();
};

#endif //TOPBAMENUBUTTON_H