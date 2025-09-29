#include "SettingsPage.h"
#include <QskTextLabel.h>

SettingsPage::SettingsPage() : QskLinearBox()
{
    auto* settingPagePlaceHolder = new QskTextLabel("Settings Page placeholder");
    this->addItem(settingPagePlaceHolder) ;
}