/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 10/25/2016
*******************************************************/
#ifndef RENDERABLEWIDGET_H
#define RENDERABLEWIDGET_H

#include <QWidget>

class RenderableWidgetPrivate;
class RenderableWidget : public QWidget {
public:
    friend class RenderableWidgetPrivate;
    RenderableWidget(QWidget* parent = 0);
    virtual ~RenderableWidget();
    void setExportMode(bool val);
    bool exportMode() const;
    virtual QImage renderImage(int W, int H) = 0;

private:
    RenderableWidgetPrivate* d;
};

#endif // RENDERABLEWIDGET_H
