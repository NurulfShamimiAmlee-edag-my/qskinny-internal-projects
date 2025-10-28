#ifndef TOPBARGRAPHICLABEL_H
#define TOPBARGRAPHICLABEL_H

#include <QskGraphicLabel.h>

class TopBarGraphicLabel : public QskGraphicLabel
{
    public:
        QSK_SUBCONTROLS(Panel, Graphic);

        TopBarGraphicLabel();
};


#endif //TOPBARGRAPHICLABEL_H