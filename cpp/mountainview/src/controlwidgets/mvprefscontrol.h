#ifndef MVPREFSCONTROL_H
#define MVPREFSCONTROL_H

#include "mvabstractcontrol.h"

class MVPrefsControlPrivate;
class MVPrefsControl : public MVAbstractControl {
    Q_OBJECT
public:
    friend class MVPrefsControlPrivate;
    MVPrefsControl(MVAbstractContext* context, MVMainWindow* mw);
    virtual ~MVPrefsControl();

    QString title() const Q_DECL_OVERRIDE;
public slots:
    virtual void updateContext() Q_DECL_OVERRIDE;
    virtual void updateControls() Q_DECL_OVERRIDE;

private slots:

private:
    MVPrefsControlPrivate* d;
};

#endif // MVPREFSCONTROL_H
