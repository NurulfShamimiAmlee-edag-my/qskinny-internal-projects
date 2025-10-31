#include "RoomPageTab.h"
#include "RoomPage.h"
#include "RoomImageWithButtonsBox.h"

RoomPageTab::RoomPageTab() : QskTabView()
{
    auto* roomPageA = new RoomPage("Meeting Room A", new MeetingRoomA());
    addTab(roomPageA->getRoomName(), roomPageA);
    addTab("Conference Room", new RoomPage("Conference Room",new ConferenceRoom()));
}

void RoomPageTab::addRoomPage(RoomPage* roomPage)
{
    m_roomPages.append(roomPage);
    for (auto room : m_roomPages)
    {
        addTab(room->getRoomName(), room);
    }
}

