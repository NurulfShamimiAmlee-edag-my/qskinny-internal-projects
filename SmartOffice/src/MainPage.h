#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QskAspect.h>
#include <QskLinearBox.h>
#include <QskStackBox.h>
#include <QskTextLabel.h>
#include <QskPushButton.h>
#include <QskGraphicLabel.h>
#include <qnamespace.h>

class MainPageTextLabel : public QskTextLabel
{
    public:
        QSK_SUBCONTROLS(Panel, Text);

        MainPageTextLabel(const QString& text, QQuickItem* parent = nullptr);
};

class MainPagePushButton : public QskPushButton
{
    public:
        QSK_SUBCONTROLS(Panel, Text);

        MainPagePushButton(const QString& text, QQuickItem* parent = nullptr);
};

class MainPageGraphicLabel : public QskGraphicLabel
{
    public:
        QSK_SUBCONTROLS(Panel);

        MainPageGraphicLabel(const QskGraphic& graphic, QQuickItem* parent = nullptr);

};

class MainPageBannerBox : public QskLinearBox
{
    public:
        QSK_SUBCONTROLS(Panel);

        MainPageBannerBox();
};

class BannerFactory
{
    public:
        virtual MainPageTextLabel* createTileTitle() = 0;
        virtual MainPagePushButton* createMasterSwitch() = 0;
        virtual MainPageGraphicLabel* createIconLabel() = 0;
};


class MainPage : public QskLinearBox
{
    public:
        MainPage();
        MainPageBannerBox* buildBanner(BannerFactory& factory);
};


#endif //MAINPAGE_H