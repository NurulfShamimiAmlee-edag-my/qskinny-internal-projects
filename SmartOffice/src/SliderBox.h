#pragma once

#include <QskGraphicLabel.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskSlider.h>
#include <QskTextLabel.h>


class SliderBox : public QskLinearBox
{
    private:
        QskGraphicLabel* m_graphicLabel = nullptr;
        QskSlider* m_slider[3];
        QskPushButton* m_button[2];
        QskTextLabel* m_currentValue[3];
        QString m_unit[3];
        
    
    public:
        SliderBox(QskSlider* slider, QskPushButton* button, QskTextLabel* currentValue);
        SliderBox();
        QskSlider* getSlider();
        QskPushButton* getButton();
        QskTextLabel* getCurrentValueLabel();
        QskLinearBox* createTemperatureSliderBox();
        QskLinearBox* createLightIntesitySliderBox();
        QskLinearBox* createBlindPositionSliderBox();
};


