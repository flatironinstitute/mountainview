/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 8/24/2016
*******************************************************/
#ifndef CurationProgramPLUGIN_H
#define CurationProgramPLUGIN_H

#include "mvmainwindow.h"

#include <QThread>

class CurationProgramPluginPrivate;
class CurationProgramPlugin : public MVAbstractPlugin {
public:
    friend class CurationProgramPluginPrivate;
    CurationProgramPlugin();
    virtual ~CurationProgramPlugin();

    QString name() Q_DECL_OVERRIDE;
    QString description() Q_DECL_OVERRIDE;
    void initialize(MVMainWindow* mw) Q_DECL_OVERRIDE;

private:
    CurationProgramPluginPrivate* d;
};

class CurationProgramFactory : public MVAbstractViewFactory {
    Q_OBJECT
public:
    CurationProgramFactory(MVMainWindow* mw, QObject* parent = 0);
    QString id() const Q_DECL_OVERRIDE;
    QString name() const Q_DECL_OVERRIDE;
    QString title() const Q_DECL_OVERRIDE;
    MVAbstractView* createView(MVAbstractContext* context) Q_DECL_OVERRIDE;
private slots:
    //void openClipsForTemplate();
};

#endif // CurationProgramPLUGIN_H
