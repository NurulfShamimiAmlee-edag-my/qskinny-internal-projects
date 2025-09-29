#include "RoomPage.h"
#include <QskLinearBox.h>
#include <QskTextLabel.h>

RoomPage::RoomPage() : QskLinearBox()
{
    auto* roomPagePlaceHolder = new QskTextLabel("Room Page Placeholder");
    this->addItem(roomPagePlaceHolder);
}