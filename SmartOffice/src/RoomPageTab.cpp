#include "RoomPageTab.h"
#include "RoomPage.h"

RoomPageTab::RoomPageTab() : QskTabView()
{
    auto* roomPageA = new RoomPage("Meeting Room A","assets/jpg/meeting-room.jpg");
    addTab(roomPageA->getRoomName(), roomPageA);
    addTab("Conference Room", new RoomPage("Meeting Room B","assets/jpg/conferenceroom.jpg"));
}

void RoomPageTab::addRoomPage(RoomPage* roomPage)
{
    m_roomPages.append(roomPage);
    for (auto room : m_roomPages)
    {
        addTab(room->getRoomName(), room);
    }
}

