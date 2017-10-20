/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/1/2016
*******************************************************/

#include "paintlayer.h"
#include <QDebug>

class PaintLayerPrivate {
public:
    PaintLayer* q;
    bool m_repaint_needed = false;
    QSize m_window_size = QSize(0, 0);
    QFont m_font;
    bool m_export_mode = false;
};

PaintLayer::PaintLayer(QObject* parent)
    : QObject(parent)
{
    d = new PaintLayerPrivate;
    d->q = this;
}

PaintLayer::~PaintLayer()
{
    delete d;
}

void PaintLayer::setExportMode(bool val)
{
    d->m_export_mode = val;
}

bool PaintLayer::exportMode() const
{
    return d->m_export_mode;
}

QSize PaintLayer::windowSize() const
{
    return d->m_window_size;
}

QFont PaintLayer::font() const
{
    return d->m_font;
}

void PaintLayer::setWindowSize(QSize size)
{
    if (d->m_window_size == size)
        return;
    d->m_window_size = size;
    emit this->windowSizeChanged();
}

void PaintLayer::setFont(QFont font)
{
    d->m_font = font;
}

class PaintLayerWidgetPrivate {
public:
    PaintLayerWidget* q;
    PaintLayer* m_paint_layer;
};

PaintLayerWidget::PaintLayerWidget(PaintLayer* PL)
{
    d = new PaintLayerWidgetPrivate;
    d->q = this;
    d->m_paint_layer = PL;

    connect(PL, SIGNAL(repaintNeeded()), this, SLOT(update()));
}

PaintLayerWidget::~PaintLayerWidget()
{
    delete d;
}

QImage PaintLayerWidget::renderImage(int W, int H)
{
    QImage img(W, H, QImage::Format_ARGB32);
    img.fill(Qt::white);
    QPainter painter(&img);
    QSize hold_size = d->m_paint_layer->windowSize();
    d->m_paint_layer->setFont(this->font());
    d->m_paint_layer->setWindowSize(QSize(W, H));
    bool hold_export_mode = d->m_paint_layer->exportMode();
    d->m_paint_layer->setExportMode(this->exportMode());
    d->m_paint_layer->paint(&painter);
    d->m_paint_layer->setExportMode(hold_export_mode);
    d->m_paint_layer->setWindowSize(hold_size);
    return img;
}

void PaintLayerWidget::paintEvent(QPaintEvent* evt)
{
    Q_UNUSED(evt);
    QPainter painter(this);
    d->m_paint_layer->setFont(this->font());
    d->m_paint_layer->setWindowSize(this->size());
    d->m_paint_layer->paint(&painter);
}
