#include "RoomPage.h"
#include "TemperatureSlider.h"
#include "TemperatureButton.h"
#include "SliderBox.h"

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
    addItem(new SliderBox(new TemperatureSlider(), new TemperatureButton(), new QskTextLabel("°C")));

    //Light Intensity Controller
    auto* lightIntensityBox = new QskLinearBox(Qt::Vertical, this);
    auto* currentLightIntensityLabel = new QskTextLabel("Current Light Intensity: 20%", lightIntensityBox);
    auto* lightIntensitySlider = new  LightIntensitySlider();
    lightIntensityBox->addItem(lightIntensitySlider);
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

RoomPage::RoomPage(QString roomName, QskBox* imageAndButtonsBox) : QskLinearBox(Qt::Horizontal), m_roomName(roomName)
{
    addItem(imageAndButtonsBox);
    m_verticalContainer = new QskLinearBox(Qt::Vertical, this);
    m_verticalContainer->addItem(new ControllerBox());
    m_verticalContainer->addItem(new InfoBox());
}

void RoomPage::setRoomName(const QString& name)
{
    auto* nameRoom = new QskTextLabel(name, this);
    nameRoom->setFontRole({QskFontRole::Display, QskFontRole::High});
    nameRoom->setAlignment(Qt::AlignCenter); 
}

QString RoomPage::getRoomName()
{
    return m_roomName;
}

