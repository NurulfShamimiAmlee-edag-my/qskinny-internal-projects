#ifndef MAINPAGETEXTLABEL_H
#define MAINPAGETEXTLABEL_H

#include <QskTextLabel.h>

class MainPageTextLabel : public QskTextLabel
{
    public:
        QSK_SUBCONTROLS(Panel, Text);

        MainPageTextLabel(const QString& text, QQuickItem* parent = nullptr);
};

#endif //MAINPAGETEXTLABEL_H