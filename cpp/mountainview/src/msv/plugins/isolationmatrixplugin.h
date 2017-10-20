/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 8/24/2016
*******************************************************/
#ifndef IsolationMatrixPLUGIN_H
#define IsolationMatrixPLUGIN_H

#include "mvmainwindow.h"

class IsolationMatrixPluginPrivate;
class IsolationMatrixPlugin : public MVAbstractPlugin {
public:
    friend class IsolationMatrixPluginPrivate;
    IsolationMatrixPlugin();
    virtual ~IsolationMatrixPlugin();

    QString name() Q_DECL_OVERRIDE;
    QString description() Q_DECL_OVERRIDE;
    void initialize(MVMainWindow* mw) Q_DECL_OVERRIDE;

private:
    IsolationMatrixPluginPrivate* d;
};

class IsolationMatrixFactory : public MVAbstractViewFactory {
    Q_OBJECT
public:
    IsolationMatrixFactory(MVMainWindow* mw, QObject* parent = 0);
    QString id() const Q_DECL_OVERRIDE;
    QString name() const Q_DECL_OVERRIDE;
    QString title() const Q_DECL_OVERRIDE;
    MVAbstractView* createView(MVAbstractContext* context) Q_DECL_OVERRIDE;
private slots:
    //void openClipsForTemplate();
};

#endif // IsolationMatrixPLUGIN_H
