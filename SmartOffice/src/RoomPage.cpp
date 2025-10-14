#include "RoomPage.h"
#include <QskBoundedValueInput.h>
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
#include <QskSlider.h>
#include <qmargins.h>
#include <qnamespace.h>
#include <qpoint.h>
#include <qvectornd.h>

RoomPage::RoomPage() : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);
    setPadding(50);
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



    
    auto* verticalContainer = new QskLinearBox(Qt::Vertical, horizontalBoxContainer);

    //Controllers Box
    auto* sliderBox = new QskLinearBox(Qt::Vertical, verticalContainer);
    sliderBox->setPanel(true);
    sliderBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    sliderBox->setColor(QskLinearBox::Panel, QColor("#f5bd82"));

    auto* sliderBoxTitle = new QskTextLabel("Controllers", sliderBox);
    sliderBoxTitle->setFontRole({QskFontRole::Headline, QskFontRole::High});
    sliderBoxTitle->setAlignment(Qt::AlignCenter);

    //Temperature Controller
    auto* tempSliderBox = new QskLinearBox(Qt::Vertical, sliderBox);
    auto* currentTempLabel = new QskTextLabel("Current Temperature: 20", tempSliderBox);
    auto* tempSlider = new QskSlider(Qt::Horizontal,tempSliderBox);
    tempSlider->setPreferredSize(QSizeF(360,10));
    tempSlider->setBoundaries(16,30);
    tempSlider->setValue(20);
    tempSlider->setStepSize(1);
    
    connect(tempSlider, &QskBoundedValueInput::valueChanged, [currentTempLabel](qreal v)
    {
        currentTempLabel->setText("Current Temperature: " + QString::number(int(v)));
    });


    //Light Intensity Controller
    auto* lightIntensityBox = new QskLinearBox(Qt::Vertical, sliderBox);
    auto* currentLightIntensityLabel = new QskTextLabel("Current Light Intensity: 20%", lightIntensityBox);
    auto* lightIntensitySlider = new  QskSlider(Qt::Horizontal, lightIntensityBox);
    lightIntensitySlider->setPreferredSize(QSizeF(360, 10));
    lightIntensitySlider->setBoundaries(0, 100);
    lightIntensitySlider->setValue(20);
    lightIntensitySlider->setStepSize(10);

    connect(lightIntensitySlider, &QskBoundedValueInput::valueChanged, [currentLightIntensityLabel](qreal v)
    {
        currentLightIntensityLabel->setText("Current Light Intensity: " + QString::number(int(v))+"%");
    });

    //Blind Controller
    auto* blindBox = new QskLinearBox(Qt::Vertical, sliderBox);
    auto* blindLabel = new QskTextLabel("Current Blind Position: 20%", blindBox);
    auto* blindSlider = new  QskSlider(Qt::Horizontal, blindBox);
    blindSlider->setPreferredSize(QSizeF(360, 10));
    blindSlider->setBoundaries(0, 100);
    blindSlider->setValue(20);
    blindSlider->setStepSize(20);

    connect(blindSlider, &QskBoundedValueInput::valueChanged, [blindLabel](qreal v)
    {
        blindLabel->setText("Current Light Intensity: " + QString::number(int(v))+"%");
    });

    //Information Box
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