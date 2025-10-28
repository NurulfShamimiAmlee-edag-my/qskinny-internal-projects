#ifndef MAINPAGEGRAPHICLABEL_H
#define MAINPAGEGRAPHICLABEL_H

#include <QskGraphicLabel.h>

class MainPageGraphicLabel : public QskGraphicLabel
{
    public:
        QSK_SUBCONTROLS(Panel);

        MainPageGraphicLabel(QQuickItem* parent = nullptr);
        MainPageGraphicLabel(const QskGraphic& graphic, QQuickItem* parent = nullptr);

};

#endif //MAINPAGEGRAPHICLABEL_H