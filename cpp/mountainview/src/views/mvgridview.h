/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 10/25/2016
*******************************************************/
#ifndef MVGRIDVIEW_H
#define MVGRIDVIEW_H

#include "renderablewidget.h"

#include <mvabstractview.h>
#include <QResizeEvent>

class MVGridViewPrivate;
class MVGridView : public MVAbstractView {
    Q_OBJECT
public:
    friend class MVGridViewPrivate;
    MVGridView(MVAbstractContext* context);
    virtual ~MVGridView();

    void setPreferredViewWidth(int width);
    void updateLayout();
    void setHorizontalScaleWidget(QWidget* W);
    void setForceSquareMatrix(bool val);
    void setPreferredHistogramWidth(int width); //use 0 for zoomed all the way out
    void updateViews();
    int currentViewIndex() const;

    QImage renderImage(int W = 0, int H = 0);

signals:
    void signalViewClicked(int index, Qt::KeyboardModifiers modifiers);

protected:
    void resizeEvent(QResizeEvent* evt);

    void clearViews();
    void addView(RenderableWidget* W);
    int viewCount() const;
    RenderableWidget* view(int j) const;

private slots:
    void slot_zoom_out(double factor = 1.2);
    void slot_zoom_in(double factor = 1.2);
    void slot_signal_view_clicked(int, Qt::KeyboardModifiers);
    void slot_grid_properties();
    void slot_export_image();

private:
    MVGridViewPrivate* d;
};

#endif // MVGRIDVIEW_H
