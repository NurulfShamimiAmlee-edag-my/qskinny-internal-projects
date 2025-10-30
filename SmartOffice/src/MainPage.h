#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QskAspect.h>
#include <QskLinearBox.h>
#include <QskStackBox.h>
#include <QskSwitchButton.h>
#include <QskTextLabel.h>
#include <QskPushButton.h>
#include <QskGraphicLabel.h>
#include <qnamespace.h>
#include <qquickitem.h>

#include "MainPageTextLabel.h"
#include "MainPagePushButton.h"
#include "MainPageGraphicLabel.h"
#include "MainPageSwitchButton.h"

class MainPageBannerBox : public QskLinearBox
{
    private:
        /*
            TODO: If master switch from room page is toggled, update the banner text label
            - consider that the master switch should control the related utility only.
        */
        MainPageTextLabel* m_bannerText = nullptr;
    
    public:
        QSK_SUBCONTROLS(Panel);

        MainPageBannerBox(QString labelText, QString path);
        MainPageBannerBox();
};



class MainPage : public QskLinearBox
{
    public:
        MainPage();
};


#endif //MAINPAGE_H