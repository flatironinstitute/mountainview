/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/29/2016
*******************************************************/

#ifndef CurationProgramView_H
#define CurationProgramView_H

#include "mvabstractview.h"

#include <mvcontext.h>
#include <mvabstractviewfactory.h>

class CurationProgramViewPrivate;
class CurationProgramView : public MVAbstractView {
    Q_OBJECT
public:
    friend class CurationProgramViewPrivate;
    CurationProgramView(MVAbstractContext* mvcontext);
    virtual ~CurationProgramView();

    void prepareCalculation() Q_DECL_OVERRIDE;
    void runCalculation() Q_DECL_OVERRIDE;
    void onCalculationFinished() Q_DECL_OVERRIDE;

    static QString applyCurationProgram(MVAbstractContext* mv_context);

protected:
private slots:
    void slot_text_changed();
    void slot_apply();

private:
    CurationProgramViewPrivate* d;
};

#endif // CurationProgramView_H
