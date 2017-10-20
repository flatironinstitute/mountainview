/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 6/27/2016
*******************************************************/

#ifndef MVTIMESERIESCONTROL_H
#define MVTIMESERIESCONTROL_H

#include "mvabstractcontrol.h"

class MVTimeseriesControlPrivate;
class MVTimeseriesControl : public MVAbstractControl {
    Q_OBJECT
public:
    friend class MVTimeseriesControlPrivate;
    MVTimeseriesControl(MVAbstractContext* context, MVMainWindow* mw);
    virtual ~MVTimeseriesControl();

    QString title() const Q_DECL_OVERRIDE;
public slots:
    virtual void updateContext() Q_DECL_OVERRIDE;
    virtual void updateControls() Q_DECL_OVERRIDE;

private slots:
    void slot_create();
    void slot_calculator_finished();

private:
    MVTimeseriesControlPrivate* d;
};

#endif // MVTIMESERIESCONTROL_H
