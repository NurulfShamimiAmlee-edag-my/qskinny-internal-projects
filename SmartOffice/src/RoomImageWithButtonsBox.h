#pragma once

#include <QskBox.h>
#include <QskGraphic.h>
#include <QskGraphicLabel.h>
#include <QskPushButton.h>

#include "ImageButtons.h"

class ImageAndButtonBoxFactory : public QskBox
{
    protected:
        QString m_roomName;
        QskGraphicLabel* m_roomImage = nullptr;
        ImageButtons* m_lightButton = nullptr;
        ImageButtons* m_wifiButton = nullptr;
        ImageButtons* m_acButton = nullptr;
        QskGraphicLabel* m_blindGraphicLabel = nullptr;
        ImageButtons* m_socketButton = nullptr;
        QVector<ImageButtons*> m_lightButtonsList;
        QVector<ImageButtons*> m_wifiButtonsList;
        QVector<ImageButtons*> m_acButtonsList;
        QVector<ImageButtons*> m_blindButtonsList;
        QVector<ImageButtons*> m_socketButtonsList;
        QRectF m_contentRect;
    
    public:
        void addImageToBox(QString imagePath, QskBox* parent);
        void addLightButtonToImage(ImageButtons* lightButton, QskBox* parent);
        void addWifiButtonToImage(ImageButtons* wifiButton, QskBox* parent);
        void addAcButtonToImage(ImageButtons* acButton);
        void addBlindButtonToImage(ImageButtons* blindButton);
        void addSocketButtonToImage(ImageButtons* socketButton);
        QString getRoomName();
        ImageButtons* getAcButton();
        ImageButtons* getLightButton();

    protected:
        void setButtonPosition(QRectF contentRectangle, ImageButtons* buttons, qreal buttonWidth, qreal buttonHeight, qreal buttonX, qreal buttonY, qreal buttonZ);
        void setRoomName(const QString& rooName);


};


class MeetingRoomA : public ImageAndButtonBoxFactory 
{
    
    public:
        MeetingRoomA();
        MeetingRoomA(QString imagePath);

    protected:
        void geometryChange(const QRectF& newGeometry, const QRectF& oldGeometry) override;

};

class ConferenceRoom : public ImageAndButtonBoxFactory
{
    
    public:
        ConferenceRoom();
    
    protected:
        void geometryChange(const QRectF& newGeometry, const QRectF& oldGeometry) override;

};


