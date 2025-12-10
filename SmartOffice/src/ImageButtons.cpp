#include "ImageButtons.h"
#include <QskAspect.h>
#include <QskPushButton.h>
#include <QskGraphic.h>
#include <QskGraphicIO.h>

QSK_SUBCONTROL(ImageButtons, Panel)
QSK_SUBCONTROL(ImageButtons, Icon)

ImageButtons::ImageButtons(QskBox* parent) : QskPushButton(parent)
{
    setSubcontrolProxy(QskPushButton::Panel, Panel);
    setSubcontrolProxy(QskPushButton::Icon, Icon);
    setCheckable(true);
}

LightImageButton::LightImageButton(QskBox* parent) : ImageButtons(parent)
{
    setIcon(QskGraphicIO::read(QString(":/assets/qvg/lamp.qvg")));

}

WifiImageButton::WifiImageButton(QskBox* parent) : ImageButtons(parent)
{
    setIcon(QskGraphicIO::read(QString(":/assets/qvg/wifi.qvg")));
}

AcImageButton::AcImageButton(QskBox* parent) : ImageButtons(parent)
{
    setIcon(QskGraphicIO::read(QString(":/assets/qvg/air-conditioner.qvg")));
}

SocketImageButton::SocketImageButton(QskBox* parent) : ImageButtons(parent)
{
    setIcon(QskGraphicIO::read(QString(":/assets/qvg/socket.qvg")));
}

