#pragma once

#include <QskBox.h>
#include <QskGraphicLabel.h>

class ImageAndButtonsBoxFactory : public QskBox
{
    private:
        QskGraphicLabel* m_roomImage = nullptr;
    
    public:
        virtual QskBox* createImageAndButtons(QskBox* parent) = 0;


};

