#include "SingletonBannerDb.h"
#include <QskGraphic.h>
#include <QskGraphicIO.h>
#include <qdebug.h>
#include <qlogging.h>


SingletonBannerDb& SingletonBannerDb::instance()
{
    static SingletonBannerDb dbInstance(nullptr);

    dbInstance.m_bannerBoxGraphic[SingletonBannerDb::Slot1] = QskGraphicIO::read(QString("assets/qvg/air-conditioner.qvg"));
    dbInstance.m_bannerBoxGraphic[SingletonBannerDb::Slot2] = QskGraphicIO::read(QString("assets/qvg/lamp.qvg"));
    dbInstance.m_bannerBoxGraphic[SingletonBannerDb::Slot3] = QskGraphicIO::read(QString("assets/qvg/window.qvg"));

    return dbInstance;
}

SingletonBannerDb::SingletonBannerDb(QObject* parent)
    : QObject(parent)
{

}

void SingletonBannerDb::changeBannerGraphic(const BannerSlot& slot, const QskGraphic& bannerIcon)
{
    qDebug() << "[DBG] changeBannerGraphic called. this=" << static_cast<const void*>(this)
             << " slot=" << static_cast<int>(slot);
    m_bannerBoxGraphic[slot] = bannerIcon;
    qDebug() << "[DBG]  stored. map size =" << m_bannerBoxGraphic.size()
             << " map_addr=" << static_cast<const void*>(&m_bannerBoxGraphic);

    emit bannerChanged(slot, bannerIcon);
}

const QskGraphic& SingletonBannerDb::readBannerGraphic(const BannerSlot& slot) const
{
    static const QskGraphic defaultGraphic;
    qDebug() << "[DBG] readBannerGraphic called. this=" << static_cast<const void*>(this)
             << " slot=" << static_cast<int>(slot)
             << " map_addr=" << static_cast<const void*>(&m_bannerBoxGraphic)
             << " map.size()=" << m_bannerBoxGraphic.size();

    // direct test using contains()
    if (m_bannerBoxGraphic.contains(slot))
    {
        qDebug() << "[DBG] contains(slot) == true";
    } else {
        qDebug() << "[DBG] contains(slot) == false";
    }

    auto it = m_bannerBoxGraphic.constFind(slot);
    if (it != m_bannerBoxGraphic.constEnd()) {
        qDebug() << "[DBG]  found (map size =" << m_bannerBoxGraphic.size() << ")";
        return it.value();
    }

    qDebug() << "[DBG]  not found (map size =" << m_bannerBoxGraphic.size() << ")";
    return defaultGraphic;

}

void SingletonBannerDb::dumpContents() const
{
    qDebug() << "----- SingletonBannerDb dump ----- this=" << static_cast<const void*>(this)
             << " map_addr=" << static_cast<const void*>(&m_bannerBoxGraphic);
    for (auto it = m_bannerBoxGraphic.constBegin(); it != m_bannerBoxGraphic.constEnd(); ++it) {
        qDebug() << "  slot =" << static_cast<int>(it.key())
                 << ", graphic.valid? =" << !it.value().isNull();
    }
    qDebug() << "---------------------------------";
}

