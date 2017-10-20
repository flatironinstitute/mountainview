#ifndef MVDISCRIMHISTVIEW_GUIDE_H
#define MVDISCRIMHISTVIEW_GUIDE_H

#include "mvabstractviewfactory.h"
#include "mvhistogramgrid.h"

class MVDiscrimHistViewGuidePrivate;
class MVDiscrimHistViewGuide : public MVHistogramGrid {
    Q_OBJECT
public:
    friend class MVDiscrimHistViewGuidePrivate;
    MVDiscrimHistViewGuide(MVAbstractContext* context);
    virtual ~MVDiscrimHistViewGuide();

    void setNumHistograms(int num);

    void prepareCalculation() Q_DECL_OVERRIDE;
    void runCalculation() Q_DECL_OVERRIDE;
    void onCalculationFinished() Q_DECL_OVERRIDE;

    void wheelEvent(QWheelEvent* evt);

signals:

private slots:
    void slot_zoom_in_horizontal(double factor = 1.2);
    void slot_zoom_out_horizontal(double factor = 1.2);
    void slot_pan_left(double units = 0.1);
    void slot_pan_right(double units = 0.1);

private:
    MVDiscrimHistViewGuidePrivate* d;
};

class MVDiscrimHistGuideFactory : public MVAbstractViewFactory {
    Q_OBJECT
public:
    MVDiscrimHistGuideFactory(MVMainWindow* mw, QObject* parent = 0);
    QString id() const Q_DECL_OVERRIDE;
    QString name() const Q_DECL_OVERRIDE;
    QString title() const Q_DECL_OVERRIDE;
    MVAbstractView* createView(MVAbstractContext* context) Q_DECL_OVERRIDE;
    bool isEnabled(MVAbstractContext* context) const Q_DECL_OVERRIDE;
};

#endif // MVDISCRIMHISTVIEW_GUIDE_H
