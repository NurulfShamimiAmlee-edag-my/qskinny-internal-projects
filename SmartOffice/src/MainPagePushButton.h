#ifndef MAINPAGEPUSHBUTTON_H
#define MAINPAGEPUSHBUTTON_H

#include <QskPushButton.h>

class MainPagePushButton : public QskPushButton
{
    public:
        QSK_SUBCONTROLS(Panel, Text);

        MainPagePushButton(const QString& text, QQuickItem* parent = nullptr);
};

#endif //MAINPAGEPUSHBUTTON_H