/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/1/2016
*******************************************************/

#ifndef MVCLUSTERLEGEND_H
#define MVCLUSTERLEGEND_H

#include "paintlayer.h"

class MVClusterLegendPrivate;
class MVClusterLegend : public PaintLayer {
    Q_OBJECT
public:
    friend class MVClusterLegend2Private;
    MVClusterLegend();
    virtual ~MVClusterLegend();

    virtual void paint(QPainter* painter) Q_DECL_OVERRIDE;
    virtual void mousePressEvent(QMouseEvent* evt) Q_DECL_OVERRIDE;
    virtual void mouseReleaseEvent(QMouseEvent* evt) Q_DECL_OVERRIDE;
    virtual void mouseMoveEvent(QMouseEvent* evt) Q_DECL_OVERRIDE;

    void setClusterColors(const QList<QColor>& colors);
    void setClusterNumbers(const QList<int>& numbers);

    int hoveredClusterNumber() const;
    QSet<int> activeClusterNumbers() const;
    void setActiveClusterNumbers(const QSet<int>& active_numbers);
signals:
    void hoveredClusterNumberChanged();
    void activeClusterNumbersChanged();

private:
    MVClusterLegendPrivate* d;
};

#endif // MVCLUSTERLEGEND_H
