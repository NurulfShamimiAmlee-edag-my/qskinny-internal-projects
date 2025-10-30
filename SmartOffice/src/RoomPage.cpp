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

#include <iostream>


HorizontalDisplayBox::HorizontalDisplayBox(QString imagePath) : QskLinearBox()
{
    setOrientation(Qt::Horizontal);
    addItem(new ImageAndButtonsBox(imagePath));
    addItem(new InfoAndControllerBox());
}

ImageAndButtonsBox::ImageAndButtonsBox(QString imagePath) : QskBox()
{
    QImage image(imagePath);
    QskGraphic imageGraphic = QskGraphic::fromImage(image);
    m_roomImage = new QskGraphicLabel(imageGraphic, this);
    // The following sets the image in the box manually... it is better to use geometryChange()
    // roomGraphicLabel->setGeometry(0,100, sizeConstraint().width() , sizeConstraint().height());

    m_lightButton = new QskPushButton(this);
    m_lightButton->setIcon(QskGraphicIO::read(QString("assets/qvg/lamp.qvg")));
    // m_lightButton->setGeometry(100,100, 50,50);
    // m_lightButton->setZ(2);

    m_acButton = new QskPushButton(this);
    m_acButton->setIcon(QskGraphicIO::read(QString("assets/qvg/air-conditioner.qvg")));
    // m_acButton->setGeometry(200,100, 50,50);
    // m_acButton->setZ(1);

    m_wifiButton = new QskPushButton(this);
    m_wifiButton->setIcon(QskGraphicIO::read(QString("assets/qvg/wifi.qvg")));
    // m_wifiButton->setGeometry(200,300, 50,50);
    // m_wifiButton->setZ(1);

}

void ImageAndButtonsBox::geometryChange(const QRectF& newGeometry, const QRectF& oldGeometry)
{
    QskBox::geometryChange(newGeometry, oldGeometry);

    // QRectF c = contentsRect(); //contentsRect cannot be used in constructor as the box has yet to be created when the constructor was called.
    m_contentRect = contentsRect().marginsRemoved(QMarginsF(8,0,8,0));// if you want image to  have margins

    QRectF imageRect(m_contentRect.left(), m_contentRect.top(), m_contentRect.width(), m_contentRect.height());
    m_roomImage->setX(imageRect.x());
    m_roomImage->setY(imageRect.y());
    m_roomImage->setWidth(imageRect.width());
    m_roomImage->setHeight(imageRect.height());

    setButtonPosition(m_lightButton, 50, 50, 100, 100, 1);
    setButtonPosition(m_acButton, 50, 50, 200, 100, 1);
    setButtonPosition(m_wifiButton, 50, 50, 200, 300, 1);

    std::cout << "width: " << m_contentRect.x() << "," << "Height: " << m_contentRect.y() << std::endl;

}

void ImageAndButtonsBox::setButtonPosition(QskPushButton* buttons, qreal buttonWidth, qreal buttonHeight, qreal buttonX, qreal buttonY, qreal buttonZ)
{
    QRectF buttonRect(m_contentRect.left() + buttonX, m_contentRect.top() + buttonY, buttonWidth, buttonHeight); //How do I place a button in relation to the image size?

    buttons->setX(buttonRect.x());
    buttons->setY(buttonRect.y());
    buttons->setZ(buttonZ);//still a random number
    buttons->setWidth(buttonRect.width());
    buttons->setHeight(buttonRect.height());
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

RoomPage::RoomPage(QString roomName, QString imagePath) : QskLinearBox(Qt::Vertical), m_roomName(roomName)
{
    addItem(new HorizontalDisplayBox(imagePath));   
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

