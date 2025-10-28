#ifndef TEMPERATUREBUTTON_H
#define TEMPERATUREBUTTON_H

#include <QskPushButton.h>

class TemperatureButton : public QskPushButton
{
    public:
        QSK_SUBCONTROLS(Panel, Icon)    

        TemperatureButton();

};


#endif //TEMPERATUREBUTTON_H