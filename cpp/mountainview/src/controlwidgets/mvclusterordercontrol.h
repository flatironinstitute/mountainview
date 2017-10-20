/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 6/27/2016
*******************************************************/

#ifndef MVCLUSTERORDERCONTROL_H
#define MVCLUSTERORDERCONTROL_H

#include "mvabstractcontrol.h"

class MVClusterOrderControlPrivate;
class MVClusterOrderControl : public MVAbstractControl {
    Q_OBJECT
public:
    friend class MVClusterOrderControlPrivate;
    MVClusterOrderControl(MVAbstractContext* context, MVMainWindow* mw);
    virtual ~MVClusterOrderControl();

    QString title() const Q_DECL_OVERRIDE;
public slots:
    virtual void updateContext() Q_DECL_OVERRIDE;
    virtual void updateControls() Q_DECL_OVERRIDE;

private slots:
    void slot_order_by_detectability();
    void slot_computation_finished();

private:
    MVClusterOrderControlPrivate* d;
};

#endif // MVCLUSTERORDERCONTROL_H
