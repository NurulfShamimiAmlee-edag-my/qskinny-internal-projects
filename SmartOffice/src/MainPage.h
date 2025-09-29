#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QskLinearBox.h>
#include <QskStackBox.h>
#include <QskTextLabel.h>
#include <QskPushButton.h>
#include <QskGraphicLabel.h>

class BannerFactory
{
    public:
        virtual QskTextLabel* createTileTitle() = 0;
        virtual QskPushButton* createMasterSwitch() = 0;
        virtual QskGraphicLabel* createIconLabel() = 0;
};


class MainPage : public QskLinearBox
{
    //I need 3 utility boxes
    //in each utility box, i want an icon, a tile title and a switch button
    public:
        MainPage();
        QskLinearBox* buildBanner(BannerFactory& factory);
};

#endif //MAINPAGE_H