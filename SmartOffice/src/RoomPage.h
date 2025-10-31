#ifndef ROOMPAGE_H
#define ROOMPAGE_H

#include <QskBox.h>
#include <QskLinearBox.h>
#include <QskGraphicLabel.h>
#include <QskPushButton.h>
#include <qnamespace.h>


class RoomPage : public QskLinearBox
{
    private:
        QString m_roomName; //hold room name of tab button label
        QskLinearBox *m_verticalContainer = nullptr; //Hold controller and info box    
    
    public:
        RoomPage(QString roomName, QskBox* imageAndButtonsBox);
        void setRoomName(const QString& name);
        QString getRoomName();
};


class ControllerBox : public QskLinearBox
{
    public:
        ControllerBox();
};

class InfoBox : public QskLinearBox
{
    public:
        InfoBox();
};


#endif //ROOMPAGE_H