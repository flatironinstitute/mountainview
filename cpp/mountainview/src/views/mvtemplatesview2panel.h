/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/29/2016
*******************************************************/

#ifndef MVTEMPLATESVIEW2PANEL_H
#define MVTEMPLATESVIEW2PANEL_H

#include "paintlayer.h"
#include <QWidget>
#include <mda.h>
#include <mvcontext.h>

class MVTemplatesView2PanelPrivate;
class MVTemplatesView2Panel : public PaintLayer {
public:
    friend class MVTemplatesView2PanelPrivate;
    MVTemplatesView2Panel();
    virtual ~MVTemplatesView2Panel();
    void setTemplate(const Mda& X);
    void setElectrodeGeometry(const ElectrodeGeometry& geom);
    void setVerticalScaleFactor(double factor);
    void setChannelColors(const QList<QColor>& colors);
    void setColors(const QMap<QString, QColor>& colors);
    void setCurrent(bool val);
    void setSelected(bool val);
    void setTitle(const QString& txt);
    void setFiringRateDiskDiameter(double val);

protected:
    void paint(QPainter* painter) Q_DECL_OVERRIDE;

private:
    MVTemplatesView2PanelPrivate* d;
};

#endif // MVTEMPLATESVIEW2PANEL_H
