#include "BottomSection.h"
#include "MainPage.h"
#include "RoomPage.h"
#include "SettingsPage.h"
#include "SummaryPage.h"

BottomSection::BottomSection() :  QskStackBox()
{
    this->addItem(new MainPage());
    this->addItem(new RoomPage());
    this->addItem(new SummaryPage());
    this->addItem(new SettingsPage());
}