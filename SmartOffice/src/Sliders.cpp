#include "Sliders.h"
#include <qnamespace.h>
#include <qsize.h>

QSK_SUBCONTROL(Sliders, Handle)
QSK_SUBCONTROL(Sliders, Groove)
QSK_SUBCONTROL(Sliders, Tick)
QSK_SUBCONTROL(Sliders, Panel)


Sliders::Sliders() : QskSlider()
{
    setSubcontrolProxy(QskSlider::Handle, Handle);
    setSubcontrolProxy(QskSlider::Groove, Groove);
    setSubcontrolProxy(QskSlider::Tick, Tick);
    setSubcontrolProxy(QskSlider::Panel, Panel);    

    setOrientation(Qt::Horizontal);
    setPreferredWidth(360);


}

TemperatureSlider::TemperatureSlider() : Sliders()
{ 
    setSnapping(true);
    setBoundaries(16,30);
    setValue(20);
    setStepSize(1);
}

LightIntensitySlider::LightIntensitySlider() : Sliders()
{
    setBoundaries(0,100);
    setValue(20);
    setStepSize(10);
}

BlindSlider::BlindSlider() : Sliders()
{
    setBoundaries(0,100);
    setSnapping(true);
    setValue(10);
    setStepSize(5);
}
