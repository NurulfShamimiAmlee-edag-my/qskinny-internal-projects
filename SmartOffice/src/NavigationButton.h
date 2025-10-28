#ifndef NAVIGATIONBUTTON_H
#define NAVIGATIONBUTTON_H

#include <QskPushButton.h>

class NavigationButton : public QskPushButton
{
    public:
        QSK_SUBCONTROLS(Panel, Text);
        NavigationButton(QString text);
};

#endif //NAVIGATIONBUTTON_H