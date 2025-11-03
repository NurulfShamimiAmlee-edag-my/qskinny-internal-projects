#pragma once

#include <QskBox.h>
#include <QskGraphicLabel.h>
#include <QskPushButton.h>

class ImageAndButtonBoxFactory : public QskBox
{
    
    
    public:
        void addImageToBox(QString imagePath, QskBox* parent);
        void addLightButtonToImage(QskPushButton* lightButton, QskBox* parent);
        void addWifiButtonToImage(QskPushButton* wifiButton, QskBox* parent);
        void addAcButtonToImage(QskPushButton* acButton);
        void addBlindButtonToImage(QskPushButton* blindButton);
        void addSocketButtonToImage(QskPushButton* socketButton);
        QString getRoomName();
    
    protected:
        QString m_roomName;


    protected:
        void setButtonPosition(QRectF contentRectangle, QskPushButton* buttons, qreal buttonWidth, qreal buttonHeight, qreal buttonX, qreal buttonY, qreal buttonZ);
        void setRoomName(const QString& rooName);

};


class MeetingRoomA : public ImageAndButtonBoxFactory 
{
    private:
        QskGraphicLabel* m_roomImage = nullptr;
        QskPushButton* m_lightButton = nullptr;
        QskPushButton* m_wifiButton = nullptr;
        QskPushButton* m_acButton = nullptr;
        QskPushButton* m_blindButton = nullptr;
        QskPushButton* m_socketButton = nullptr;
        QVector<QskPushButton*> m_lightButtonsList;
        QVector<QskPushButton*> m_wifiButtonsList;
        QVector<QskPushButton*> m_acButtonsList;
        QVector<QskPushButton*> m_blindButtonsList;
        QVector<QskPushButton*> m_socketButtonsList;
        QRectF m_contentRect;
    
    public:
        MeetingRoomA();
        MeetingRoomA(QString imagePath);

    protected:
        void geometryChange(const QRectF& newGeometry, const QRectF& oldGeometry) override;

};

class ConferenceRoom : public ImageAndButtonBoxFactory
{
    private:
        QskGraphicLabel* m_roomImage = nullptr;
        QskPushButton* m_lightButton = nullptr;
        QskPushButton* m_wifiButton = nullptr;
        QskPushButton* m_acButton = nullptr;
        QskPushButton* m_blindButton = nullptr;
        QskPushButton* m_socketButton = nullptr;
        QVector<QskPushButton*> m_lightButtonsList;
        QVector<QskPushButton*> m_wifiButtonsList;
        QVector<QskPushButton*> m_acButtonsList;
        QVector<QskPushButton*> m_blindButtonsList;
        QVector<QskPushButton*> m_socketButtonsList;
        QRectF m_contentRect;
    
    public:
        ConferenceRoom();
    
    protected:
        void geometryChange(const QRectF& newGeometry, const QRectF& oldGeometry) override;

};


