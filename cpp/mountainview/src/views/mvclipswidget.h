/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 4/4/2016
*******************************************************/

#ifndef MVCLIPSWIDGET_H
#define MVCLIPSWIDGET_H

#include "diskreadmda.h"
#include <QWidget>
#include "mvutils.h"
#include "mvabstractview.h"
#include "mvabstractviewfactory.h"

class MVClipsWidgetPrivate;
class MVClipsWidget : public MVAbstractView {
    Q_OBJECT
public:
    friend class MVClipsWidgetPrivate;
    MVClipsWidget(MVContext* context);
    virtual ~MVClipsWidget();

    void prepareCalculation() Q_DECL_OVERRIDE;
    void runCalculation() Q_DECL_OVERRIDE;
    void onCalculationFinished() Q_DECL_OVERRIDE;

    void setLabelsToUse(const QList<int>& labels);

    void paintEvent(QPaintEvent* evt);
signals:
private slots:

private:
    MVClipsWidgetPrivate* d;
};

#endif // MVCLIPSWIDGET_H
