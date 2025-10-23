#ifndef ROOMPAGE_H
#define ROOMPAGE_H

#include <QskBox.h>
#include <QskLinearBox.h>
#include <qnamespace.h>


class RoomPage : public QskLinearBox
{
         
    public:
        RoomPage(QString roomName, QString imagePath);
};


class HorizontalDisplayBox : public QskLinearBox
{
    public:
        HorizontalDisplayBox(QString imagePath);

};

class ImageAndButtonsBox : public QskBox
{
    public:
        ImageAndButtonsBox(QString imagePath);

};

class InfoAndControllerBox : public QskLinearBox
{
    public:
        InfoAndControllerBox();
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