#include "RoomPageTab.h"
#include "RoomPage.h"
#include "RoomImageWithButtonsBox.h"

RoomPageTab::RoomPageTab() : QskTabView()
{
    auto* roomPageA = new RoomPage(new MeetingRoomA());
    auto* conferenceRoom = new RoomPage(new ConferenceRoom());

    for(auto roomPage : {roomPageA, conferenceRoom})
    {
        addTab(roomPage->getRoomPageName(), roomPage);
    }
}

void RoomPageTab::addRoomPage(RoomPage* roomPage)
{
    m_roomPages.append(roomPage);
    for (auto room : m_roomPages)
    {
        addTab(room->getRoomPageName(), room);
    }
}

