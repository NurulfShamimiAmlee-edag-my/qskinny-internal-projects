#include "RoomPage.h"
#include <QskGraphic.h>
#include <QskGraphicLabel.h>
#include <QskGridBox.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskSizePolicy.h>
#include <QskStackBox.h>
#include <QskTextLabel.h>
#include <QskFontRole.h>
#include <QskBoxShapeMetrics.h>
#include <qmargins.h>
#include <iostream>
#include <qnamespace.h>
#include <qpoint.h>

RoomPage::RoomPage() : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);
    // auto* testBox = new QskLinearBox(this);
    auto* roomName = new QskTextLabel("Meeting Room A", this);
    roomName->setFontRole({QskFontRole::Display, QskFontRole::High});
    roomName->setAlignment(Qt::AlignCenter);  

    auto* horizontalBoxContainer = new QskLinearBox(Qt::Horizontal, this);


    /* Image and Buttons Placement */
    auto* roomImageBox = new QskStackBox();
    horizontalBoxContainer->addItem(roomImageBox);

    auto* roomBackgroundBox = new QskGraphicLabel(createGraphic("assets/meeting-room.jpg"));
    roomBackgroundBox->setFixedWidth(1080);

    // auto* buttonBox = new QskBox();
    // buttonBox->setSizePolicy(QskSizePolicy::Expanding, QskSizePolicy::Expanding);
    // buttonBox->setParentItem(roomImageBox);
    auto* testButton = new QskPushButton("test");
    testButton->setSizePolicy(QskSizePolicy::Fixed, QskSizePolicy::Fixed);
    testButton->setMargins(QMarginsF(0,-20,0,0)); //why is this not working?
    testButton->setColor(QskPushButton::Panel, QColor("#82f5d4"));
    testButton->setPosition(QPointF(500,500));

    //TODO: get test button to appear on the image without sacrificing the buttons properties.
    roomImageBox->addItem(roomBackgroundBox);
    roomImageBox->addItem(testButton);


    /* Image and Buttons Placement */

    /* Debug */
    // std::cout<< roomImageBox->itemCount() << std::endl;
    /* Debug */
    
    
    auto* verticalContainer = new QskLinearBox(Qt::Vertical, horizontalBoxContainer);
    auto* sliderBox = new QskLinearBox(Qt::Vertical, verticalContainer);
    sliderBox->setPanel(true);
    sliderBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    sliderBox->setColor(QskLinearBox::Panel, QColor("#f5bd82"));
    auto* sliderPlaceHolder = new QskTextLabel("Slider Place Holder", sliderBox);
    auto* informationBox = new QskLinearBox(Qt::Vertical, verticalContainer);
    informationBox->setPanel(true);
    informationBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    informationBox->setColor(QskLinearBox::Panel, QColor("#f5d682"));    
    auto* informationLight = new QskTextLabel("Lights Info ______", informationBox);
    auto* informationAC = new QskTextLabel("AC Info _______", informationBox);
}

QskGraphic RoomPage::createGraphic(QString text)
{
    QImage image(text);
    QskGraphic imageGraphic = QskGraphic::fromImage(image);
    return imageGraphic;
}