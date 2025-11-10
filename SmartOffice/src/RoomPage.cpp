#include "RoomPage.h"
#include "MasterSwitchButton.h"
#include "RoomImageWithButtonsBox.h"
#include "Sliders.h"
#include "TemperatureButton.h"
#include "LightButton.h"
#include "SliderBox.h"
#include "UsageBox.h"

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
#include <QskSeparator.h>
#include <QVector>
#include <qmargins.h>
#include <qnamespace.h>
#include <qpoint.h>
#include <qvectornd.h>


RoomPage::RoomPage(ImageAndButtonBoxFactory* imageAndButtonsBox, SliderBox* sliderBox) : QskLinearBox(Qt::Horizontal), m_imageAndButtons(imageAndButtonsBox), m_sliderBox(sliderBox)
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
    m_controllerSubBox1 = new QskLinearBox(Qt::Horizontal, m_controllerBox);
    m_controllerSubBox2 = new QskLinearBox(Qt::Vertical, m_controllerBox);
    m_controllerBox->setPanel(true);
    m_controllerBox->setMargins(25);
    m_controllerBox->setPadding(25);
    m_controllerBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    m_controllerBox->setColor(QskLinearBox::Panel, QColor("#f5bd82"));

    //SliderBox section -> TODO: Change it so that whe don't directly set it like this
    m_masterSwitch = new MasterSwitchButton(m_controllerSubBox1);
    connect(m_masterSwitch, &MasterSwitchButton::toggled, this, [this](bool checked){
        if (checked)
        {
            m_controllerSubBox2->setDisabled(true);
            m_imageAndButtons->setDisabled(true);
        }
        else 
        {
            m_controllerSubBox2->setDisabled(false);
            m_imageAndButtons->setDisabled(false);
        }
    });
    m_controllerSubBox1->addItem(m_masterSwitch);
    m_controllerSubBox2->addItem(m_sliderBox->createTemperatureSliderBox());
    m_controllerSubBox2->addItem(m_sliderBox->createLightIntesitySliderBox());
    m_controllerSubBox2->addItem(m_sliderBox->createBlindPositionSliderBox());
}

void RoomPage::setInfoBox(QskLinearBox* parent)
{
    m_infoBox = new QskLinearBox(Qt::Vertical, parent);
    m_infoBox->setPanel(true);
    m_infoBox->setPadding(20);
    m_infoBox->setMargins(25,25,25,35);
    m_infoBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    m_infoBox->setColor(QskLinearBox::Panel, QColor("#f5d682"));    
    m_infoBox->addItem(new UsageBox());

}

