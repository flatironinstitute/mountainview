/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/29/2016
*******************************************************/

#ifndef ClusterPairMetricsView_H
#define ClusterPairMetricsView_H

#include "mvabstractview.h"

#include <mvcontext.h>
#include <mvabstractviewfactory.h>

class ClusterPairMetricsViewPrivate;
class ClusterPairMetricsView : public MVAbstractView {
    Q_OBJECT
public:
    friend class ClusterPairMetricsViewPrivate;
    ClusterPairMetricsView(MVAbstractContext* mvcontext);
    virtual ~ClusterPairMetricsView();

    void prepareCalculation() Q_DECL_OVERRIDE;
    void runCalculation() Q_DECL_OVERRIDE;
    void onCalculationFinished() Q_DECL_OVERRIDE;

protected:
    void keyPressEvent(QKeyEvent* evt) Q_DECL_OVERRIDE;
    void prepareMimeData(QMimeData& mimeData, const QPoint& pos) Q_DECL_OVERRIDE;

private slots:
    void slot_current_item_changed();
    void slot_item_selection_changed();
    void slot_update_current_cluster_pair();
    void slot_update_selected_cluster_pairs();

private:
    ClusterPairMetricsViewPrivate* d;
};

#endif // ClusterPairMetricsView_H
