#include "RoomPage.h"
#include <QskGraphic.h>
#include <QskGraphicLabel.h>
#include <QskGridBox.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskSizePolicy.h>
#include <QskSkinnable.h>
#include <QskStackBox.h>
#include <QskTextLabel.h>
#include <QskFontRole.h>
#include <QskBoxShapeMetrics.h>
#include <qmargins.h>
#include <qnamespace.h>
#include <qpoint.h>
#include <qvectornd.h>

RoomPage::RoomPage() : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);
    // auto* testBox = new QskLinearBox(this);
    auto* roomName = new QskTextLabel("Meeting Room A", this);
    roomName->setFontRole({QskFontRole::Display, QskFontRole::High});
    roomName->setAlignment(Qt::AlignCenter);  

    auto* horizontalBoxContainer = new QskLinearBox(Qt::Horizontal, this);



    /* Image and Buttons Placement */
    auto* roomImageBox = new QskBox();
    auto roomRect = roomImageBox->contentsRect();
    horizontalBoxContainer->addItem(roomImageBox);

    auto* roomBackgroundBox = new QskGraphicLabel(createGraphic("assets/jpg/meeting-room.jpg"),roomImageBox);
    // auto imageHint = roomBackgroundBox->sizeConstraint();
    // qreal y = roomRect.y() + 0.6 * roomRect.height() - 0.5 * imageHint.height();
    // qreal x = roomRect.center().x() - 0.5 * imageHint.width();
    QRectF imageRect(0,0,960,960);
    roomBackgroundBox->setGeometry(0, -100,960,1080);
    // std::cout << y << x << std::endl;
    // std::cout << imageHint.height() << imageHint.width() << std::endl;

    auto* testButton = new QskPushButton("test", roomImageBox);
    testButton->setColor(QskPushButton::Panel, QColor("#82f5d4"));
    testButton->setGeometry(100,100, 100,100);
    testButton->setZ(2);
    // std::cout << testButton->x() << testButton->y() << std::endl;

    auto* testButton2 = new QskPushButton("test2", roomImageBox);
    testButton2->setColor(QskPushButton::Panel, QColor("#82f5d4"));
    testButton2->setGeometry(150,100, 100,100);
    testButton2->setZ(1);

    //TODO: get test button to appear on the image without sacrificing the buttons properties.
    // roomImageBox->addItem(roomBackgroundBox);
    // roomImageBox->addItem(testButton);


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