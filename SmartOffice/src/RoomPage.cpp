#include "RoomPage.h"

#include <QskBoundedValueInput.h>
#include <QskBox.h>
#include <QskGraphic.h>
#include <QskGraphicLabel.h>
#include <QskGridBox.h>
#include <QskLinearBox.h>
#include <QskNamespace.h>
#include <QskPushButton.h>
#include <QskSizePolicy.h>
#include <QskSkinnable.h>
#include <QskStackBox.h>
#include <QskTextLabel.h>
#include <QskFontRole.h>
#include <QskBoxShapeMetrics.h>
#include <QskSwitchButton.h>
#include <QskSlider.h>
#include <QskGraphicIO.h>
#include <QskTickmarks.h>
#include <QVector>
#include <qmargins.h>
#include <qnamespace.h>
#include <qpoint.h>
#include <qvectornd.h>


HorizontalDisplayBox::HorizontalDisplayBox(QString imagePath) : QskLinearBox()
{
    setOrientation(Qt::Horizontal);
    addItem(new ImageAndButtonsBox(imagePath));
    addItem(new InfoAndControllerBox());
}

ImageAndButtonsBox::ImageAndButtonsBox(QString imagePath) : QskBox()
{
    // contentsRect();
    QImage image(imagePath);
    QskGraphic imageGraphic = QskGraphic::fromImage(image);
    auto* roomGraphicLabel = new QskGraphicLabel(imageGraphic, this);
    roomGraphicLabel->setGeometry(0,-100, 960,1080);

    auto* lampButton = new QskPushButton(this);
    lampButton->setIcon(QskGraphicIO::read(QString("assets/qvg/lamp.qvg")));
    lampButton->setGeometry(100,100, 100,100);
    lampButton->setZ(2);

    auto* wifiButton = new QskPushButton(this);
    wifiButton->setIcon(QskGraphicIO::read(QString("assets/qvg/air-conditioner.qvg")));
    wifiButton->setGeometry(350,100, 100,100);
    wifiButton->setZ(1);


}

InfoAndControllerBox::InfoAndControllerBox() : QskLinearBox()
{
    setOrientation(Qt::Vertical);
    addItem(new ControllerBox());
    addItem(new InfoBox());
}

ControllerBox::ControllerBox() : QskLinearBox()
{
    setOrientation(Qt::Vertical);
    setPanel(true);
    setMargins(25);
    setPadding(25);
    setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    setColor(QskLinearBox::Panel, QColor("#f5bd82"));

    auto* sliderBoxTitle = new QskTextLabel("Controllers", this);
    sliderBoxTitle->setFontRole({QskFontRole::Headline, QskFontRole::High});
    sliderBoxTitle->setAlignment(Qt::AlignCenter);

    //Temperature Controller
    //TODO: Implement button on the left of the slider, right-label of current value
    //Optional TODO: Create visible ticks for the sliders.
    auto* tempSliderBox = new QskLinearBox(Qt::Horizontal, this);
    auto* tempButton = new QskPushButton(tempSliderBox);
    tempButton->setIcon(QskGraphicIO::read(QString("assets/qvg/air-conditioner.qvg")));
    tempButton->setFixedSize(50,50);
    tempButton->setBoxShapeHint(QskPushButton::Panel, QskBoxShapeMetrics(50));
    auto* tempSlider = new QskSlider(Qt::Horizontal,tempSliderBox);
    auto* currentTempLabel = new QskTextLabel("20 °C", tempSliderBox);
    tempSlider->setSnapping(true);
    tempSlider->setBoundaries(16,30);
    tempSlider->setValue(20);
    tempSlider->setStepSize(1);
    
    connect(tempSlider, &QskBoundedValueInput::valueChanged, [currentTempLabel](qreal v)
    {
        currentTempLabel->setText(QString::number(int(v))+" °C");
    });


    //Light Intensity Controller
    auto* lightIntensityBox = new QskLinearBox(Qt::Vertical, this);
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
    auto* blindBox = new QskLinearBox(Qt::Vertical, this);
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
}

InfoBox::InfoBox() : QskLinearBox()
{
    setOrientation(Qt::Vertical);
    // auto* informationBox = new QskLinearBox(Qt::Vertical, this);
    setPanel(true);
    setPadding(25);
    setMargins(25);
    setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    setColor(QskLinearBox::Panel, QColor("#f5d682"));    
    auto* informationBoxTitle = new QskTextLabel("Energy Consumption", this);
    informationBoxTitle->setAlignment(Qt::AlignCenter);
    informationBoxTitle->setFontRole({QskFontRole::Headline, QskFontRole::High});
    auto* informationLight = new QskTextLabel("Lights Info ______", this);
    auto* informationAC = new QskTextLabel("AC Info _______", this);
}

RoomPage::RoomPage(QString roomName, QString imagePath) : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);

    auto* nameRoom = new QskTextLabel(roomName, this);
    nameRoom->setFontRole({QskFontRole::Display, QskFontRole::High});
    nameRoom->setAlignment(Qt::AlignCenter); 

    addItem(new HorizontalDisplayBox(imagePath));
    

}

