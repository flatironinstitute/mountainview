/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 8/24/2016
*******************************************************/
#ifndef CLIPSVIEWPLUGIN_H
#define CLIPSVIEWPLUGIN_H

#include "mvmainwindow.h"

class ClipsViewPluginPrivate;
class ClipsViewPlugin : public MVAbstractPlugin {
public:
    friend class ClipsViewPluginPrivate;
    ClipsViewPlugin();
    virtual ~ClipsViewPlugin();

    QString name() Q_DECL_OVERRIDE;
    QString description() Q_DECL_OVERRIDE;
    void initialize(MVMainWindow* mw) Q_DECL_OVERRIDE;
    virtual QList<QAction*> actions(const QMimeData& md) Q_DECL_OVERRIDE;

private:
    ClipsViewPluginPrivate* d;
};

class ClipsViewFactory : public MVAbstractViewFactory {
    Q_OBJECT
public:
    ClipsViewFactory(MVMainWindow* mw, QObject* parent = 0);
    QString id() const Q_DECL_OVERRIDE;
    QString name() const Q_DECL_OVERRIDE;
    QString title() const Q_DECL_OVERRIDE;
    MVAbstractView* createView(MVAbstractContext* context) Q_DECL_OVERRIDE;
private slots:
    //void openClipsForTemplate();
};

#endif // CLIPSVIEWPLUGIN_H
