#include "mvabstractviewfactory.h"

MVAbstractViewFactory::MVAbstractViewFactory(MVMainWindow* mw, QObject* parent)
    : QObject(parent)
{
    m_main_window = mw;
}

QString MVAbstractViewFactory::group() const { return QString(); }

QString MVAbstractViewFactory::toolTip() const { return QString(); }

QString MVAbstractViewFactory::title() const { return name(); }

MVAbstractViewFactory::PreferredOpenLocation MVAbstractViewFactory::preferredOpenLocation() const
{
    return PreferredOpenLocation::NoPreference;
}

bool MVAbstractViewFactory::isEnabled(MVAbstractContext* context) const
{
    Q_UNUSED(context)
    return true;
}

MVMainWindow* MVAbstractViewFactory::mainWindow()
{
    return m_main_window;
}

QList<QAction*> MVAbstractViewFactory::actions(const QMimeData& md)
{
    Q_UNUSED(md)
    return QList<QAction*>();
}
