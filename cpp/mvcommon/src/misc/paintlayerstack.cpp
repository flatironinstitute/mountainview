/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/1/2016
*******************************************************/

#include "paintlayerstack.h"
#include <QDebug>

class PaintLayerStackPrivate {
public:
    PaintLayerStack* q;
    QList<PaintLayer*> m_layers;
};

PaintLayerStack::PaintLayerStack(QObject* parent)
    : PaintLayer(parent)
{
    d = new PaintLayerStackPrivate;
    d->q = this;
}

PaintLayerStack::~PaintLayerStack()
{
    delete d;
}

void PaintLayerStack::addLayer(PaintLayer* layer)
{
    d->m_layers << layer;

    /// Witold, is this the right thing to do?
    layer->setParent(this);

    layer->setWindowSize(this->windowSize());

    QObject::connect(layer, SIGNAL(repaintNeeded()), this, SIGNAL(repaintNeeded()));
}

void PaintLayerStack::paint(QPainter* painter)
{
    for (int i = 0; i < d->m_layers.count(); i++) {
        bool hold_export_mode = d->m_layers[i]->exportMode();
        d->m_layers[i]->setExportMode(this->exportMode());
        d->m_layers[i]->paint(painter);
        d->m_layers[i]->setExportMode(hold_export_mode);
    }
}

void PaintLayerStack::mousePressEvent(QMouseEvent* evt)
{
    evt->setAccepted(false);
    for (int i = d->m_layers.count() - 1; i >= 0; i--) {
        if (evt->isAccepted())
            break;
        d->m_layers[i]->mousePressEvent(evt);
    }
}

void PaintLayerStack::mouseReleaseEvent(QMouseEvent* evt)
{
    evt->setAccepted(false);
    for (int i = d->m_layers.count() - 1; i >= 0; i--) {
        if (evt->isAccepted())
            break;
        d->m_layers[i]->mouseReleaseEvent(evt);
    }
}

void PaintLayerStack::mouseMoveEvent(QMouseEvent* evt)
{
    evt->setAccepted(false);
    for (int i = d->m_layers.count() - 1; i >= 0; i--) {
        if (evt->isAccepted())
            break;
        d->m_layers[i]->mouseMoveEvent(evt);
    }
}

void PaintLayerStack::setWindowSize(QSize size)
{
    for (int i = 0; i < d->m_layers.count(); i++) {
        d->m_layers[i]->setWindowSize(size);
    }
    PaintLayer::setWindowSize(size);
}
