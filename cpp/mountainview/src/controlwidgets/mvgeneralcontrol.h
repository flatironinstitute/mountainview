/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 6/27/2016
*******************************************************/

#ifndef MVGENERALCONTROL_H
#define MVGENERALCONTROL_H

#include "mvabstractcontrol.h"

class MVGeneralControlPrivate;
class MVGeneralControl : public MVAbstractControl {
    Q_OBJECT
public:
    friend class MVGeneralControlPrivate;
    MVGeneralControl(MVAbstractContext* context, MVMainWindow* mw);
    virtual ~MVGeneralControl();

    QString title() const Q_DECL_OVERRIDE;
public slots:
    virtual void updateContext() Q_DECL_OVERRIDE;
    virtual void updateControls() Q_DECL_OVERRIDE;

private slots:

private:
    MVGeneralControlPrivate* d;
};

#endif // MVGENERALCONTROL_H
