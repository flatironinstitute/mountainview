/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/1/2016
*******************************************************/

#ifndef PAINTLAYERSTACK_H
#define PAINTLAYERSTACK_H

#include "paintlayer.h"

class PaintLayerStackPrivate;
class PaintLayerStack : public PaintLayer {
    Q_OBJECT
public:
    friend class PaintLayerStackPrivate;
    PaintLayerStack(QObject* parent = 0);
    virtual ~PaintLayerStack();

    void addLayer(PaintLayer* layer);

    virtual void paint(QPainter* painter) Q_DECL_OVERRIDE;
    virtual void mousePressEvent(QMouseEvent* evt) Q_DECL_OVERRIDE;
    virtual void mouseReleaseEvent(QMouseEvent* evt) Q_DECL_OVERRIDE;
    virtual void mouseMoveEvent(QMouseEvent* evt) Q_DECL_OVERRIDE;
    virtual void setWindowSize(QSize size) Q_DECL_OVERRIDE;

private slots:

private:
    PaintLayerStackPrivate* d;
};

#endif // PAINTLAYERSTACK_H
