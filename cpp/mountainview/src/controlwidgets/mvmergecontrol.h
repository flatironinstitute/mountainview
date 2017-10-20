/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/13/2016
*******************************************************/

#ifndef MVMERGECONTROL
#define MVMERGECONTROL

#include "mvabstractcontrol.h"

class MVMergeControlPrivate;
class MVMergeControl : public MVAbstractControl {
    Q_OBJECT
public:
    friend class MVMergeControlPrivate;
    MVMergeControl(MVAbstractContext* context, MVMainWindow* mw);
    virtual ~MVMergeControl();

    QString title() const Q_DECL_OVERRIDE;

public slots:
    virtual void updateContext() Q_DECL_OVERRIDE;
    virtual void updateControls() Q_DECL_OVERRIDE;

private slots:
    void slot_merge_selected();
    void slot_unmerge_selected();

private:
    MVMergeControlPrivate* d;
};

#endif // MVMERGECONTROL
