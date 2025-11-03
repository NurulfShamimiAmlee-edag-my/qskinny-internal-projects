#ifndef ROOMPAGE_H
#define ROOMPAGE_H

#include "RoomImageWithButtonsBox.h"
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
        QskLinearBox *m_infoBox = nullptr;
        ImageAndButtonBoxFactory *m_imageAndButtons = nullptr;
        
    private:
        void setControllerBox(QskLinearBox* parent);
        void setInfoBox(QskLinearBox* parent);
    
    public:
        RoomPage(ImageAndButtonBoxFactory* imageAndButtonsBox);
        QString getRoomPageName();
};


#endif //ROOMPAGE_H