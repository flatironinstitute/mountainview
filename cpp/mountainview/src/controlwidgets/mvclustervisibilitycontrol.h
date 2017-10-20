/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 6/27/2016
*******************************************************/

#ifndef MVCLUSTERVISIBILITYCONTROL_H
#define MVCLUSTERVISIBILITYCONTROL_H

#include "mvabstractcontrol.h"

class MVClusterVisibilityControlPrivate;
class MVClusterVisibilityControl : public MVAbstractControl {
    Q_OBJECT
public:
    friend class MVClusterVisibilityControlPrivate;
    MVClusterVisibilityControl(MVAbstractContext* context, MVMainWindow* mw);
    virtual ~MVClusterVisibilityControl();

    QString title() const Q_DECL_OVERRIDE;
public slots:
    virtual void updateContext() Q_DECL_OVERRIDE;
    virtual void updateControls() Q_DECL_OVERRIDE;

private slots:

private:
    MVClusterVisibilityControlPrivate* d;
};

#endif // MVCLUSTERVISIBILITYCONTROL_H
