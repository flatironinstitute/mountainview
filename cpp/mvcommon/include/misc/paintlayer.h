/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/1/2016
*******************************************************/

#ifndef PAINTLAYER_H
#define PAINTLAYER_H

#include <QMouseEvent>
#include <QPainter>
#include <QWidget>
#include <renderablewidget.h>

class PaintLayerPrivate;
class PaintLayer : public QObject {
    Q_OBJECT
public:
    friend class PaintLayerPrivate;
    PaintLayer(QObject* parent = 0);
    virtual ~PaintLayer();

    virtual void paint(QPainter* painter) = 0;

    void setExportMode(bool val);
    bool exportMode() const;

    virtual void mousePressEvent(QMouseEvent* evt) { Q_UNUSED(evt) }
    virtual void mouseReleaseEvent(QMouseEvent* evt) { Q_UNUSED(evt) }
    virtual void mouseMoveEvent(QMouseEvent* evt) { Q_UNUSED(evt) }

    //used by the subclass
    QSize windowSize() const;
    QFont font() const;
    void setFont(QFont font);

    //used by the widget/paintlayerstack
    virtual void setWindowSize(QSize size);

protected:
signals:
    void windowSizeChanged();
    void repaintNeeded();

private:
    PaintLayerPrivate* d;
};

class PaintLayerWidgetPrivate;
class PaintLayerWidget : public RenderableWidget {
public:
    friend class PaintLayerWidgetPrivate;
    PaintLayerWidget(PaintLayer* PL);
    virtual ~PaintLayerWidget();
    QImage renderImage(int W, int H) Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent* evt);

private:
    PaintLayerWidgetPrivate* d;
};

#endif // PAINTLAYER_H
