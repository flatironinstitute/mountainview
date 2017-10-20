/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 6/27/2016
*******************************************************/

#ifndef MVOPENVIEWSCONTROL_H
#define MVOPENVIEWSCONTROL_H

#include "mvabstractcontrol.h"

class MVOpenViewsControlPrivate;
class MVOpenViewsControl : public MVAbstractControl {
    Q_OBJECT
public:
    friend class MVOpenViewsControlPrivate;
    MVOpenViewsControl(MVAbstractContext* context, MVMainWindow* mw);
    virtual ~MVOpenViewsControl();

    QString title() const Q_DECL_OVERRIDE;
public slots:
    virtual void updateContext() Q_DECL_OVERRIDE;
    virtual void updateControls() Q_DECL_OVERRIDE;

private slots:
    void slot_open_view(QObject* obj);
    void slot_update_enabled();
    void slot_close_all_views();

private:
    MVOpenViewsControlPrivate* d;
};

#endif // MVOPENVIEWSCONTROL_H
