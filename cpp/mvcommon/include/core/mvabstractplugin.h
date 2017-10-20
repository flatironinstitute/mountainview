/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 8/20/2016
*******************************************************/
#ifndef MVABSTRACTPLUGIN_H
#define MVABSTRACTPLUGIN_H

#include <QString>
#include "mvabstractviewfactory.h"

class MVMainWindow;
class MVAbstractPlugin {
public:
    MVAbstractPlugin();
    virtual ~MVAbstractPlugin();

    virtual QString name() = 0;
    virtual QString description() = 0;
    virtual void initialize(MVMainWindow* mw);

    virtual QList<QAction*> actions(const QMimeData& md);

protected:
    MVMainWindow* mainWindow();

private:
    MVMainWindow* m_main_window = 0;
};

#endif // MVABSTRACTPLUGIN_H
