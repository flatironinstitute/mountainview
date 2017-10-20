/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 8/25/2016
*******************************************************/
#ifndef CLUSTERCONTEXTMENUPLUGIN_H
#define CLUSTERCONTEXTMENUPLUGIN_H

#include "mvmainwindow.h"

class ClusterContextMenuPluginPrivate;
class ClusterContextMenuPlugin : public MVAbstractPlugin {
public:
    friend class ClusterContextMenuPluginPrivate;
    ClusterContextMenuPlugin();
    virtual ~ClusterContextMenuPlugin();

    QString name() Q_DECL_OVERRIDE;
    QString description() Q_DECL_OVERRIDE;
    void initialize(MVMainWindow* mw) Q_DECL_OVERRIDE;

private:
    ClusterContextMenuPluginPrivate* d;
};

#endif // CLUSTERCONTEXTMENUPLUGIN_H
