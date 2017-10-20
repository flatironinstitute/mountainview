#include "createtimeseriesdialog.h"

#include "ui_createtimeseriesdialog.h"

class CreateTimeseriesDialogPrivate {
public:
    CreateTimeseriesDialog* q;
    Ui_CreateTimeseriesDialog ui;
};

CreateTimeseriesDialog::CreateTimeseriesDialog()
{
    d = new CreateTimeseriesDialogPrivate;
    d->q = this;
    d->ui.setupUi(this);
    d->ui.samplerate->setReadOnly(true);
}

CreateTimeseriesDialog::~CreateTimeseriesDialog()
{
    delete d;
}

void CreateTimeseriesDialog::setSampleRate(double val)
{
    d->ui.samplerate->setText(QString("%1").arg(val));
}

void CreateTimeseriesDialog::setFreqMax(double val)
{
    d->ui.freq_max->setText(QString("%1").arg(val));
}

void CreateTimeseriesDialog::setFreqMin(double val)
{
    d->ui.freq_min->setText(QString("%1").arg(val));
}

double CreateTimeseriesDialog::sampleRate() const
{
    return d->ui.samplerate->text().toDouble();
}

double CreateTimeseriesDialog::freqMin() const
{
    return d->ui.freq_min->text().toDouble();
}

double CreateTimeseriesDialog::freqMax() const
{
    return d->ui.freq_max->text().toDouble();
}
