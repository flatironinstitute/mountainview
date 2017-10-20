/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
*******************************************************/

#ifndef HISTOGRAMVIEW_H
#define HISTOGRAMVIEW_H

#include "renderablewidget.h"

#include <QWidget>
#include <mvmisc.h>

/** \class HistogramView
 *  \brief View of a histogram from an arbitrary data array
 */
class HistogramViewPrivate;
class HistogramView : public RenderableWidget {
    Q_OBJECT
public:
    enum TimeScaleMode {
        Uniform,
        Log,
        Cubic
    };

    friend class HistogramViewPrivate;
    explicit HistogramView(QWidget* parent = 0);
    virtual ~HistogramView();

    void setData(const QVector<double>& values); // The data to view
    void setSecondData(const QVector<double>& values);
    void setBinInfo(double bin_min, double bin_max, int num_bins); //Set evenly spaced bins
    void setFillColor(const QColor& col); // The color for filling the histogram bars
    void setLineColor(const QColor& col); // The edge color for the bars
    void setTitle(const QString& title);
    void setCaption(const QString& caption);
    void setColors(const QMap<QString, QColor>& colors); // Controls background and highlighting colors. For consistent app look.
    void setTimeScaleMode(TimeScaleMode mode);
    void setTimeConstant(double timepoints);

    MVRange xRange() const;
    void setXRange(MVRange range);
    void autoCenterXRange(); //centers range based on data
    void setDrawVerticalAxisAtZero(bool val);
    void setVerticalLines(const QList<double>& vals);
    void setTickMarks(const QList<double>& vals);

    void setCurrent(bool val); // Set this as the current histogram (affects highlighting)
    void setSelected(bool val); // Set this as among the selected histograms (affects highlighting)

    QImage renderImage(int W, int H) Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent* evt);
    void mousePressEvent(QMouseEvent* evt);
    void mouseMoveEvent(QMouseEvent* evt);
    void enterEvent(QEvent* evt);
    void leaveEvent(QEvent* evt);
    void mouseDoubleClickEvent(QMouseEvent* evt);
signals:
    void clicked(Qt::KeyboardModifiers modifiers);
    void rightClicked(Qt::KeyboardModifiers modifiers);
    void activated(const QPoint&);

    void signalExportHistogramMatrixImage();

private slots:
    void slot_context_menu(const QPoint& pos);

private:
    HistogramViewPrivate* d;
};

#endif // HISTOGRAMVIEW_H
