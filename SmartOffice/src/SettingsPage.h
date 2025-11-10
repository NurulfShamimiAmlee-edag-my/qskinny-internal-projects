#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include "MainPage.h"
#include "DropBox.h"

#include <QskGraphicLabel.h>
#include <QskLinearBox.h>
#include <QskTextLabel.h>
#include <qcontainerfwd.h>
#include <qevent.h>
#include <qtmetamacros.h>


class SettingsPage : public QskLinearBox
{
    private:
        QskPushButton* m_confirmButton = nullptr;
        QVector<DropBox*>m_listOfDropBox;
        QVector<MainPageBannerBox*> m_mainPageBannerBox;
    
    public:
        SettingsPage();
        void notify();
};

#endif //SETTINGSPAGE_Hl