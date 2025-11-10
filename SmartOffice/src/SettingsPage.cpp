#include "SettingsPage.h"
#include <QGuiApplication>
#include <QMimeData>
#include <QDrag>
#include <QskBoxShapeMetrics.h>
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
#include "SingletonBannerDb.h"



SettingsPage::SettingsPage() : QskLinearBox()
{
    setOrientation(Qt::Vertical);

    auto *dropBoxAreaHorizontal = new QskLinearBox(Qt::Horizontal, this);
    auto dropBox = new DropBox(SingletonBannerDb::Slot1);
    auto dropBox2 = new DropBox(SingletonBannerDb::Slot2);
    auto dropBox3 = new DropBox(SingletonBannerDb::Slot3);
    
    m_listOfDropBox = {dropBox, dropBox2, dropBox3};
    for (auto dropArea : m_listOfDropBox)
    {
        dropBoxAreaHorizontal->addItem(dropArea);
    }

    //DragGraphicLabelArea
    auto* DragGraphicLabelsBox = new QskLinearBox(Qt::Vertical);
    DragGraphicLabelsBox->setPanel(true);
    DragGraphicLabelsBox->setColor(QskLinearBox::Panel, QColor("#f5d682"));
    DragGraphicLabelsBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    DragGraphicLabelsBox->setMargins(5);

    for (int row = 0 ; row < 2; row++)
    {
        auto* horizontalDragGraphicLabelsBox = new QskLinearBox(Qt::Horizontal);
        if(row == 0)
        {
            auto itemsRow1 = {"assets/qvg/air-conditioner.qvg", "assets/qvg/wifi.qvg", "assets/qvg/lamp.qvg"};

            for (auto item : itemsRow1)
            {
                auto* dragLabel = new DragGraphicLabel(item, m_listOfDropBox);
                horizontalDragGraphicLabelsBox->addItem(dragLabel);
            }

        }
        else
        {
            auto itemsRow2 = {"assets/qvg/window.qvg", "assets/qvg/thermometer-svgrepo-com.qvg", "assets/qvg/socket.qvg"};

            for (auto item : itemsRow2)
            {
                auto* dragLabel = new DragGraphicLabel(item, m_listOfDropBox);
                horizontalDragGraphicLabelsBox->addItem(dragLabel);
            }
            
        } 

        DragGraphicLabelsBox->addItem(horizontalDragGraphicLabelsBox);
    }

    this->addItem(DragGraphicLabelsBox);


}
