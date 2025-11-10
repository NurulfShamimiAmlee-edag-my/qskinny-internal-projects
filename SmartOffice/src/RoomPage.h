#ifndef ROOMPAGE_H
#define ROOMPAGE_H

#include "RoomImageWithButtonsBox.h"
#include "SliderBox.h"
#include "MasterSwitchButton.h"

#include <QskBox.h>
#include <QskLinearBox.h>
#include <QskGraphicLabel.h>
#include <QskPushButton.h>
#include <qnamespace.h>


class RoomPage : public QskLinearBox
{
    private:
        QString m_roomPageName; //hold room name of tab button label
        QskLinearBox *m_verticalContainer = nullptr; //Hold controller and info box 
        QskLinearBox *m_controllerBox = nullptr;
        QskLinearBox *m_controllerSubBox1 = nullptr; //Place master switch button
        QskLinearBox *m_controllerSubBox2 = nullptr; //Place slider boxes
        SliderBox *m_sliderBox = nullptr;
        QskLinearBox *m_infoBox = nullptr;
        ImageAndButtonBoxFactory *m_imageAndButtons = nullptr;
        MasterSwitchButton* m_masterSwitch = nullptr;
        
    private:
        void setControllerBox(QskLinearBox* parent);
        void setInfoBox(QskLinearBox* parent);
    
    public:
        RoomPage(ImageAndButtonBoxFactory* imageAndButtonsBox, SliderBox* sliderBox);
        QString getRoomPageName();
};


#endif //ROOMPAGE_H