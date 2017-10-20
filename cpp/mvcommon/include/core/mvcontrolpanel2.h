/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 6/27/2016
*******************************************************/

#ifndef MVCONTROLPANEL2_H
#define MVCONTROLPANEL2_H

#include "mvabstractcontrol.h"
#include <QWidget>

class MVControlPanel2Private;
class MVControlPanel2 : public QWidget {
    Q_OBJECT
public:
    friend class MVControlPanel2Private;
    MVControlPanel2(MVAbstractContext* context, MVMainWindow* mw);
    virtual ~MVControlPanel2();
    void insertControl(int position, MVAbstractControl* mvcontrol, bool start_open);
    void addControl(MVAbstractControl* mvcontrol, bool start_open);

private slots:
    void slot_recalc_visible();
    void slot_recalc_all();

private:
    MVControlPanel2Private* d;
};

#endif // MVCONTROLPANEL2_H
