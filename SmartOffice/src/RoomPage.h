#ifndef ROOMPAGE_H
#define ROOMPAGE_H

#include <QskBox.h>
#include <QskLinearBox.h>
#include <QskGraphicLabel.h>
#include <qnamespace.h>


class RoomPage : public QskLinearBox
{
    private:
        QString m_roomName;     
    
    public:
        RoomPage(QString roomName, QString imagePath);
        void setRoomName(const QString& name);
        QString getRoomName();
};


class HorizontalDisplayBox : public QskLinearBox
{
    public:
        HorizontalDisplayBox(QString imagePath);

};

class ImageAndButtonsBox : public QskBox
{
    private:
        QskGraphicLabel* m_roomImage = nullptr;
    
    public:
        ImageAndButtonsBox(QString imagePath);

    protected:
        void geometryChange(const QRectF& newGeometry, const QRectF& oldGeometry) override;

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