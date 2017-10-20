/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 6/27/2016
*******************************************************/

#include "mvgeneralcontrol.h"

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMap>
#include <QTimer>
#include <mvcontext.h>

class MVGeneralControlPrivate {
public:
    MVGeneralControl* q;
};

MVGeneralControl::MVGeneralControl(MVAbstractContext* context, MVMainWindow* mw)
    : MVAbstractControl(context, mw)
{
    d = new MVGeneralControlPrivate;
    d->q = this;

    QGridLayout* glayout = new QGridLayout;
    int row = 0;
    {
        QWidget* X = this->createChoicesControl("timeseries");
        X->setToolTip("The default timeseries used for all the views");
        connect(context, SIGNAL(timeseriesNamesChanged()), this, SLOT(updateControls()));
        connect(context, SIGNAL(currentTimeseriesChanged()), this, SLOT(updateControls()));
        glayout->addWidget(new QLabel("Timeseries:"), row, 0);
        glayout->addWidget(X, row, 1);
        row++;
    }
    this->setLayout(glayout);

    updateControls();
}

MVGeneralControl::~MVGeneralControl()
{
    delete d;
}

QString MVGeneralControl::title() const
{
    return "General Options";
}

void MVGeneralControl::updateContext()
{
    MVContext* c = qobject_cast<MVContext*>(mvContext());
    Q_ASSERT(c);

    c->setCurrentTimeseriesName(this->controlValue("timeseries").toString());
}

void MVGeneralControl::updateControls()
{
    MVContext* c = qobject_cast<MVContext*>(mvContext());
    Q_ASSERT(c);

    this->setChoices("timeseries", c->timeseriesNames());
    this->setControlValue("timeseries", c->currentTimeseriesName());
}
