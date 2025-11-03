#include "RoomImageWithButtonsBox.h"
#include <QskGraphic.h>
#include <QskGraphicIO.h>

void ImageAndButtonBoxFactory::setButtonPosition(QRectF contentRectangle,QskPushButton* buttons, qreal buttonWidth, qreal buttonHeight, qreal buttonX, qreal buttonY, qreal buttonZ)
{
    QRectF buttonRect(contentRectangle.left() + buttonX, contentRectangle.top() + buttonY, buttonWidth, buttonHeight); //How do I place a button in relation to the image size?

    buttons->setX(buttonRect.x());
    buttons->setY(buttonRect.y());
    buttons->setZ(buttonZ);//still a random number
    buttons->setWidth(buttonRect.width());
    buttons->setHeight(buttonRect.height());

}

QString ImageAndButtonBoxFactory::getRoomName()
{
    return m_roomName;
}

void ImageAndButtonBoxFactory::setRoomName(const QString& roomName)
{
    m_roomName = roomName;
}

MeetingRoomA::MeetingRoomA(QString imagePath) : ImageAndButtonBoxFactory()
{
    QImage image(imagePath);
    QskGraphic imageGraphic = QskGraphic::fromImage(image); //Image size preferred: 1440x1080
    m_roomImage = new QskGraphicLabel(imageGraphic, this);
    setRoomName("Meeting Room A");
}

MeetingRoomA::MeetingRoomA() : ImageAndButtonBoxFactory()
{
    setRoomName("Meeting Room A");
    QImage image("assets/jpg/meeting-room.jpg");
    QskGraphic imageGraphic = QskGraphic::fromImage(image);
    m_roomImage = new QskGraphicLabel(imageGraphic, this);
    // The following sets the image in the box manually... it is better to use geometryChange()
    // roomGraphicLabel->setGeometry(0,100, sizeConstraint().width() , sizeConstraint().height());

    m_lightButton = new QskPushButton(this);
    m_lightButton->setIcon(QskGraphicIO::read(QString("assets/qvg/lamp.qvg")));


    m_acButton = new QskPushButton(this);
    m_acButton->setIcon(QskGraphicIO::read(QString("assets/qvg/air-conditioner.qvg")));


    m_wifiButton = new QskPushButton(this);
    m_wifiButton->setIcon(QskGraphicIO::read(QString("assets/qvg/wifi.qvg")));

}

void MeetingRoomA::geometryChange(const QRectF& newGeometry, const QRectF& oldGeometry)
{
    QskBox::geometryChange(newGeometry, oldGeometry);

    // QRectF c = contentsRect(); //contentsRect cannot be used in constructor as the box has yet to be created when the constructor was called.
    m_contentRect = contentsRect().marginsRemoved(QMarginsF(8,0,8,0));// if you want image to  have margins

    QRectF imageRect(m_contentRect.left(), m_contentRect.top(), m_contentRect.width(), m_contentRect.height());
    m_roomImage->setX(imageRect.x());
    m_roomImage->setY(imageRect.y());
    m_roomImage->setWidth(imageRect.width());
    m_roomImage->setHeight(imageRect.height());

    setButtonPosition(m_contentRect, m_lightButton, 50, 50, 100, 100, 1);
    setButtonPosition(m_contentRect,m_acButton, 50, 50, 200, 100, 1);
    setButtonPosition(m_contentRect, m_wifiButton, 50, 50, 200, 300, 1);

    // qDebug() << m_contentRect ;

}

ConferenceRoom::ConferenceRoom() : ImageAndButtonBoxFactory()
{
    setRoomName("Conference Room B");
    QImage image("assets/jpg/conferenceroomb.jpg");
    QskGraphic imageGraphic = QskGraphic::fromImage(image);
    m_roomImage = new QskGraphicLabel(imageGraphic, this);

     m_lightButton = new QskPushButton(this);
    m_lightButton->setIcon(QskGraphicIO::read(QString("assets/qvg/lamp.qvg")));


    m_acButton = new QskPushButton(this);
    m_acButton->setIcon(QskGraphicIO::read(QString("assets/qvg/air-conditioner.qvg")));


    m_wifiButton = new QskPushButton(this);
    m_wifiButton->setIcon(QskGraphicIO::read(QString("assets/qvg/wifi.qvg")));

}

void ConferenceRoom::geometryChange(const QRectF& newGeometry, const QRectF& oldGeometry)
{
    QskBox::geometryChange(newGeometry, oldGeometry);

    // QRectF c = contentsRect(); //contentsRect cannot be used in constructor as the box has yet to be created when the constructor was called.
    m_contentRect = contentsRect().marginsRemoved(QMarginsF(8,0,8,0));// if you want image to  have margins

    QRectF imageRect(m_contentRect.left(), m_contentRect.top(), m_contentRect.width(), m_contentRect.height());
    m_roomImage->setX(imageRect.x());
    m_roomImage->setY(imageRect.y());
    m_roomImage->setWidth(imageRect.width());
    m_roomImage->setHeight(imageRect.height());

    setButtonPosition(m_contentRect, m_lightButton, 50, 50, 100, 100, 1);
    setButtonPosition(m_contentRect, m_acButton, 50, 50, 200, 200, 1);
    setButtonPosition(m_contentRect, m_wifiButton, 50, 50, 170, 100, 1);

} 
