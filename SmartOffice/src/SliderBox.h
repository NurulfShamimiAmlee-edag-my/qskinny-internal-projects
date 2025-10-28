#ifndef SLIDERBOX_H
#define SLIDERBOX_H

#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskSlider.h>
#include <QskTextLabel.h>


class SliderBox : public QskLinearBox
{
    private:
        QskSlider* m_slider = nullptr;
        QskPushButton* m_button = nullptr;
        QskTextLabel* m_currentValue = nullptr;
        QString m_unit;
    
    public:
        SliderBox(QskSlider* slider = nullptr, QskPushButton* button = nullptr, QskTextLabel* currentValue = nullptr);
        QskSlider* getSlider();
        QskPushButton* getButton();
        QskTextLabel* getCurrentValueLabel();

};


#endif //SLIDERBOX_H