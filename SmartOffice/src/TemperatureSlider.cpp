#include "TemperatureSlider.h"
#include <qnamespace.h>
#include <qsize.h>

QSK_SUBCONTROL(TemperatureSlider, Handle)
QSK_SUBCONTROL(TemperatureSlider, Groove)
QSK_SUBCONTROL(TemperatureSlider, Tick)
QSK_SUBCONTROL(TemperatureSlider, Panel)

QSK_SUBCONTROL(LightIntensitySlider, Handle)
QSK_SUBCONTROL(LightIntensitySlider, Groove)
QSK_SUBCONTROL(LightIntensitySlider, Tick)
QSK_SUBCONTROL(LightIntensitySlider, Panel)

TemperatureSlider::TemperatureSlider() : QskSlider()
{
    setSubcontrolProxy(QskSlider::Handle, Handle);
    setSubcontrolProxy(QskSlider::Groove, Groove);
    setSubcontrolProxy(QskSlider::Tick, Tick);
    setSubcontrolProxy(QskSlider::Panel, Panel);    

    setOrientation(Qt::Horizontal);
    setPreferredWidth(360);
    setSnapping(true);
    setBoundaries(16,30);
    setValue(20);
    setStepSize(1);
}

LightIntensitySlider::LightIntensitySlider() : QskSlider()
{
    setSubcontrolProxy(QskSlider::Handle, Handle);
    setSubcontrolProxy(QskSlider::Groove, Groove);
    setSubcontrolProxy(QskSlider::Tick, Tick);
    setSubcontrolProxy(QskSlider::Panel, Panel); 
    
    setOrientation(Qt::Horizontal);
    // setPreferredSize(QSizeF(360,10));
    setBoundaries(0,100);
    setValue(20);
    setStepSize(10);
}
