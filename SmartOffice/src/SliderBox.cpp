#include "SliderBox.h"
#include <QskPushButton.h>
#include <QskTextLabel.h>

SliderBox::SliderBox(QskSlider* slider, QskPushButton* button, QskTextLabel* currentValue) : QskLinearBox(Qt::Horizontal)
{
    m_button = button;
    m_slider = slider;
    m_currentValue = currentValue;
    
    addItem(m_button);
    addItem(m_slider);
    addItem(m_currentValue);

    m_unit = currentValue->text();
    m_currentValue->setText("20" + m_unit);

    connect(slider, &QskBoundedValueInput::valueChanged, [this](qreal v)
    {
        m_currentValue->setText(QString::number(int(v))+ m_unit );
    });
}