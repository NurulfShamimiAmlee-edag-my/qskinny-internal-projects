#include "RoomPage.h"
#include <QskGraphic.h>
#include <QskGraphicLabel.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskSizePolicy.h>
#include <QskTextLabel.h>
#include <QskFontRole.h>
#include <QskBoxShapeMetrics.h>
#include <qnamespace.h>

RoomPage::RoomPage() : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);
    // auto* testBox = new QskLinearBox(this);
    auto* roomName = new QskTextLabel("Meeting Room A", this);
    // roomName->setPanel(true);
    // roomName->setColor(QskTextLabel::Panel, QColor("#82d6f5"));
    roomName->setFontRole({QskFontRole::Display, QskFontRole::High});
    roomName->setAlignment(Qt::AlignCenter);  
    auto* horizontalBoxContainer = new QskLinearBox(Qt::Horizontal, this);
    auto* roomBackground = new QskGraphicLabel(createGraphic("assets/meeting-room.jpg"), horizontalBoxContainer);
    roomBackground->setFixedWidth(1080);
    roomBackground->setPanel(true);
    auto* testButton = new QskPushButton("test", roomBackground);
    testButton->setColor(QskPushButton::Panel, QColor("#82f5d4"));
    testButton->setX(500);
    testButton->setY(500);
    
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