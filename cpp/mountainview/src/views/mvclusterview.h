/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
*******************************************************/

#ifndef MVCLUSTERVIEW_H
#define MVCLUSTERVIEW_H

#include <QWidget>
#include <mvabstractcontext.h>
#include "mda.h"
#include "mvutils.h"
#include "affinetransformation.h"
#include "paintlayer.h"

#define MVCV_MODE_HEAT_DENSITY 1
#define MVCV_MODE_LABEL_COLORS 2
#define MVCV_MODE_TIME_COLORS 3
#define MVCV_MODE_AMPLITUDE_COLORS 4

/** \class MVClusterView
 *  \brief A rotatable view of datapoints in 3D space
 *
 *  Several modes are available
 */

class MVClusterViewPrivate;
class MVClusterView : public QWidget {
    Q_OBJECT
public:
    friend class MVClusterViewPrivate;
    MVClusterView(MVAbstractContext* context, QWidget* parent = 0);
    virtual ~MVClusterView();
    void setData(const Mda& X);
    bool hasData();
    void setTimes(const QVector<double>& times);
    void setLabels(const QVector<int>& labels);
    void setAmplitudes(const QVector<double>& amps);

    void setMode(int mode);
    void setCurrentEvent(MVEvent evt, bool do_emit = false);
    MVEvent currentEvent();
    int currentEventIndex();
    AffineTransformation transformation();
    void setTransformation(const AffineTransformation& T);

    QSet<int> activeClusterNumbers() const;
    void setActiveClusterNumbers(const QSet<int>& A);

    QImage renderImage(int W, int H);
signals:
    void currentEventChanged();
    void transformationChanged();
    void activeClusterNumbersChanged();

private slots:
    void slot_context_menu(const QPoint& pos);
    void slot_active_cluster_numbers_changed();
    void slot_hovered_cluster_number_changed();
    void slot_update_colors();

protected:
    void paintEvent(QPaintEvent* evt);
    void mouseMoveEvent(QMouseEvent* evt);
    void mousePressEvent(QMouseEvent* evt);
    void mouseReleaseEvent(QMouseEvent* evt);
    void wheelEvent(QWheelEvent* evt);
    void resizeEvent(QResizeEvent* evt);

private:
    MVClusterViewPrivate* d;
};

#endif // MVCLUSTERVIEW_H
