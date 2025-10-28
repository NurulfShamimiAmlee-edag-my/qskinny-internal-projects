#ifndef TEMPERATURESLIDER_H
#define TEMPERATURESLIDER_H

#include <QskSlider.h>

class TemperatureSlider : public QskSlider
{

    public:
        QSK_SUBCONTROLS(Handle, Groove, Tick, Panel)

        TemperatureSlider();

};

class LightIntensitySlider : public QskSlider
{
    public:
        QSK_SUBCONTROLS(Handle, Groove, Tick, Panel)

        LightIntensitySlider();

};

#endif //TEMPERATURESLIDER_H