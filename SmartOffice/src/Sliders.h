#pragma once

#include <QskAspect.h>
#include <QskSlider.h>

class Sliders : public QskSlider
{
    public:
        QSK_SUBCONTROLS(Handle, Groove, Tick, Panel)

        Sliders();
};

class TemperatureSlider : public Sliders
{

    public:
        TemperatureSlider();

};

class LightIntensitySlider : public Sliders
{
    public:
        LightIntensitySlider();

};

class BlindSlider : public Sliders
{
    public:
        BlindSlider();

};