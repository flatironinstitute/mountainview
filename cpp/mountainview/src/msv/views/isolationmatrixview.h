/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/29/2016
*******************************************************/

#ifndef IsolationMatrixView_H
#define IsolationMatrixView_H

#include "mvabstractview.h"

#include <mvcontext.h>
#include <mvabstractviewfactory.h>

class IsolationMatrixViewPrivate;
class IsolationMatrixView : public MVAbstractView {
    Q_OBJECT
public:
    enum PermutationMode {
        NoPermutation,
        RowPermutation,
        ColumnPermutation,
        BothRowBasedPermutation,
        BothColumnBasedPermutation
    };

    friend class IsolationMatrixViewPrivate;
    IsolationMatrixView(MVContext* mvcontext);
    virtual ~IsolationMatrixView();

    void prepareCalculation() Q_DECL_OVERRIDE;
    void runCalculation() Q_DECL_OVERRIDE;
    void onCalculationFinished() Q_DECL_OVERRIDE;

protected:
    void keyPressEvent(QKeyEvent* evt) Q_DECL_OVERRIDE;
    void prepareMimeData(QMimeData& mimeData, const QPoint& pos) Q_DECL_OVERRIDE;

private slots:
    void slot_permutation_mode_button_clicked();
    void slot_matrix_view_current_element_changed();
    void slot_update_current_elements_based_on_context();

private:
    IsolationMatrixViewPrivate* d;
};

#endif // IsolationMatrixView_H
