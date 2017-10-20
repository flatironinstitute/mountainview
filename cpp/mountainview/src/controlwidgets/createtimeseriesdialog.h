#ifndef CREATETIMESERIESDIALOG_H
#define CREATETIMESERIESDIALOG_H

#include <QDialog>

class CreateTimeseriesDialogPrivate;
class CreateTimeseriesDialog : public QDialog {
public:
    friend class CreateTimeseriesDialogPrivate;
    CreateTimeseriesDialog();
    virtual ~CreateTimeseriesDialog();
    void setSampleRate(double val);
    void setFreqMin(double val);
    void setFreqMax(double val);
    double sampleRate() const;
    double freqMin() const;
    double freqMax() const;

private:
    CreateTimeseriesDialogPrivate* d;
};

#endif // CREATETIMESERIESDIALOG_H
