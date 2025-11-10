#include "SliderBox.h"
#include "BlindGraphicLabel.h"
#include "LightButton.h"
#include "Sliders.h"
#include "SliderButtons.h"
#include "TemperatureButton.h"
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskTextLabel.h>
#include <qnamespace.h>

SliderBox::SliderBox(QskSlider* slider, QskPushButton* button, QskTextLabel* currentValue) : QskLinearBox(Qt::Horizontal)
{
//     addItem(m_button);
//     addItem(m_slider);
//     addItem(m_currentValue);

//     m_unit = currentValue->text();
//     m_currentValue->setText("20" + m_unit);

//     connect(m_slider, &QskBoundedValueInput::valueChanged, [this](qreal v)
//     {
//         m_currentValue->setText(QString::number(int(v))+ m_unit );
//     });

//     connect(m_button, &QskPushButton::click,[this]()
//     {
//         m_slider->setValue(m_slider->minimum());
//     });
}

SliderBox::SliderBox() : QskLinearBox()
{
}

QskLinearBox* SliderBox::createTemperatureSliderBox()
{
    auto temperatureSliderBox = new QskLinearBox(Qt::Horizontal);
    m_button[0] = new TemperatureButton();
    m_slider[0] = new TemperatureSlider();
    m_currentValue[0] = new QskTextLabel();
    m_unit[0] = "°C";
    m_currentValue[0]->setText(QString::number(m_slider[0]->value()) + m_unit[0]);

    temperatureSliderBox->addItem(m_button[0]);
    temperatureSliderBox->addItem(m_slider[0]);
    temperatureSliderBox->addItem(m_currentValue[0]);

    connect(m_slider[0], &QskBoundedValueInput::valueChanged, [this](qreal v)
    {
        m_currentValue[0]->setText(QString::number(int(v))+ m_unit[0] );
    });

    connect(m_button[0], &QskPushButton::clicked,[this]()
    {
        if (m_button[0]->isChecked())
            m_slider[0]->setDisabled(true);
        else
            m_slider[0]->setDisabled(false);
    });

    return temperatureSliderBox;
}

QskLinearBox* SliderBox::createLightIntesitySliderBox()
{
    auto lightSliderBox = new QskLinearBox(Qt::Horizontal);
    m_button[1] = new LightButton();
    m_slider[1] = new LightIntensitySlider();
    m_currentValue[1] = new QskTextLabel();
    m_unit[1] = "lx";
    m_currentValue[1]->setText(QString::number(m_slider[1]->value()) + m_unit[1]);

    lightSliderBox->addItem(m_button[1]);
    lightSliderBox->addItem(m_slider[1]);
    lightSliderBox->addItem(m_currentValue[1]);

    connect(m_slider[1], &QskBoundedValueInput::valueChanged, [this](qreal v)
    {
        m_currentValue[1]->setText(QString::number(int(v))+ m_unit[1] );
    });

    connect(m_button[1], &QskPushButton::clicked,[this]()
    {
        if (m_button[1]->isChecked())
            m_slider[1]->setDisabled(true);
        else
            m_slider[1]->setDisabled(false);
    });

    return lightSliderBox;
}


QskLinearBox* SliderBox::createBlindPositionSliderBox()
{
    auto blindSliderBox = new QskLinearBox(Qt::Horizontal);
    setOrientation(Qt::Horizontal);
    m_graphicLabel = new BlindGraphicLabel();
    m_slider[2] = new BlindSlider();
    m_currentValue[2] = new QskTextLabel();
    m_unit[2] = "%";

    blindSliderBox->addItem(m_graphicLabel);
    blindSliderBox->addItem(m_slider[2]);
    blindSliderBox->addItem(m_currentValue[2]);

    m_currentValue[2]->setText(QString::number(m_slider[2]->value()) + m_unit[2]);

    connect(m_slider[2], &QskBoundedValueInput::valueChanged, [this](qreal v)
    {
        m_currentValue[2]->setText(QString::number(int(v))+ m_unit[2]);
    }); 

    return blindSliderBox;
}