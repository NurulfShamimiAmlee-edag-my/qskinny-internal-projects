#include "BottomSection.h"
#include "MainPage.h"
#include "SettingsPage.h"
#include "SummaryPage.h"
#include "RoomPageTab.h"

BottomSection::BottomSection() :  QskSwipeView()
{
    this->addItem(new MainPage());
    this->addItem(new RoomPageTab());
    this->addItem(new SummaryPage());
    this->addItem(new SettingsPage());
}