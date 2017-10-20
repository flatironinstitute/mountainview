#ifndef MATRIXVIEW_H
#define MATRIXVIEW_H

#include <QWidget>
#include <mda.h>

class MatrixViewPrivate;
class MatrixView : public QWidget {
    Q_OBJECT
public:
    enum Mode {
        PercentMode,
        CountsMode
    };

    friend class MatrixViewPrivate;
    MatrixView();
    virtual ~MatrixView();
    void setMode(Mode mode);
    void setMatrix(const Mda& A);
    void setValueRange(double minval, double maxval);
    void setIndexPermutations(const QVector<int>& perm_rows, const QVector<int>& perm_cols);
    void setLabels(const QStringList& row_labels, const QStringList& col_labels);
    void setTitle(QString title);
    void setRowAxisLabel(QString label);
    void setColumnAxisLabel(QString label);
    void setDrawDividerForFinalRow(bool val);
    void setDrawDividerForFinalColumn(bool val);
    void setCurrentElement(QPoint pt);
    QPoint currentElement() const;
signals:
    void currentElementChanged();

protected:
    void paintEvent(QPaintEvent* evt);
    void mouseMoveEvent(QMouseEvent* evt);
    void leaveEvent(QEvent*);
    void mousePressEvent(QMouseEvent* evt);

private:
    MatrixViewPrivate* d;
};

#endif // MATRIXVIEW_H
