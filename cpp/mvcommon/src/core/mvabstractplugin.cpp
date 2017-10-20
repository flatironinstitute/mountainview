/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 8/20/2016
*******************************************************/

#include "mvabstractplugin.h"

MVAbstractPlugin::MVAbstractPlugin()
{
}

MVAbstractPlugin::~MVAbstractPlugin()
{
}

void MVAbstractPlugin::initialize(MVMainWindow* mw)
{
    m_main_window = mw;
}

QList<QAction*> MVAbstractPlugin::actions(const QMimeData& md)
{
    Q_UNUSED(md)
    return QList<QAction*>();
}

MVMainWindow* MVAbstractPlugin::mainWindow()
{
    return m_main_window;
}
