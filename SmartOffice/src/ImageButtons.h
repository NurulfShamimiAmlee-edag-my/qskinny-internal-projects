#pragma once

#include <QskAspect.h>
#include <QskBox.h>
#include <QskPushButton.h>

class ImageButtons : public QskPushButton
{
    public:
        QSK_SUBCONTROLS(Panel, Icon)

        ImageButtons(QskBox* parent);

};

class LightImageButton : public ImageButtons
{
    public:
        LightImageButton(QskBox* parent);

};

class WifiImageButton : public ImageButtons
{
    public:
        WifiImageButton(QskBox* parent);
};

class AcImageButton : public ImageButtons
{ 
    public:
        AcImageButton(QskBox* parent);
};

class SocketImageButton : public ImageButtons
{ 
    public:
        SocketImageButton(QskBox* parent);
};