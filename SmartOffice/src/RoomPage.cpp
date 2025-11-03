#include "RoomPage.h"
#include "RoomImageWithButtonsBox.h"
#include "TemperatureSlider.h"
#include "TemperatureButton.h"
#include "LightButton.h"
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


RoomPage::RoomPage(ImageAndButtonBoxFactory* imageAndButtonsBox) : QskLinearBox(Qt::Horizontal), m_imageAndButtons(imageAndButtonsBox)
{
    m_roomPageName = m_imageAndButtons->getRoomName();
    addItem(m_imageAndButtons);
    m_verticalContainer = new QskLinearBox(Qt::Vertical, this);
    setControllerBox(m_verticalContainer);
    setInfoBox(m_verticalContainer);
}

QString RoomPage::getRoomPageName()
{
    return m_roomPageName;
}

void RoomPage::setControllerBox(QskLinearBox* parent)
{
    m_controllerBox = new QskLinearBox(Qt::Vertical, parent);
    m_controllerBox->setPanel(true);
    m_controllerBox->setMargins(25);
    m_controllerBox->setPadding(25);
    m_controllerBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    m_controllerBox->setColor(QskLinearBox::Panel, QColor("#f5bd82"));

    // auto* sliderBoxTitle = new QskTextLabel("Controller", m_controllerBox);
    // sliderBoxTitle->setFontRole({QskFontRole::Headline, QskFontRole::High});

    //SliderBox section -> TODO: Change it so that whe don't directly set it like this
    m_controllerBox->addItem(new SliderBox(new TemperatureSlider(), new TemperatureButton(), new QskTextLabel("°C")));
    m_controllerBox->addItem(new SliderBox(new LightIntensitySlider(), new LightButton(), new QskTextLabel("%") ));
    m_controllerBox->addItem(new SliderBox(new LightIntensitySlider(), new LightButton(), new QskTextLabel("%")));

}

void RoomPage::setInfoBox(QskLinearBox* parent)
{
    m_infoBox = new QskLinearBox(Qt::Vertical, parent);
    m_infoBox->setPanel(true);
    m_infoBox->setPadding(25);
    m_infoBox->setMargins(25,25,25,35);
    m_infoBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    m_infoBox->setColor(QskLinearBox::Panel, QColor("#f5d682"));    
    // auto* informationBoxTitle = new QskTextLabel("Energy Consumption", m_infoBox);
    // informationBoxTitle->setAlignment(Qt::AlignCenter);
    // informationBoxTitle->setFontRole({QskFontRole::Headline, QskFontRole::High});
    auto* informationLight = new QskTextLabel("Lights Info ______", m_infoBox);
    auto* informationAC = new QskTextLabel("AC Info _______", m_infoBox);

}

