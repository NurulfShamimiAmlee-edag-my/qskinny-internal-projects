#include "SettingsPage.h"
#include <QGuiApplication>
#include <QMimeData>
#include <QDrag>
#include <QskEvent.h>
#include <QskGraphicLabel.h>
#include <QskLinearBox.h>
#include <QskTextLabel.h>
#include <QskBox.h>
#include <QskGraphic.h>
#include <QskGraphicIO.h>
#include <QTimer>
#include <QStyleHints>
#include <qdrag.h>
#include <qevent.h>
#include <qguiapplication.h>
#include <qicon.h>
#include <qmimedata.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpoint.h>
#include <qstringliteral.h>
#include <iostream>

#include "DragGraphicLabel.h"
#include "DropBox.h"


SettingsPage::SettingsPage() : QskLinearBox()
{
    setOrientation(Qt::Vertical);

    auto *dropBoxAreaHorizontal = new QskLinearBox(Qt::Horizontal, this);
    auto dropBox = new DropBox();
    auto dropBox2 = new DropBox();
    auto dropBox3 = new DropBox();
    dropBoxAreaHorizontal->addItem(dropBox);
    dropBoxAreaHorizontal->addItem(dropBox2);
    dropBoxAreaHorizontal->addItem(dropBox3);
    
    auto dropArea = {dropBox, dropBox2, dropBox3};

    //DragGraphicLabelArea
    auto* DragGraphicLabelsBox = new QskLinearBox(Qt::Vertical);
    DragGraphicLabelsBox->setPanel(true);
    DragGraphicLabelsBox->setColor(QskLinearBox::Panel, QColor("#f5d682"));
    // DragGraphicLabelsBox->setMargins(25);

    for (int row = 0 ; row < 2; row++)
    {
        auto* horizontalDragGraphicLabelsBox = new QskLinearBox(Qt::Horizontal);
        if(row == 0)
        {
            auto* acDragGraphicLabel = new DragGraphicLabel("assets/qvg/air-conditioner.qvg", dropArea);
            auto* wifiDragGraphicLabel = new DragGraphicLabel("assets/qvg/wifi.qvg", dropArea);
            auto* lightDragGraphicLabel =  new DragGraphicLabel("assets/qvg/lamp.qvg", dropArea);

            horizontalDragGraphicLabelsBox->addItem(acDragGraphicLabel);
            horizontalDragGraphicLabelsBox->addItem(wifiDragGraphicLabel);
            horizontalDragGraphicLabelsBox->addItem(lightDragGraphicLabel);
        }
        else
        {
            auto* blindDragGraphicLabel = new DragGraphicLabel("assets/qvg/window.qvg", dropArea);
            auto* temperatureDragGraphicLabel = new DragGraphicLabel("assets/qvg/thermometer-svgrepo-com.qvg", dropArea);
            auto* plugPointDragGraphicLabel =  new DragGraphicLabel("assets/qvg/socket.qvg", dropArea);

            horizontalDragGraphicLabelsBox->addItem(blindDragGraphicLabel);
            horizontalDragGraphicLabelsBox->addItem(temperatureDragGraphicLabel);
            horizontalDragGraphicLabelsBox->addItem(plugPointDragGraphicLabel);
        }

        DragGraphicLabelsBox->addItem(horizontalDragGraphicLabelsBox);
    }
    // this->addItem(new DragGraphicLabel("Test drag label", dropBox));
    this->addItem(DragGraphicLabelsBox);

}
