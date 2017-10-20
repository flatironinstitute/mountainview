/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 8/24/2016
*******************************************************/
#ifndef CLUSTERDETAILPLUGIN_H
#define CLUSTERDETAILPLUGIN_H

#include "mvmainwindow.h"

class ClusterDetailPluginPrivate;
class ClusterDetailPlugin : public MVAbstractPlugin {
public:
    friend class ClusterDetailPluginPrivate;
    ClusterDetailPlugin();
    virtual ~ClusterDetailPlugin();

    QString name() Q_DECL_OVERRIDE;
    QString description() Q_DECL_OVERRIDE;
    void initialize(MVMainWindow* mw) Q_DECL_OVERRIDE;

private:
    ClusterDetailPluginPrivate* d;
};

class ClusterDetailFactory : public MVAbstractViewFactory {
    Q_OBJECT
public:
    ClusterDetailFactory(MVMainWindow* mw, QObject* parent = 0);
    QString id() const Q_DECL_OVERRIDE;
    QString name() const Q_DECL_OVERRIDE;
    QString title() const Q_DECL_OVERRIDE;
    MVAbstractView* createView(MVAbstractContext* context) Q_DECL_OVERRIDE;
private slots:
    //void openClipsForTemplate();
};

#endif // CLUSTERDETAILPLUGIN_H
