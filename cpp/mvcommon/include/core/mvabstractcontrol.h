/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 6/27/2016
*******************************************************/

#ifndef MVABSTRACTCONTROL_H
#define MVABSTRACTCONTROL_H

#include <QCheckBox>
#include <QComboBox>
#include <QRadioButton>
#include <QToolButton>

#include "mvabstractcontext.h"

class MVMainWindow;
class MVAbstractControlPrivate;
class MVAbstractControl : public QWidget {
public:
    friend class MVAbstractControlPrivate;
    MVAbstractControl(MVAbstractContext* context, MVMainWindow* mw);
    virtual ~MVAbstractControl();

    virtual QString title() const = 0;
public slots:
    virtual void updateContext() = 0;
    virtual void updateControls() = 0;

protected:
    MVAbstractContext* mvContext();
    MVMainWindow* mainWindow();

    QVariant controlValue(QString name) const;
    void setControlValue(QString name, QVariant val);
    void setChoices(QString name, const QStringList& choices);
    void setControlEnabled(QString name, bool val);

    QWidget* createStringControl(QString name);
    QWidget* createIntControl(QString name);
    QWidget* createDoubleControl(QString name);
    QComboBox* createChoicesControl(QString name);
    QCheckBox* createCheckBoxControl(QString name, QString label);
    QRadioButton* createRadioButtonControl(QString name, QString label);
    QToolButton* createToolButtonControl(QString name, QString label, QObject* receiver = 0, const char* signal_or_slot = 0);

    void updateControlsOn(QObject* sender, const char* signal);

private slots:
    void slot_controls_changed();

private:
    MVAbstractControlPrivate* d;
};

#endif // MVABSTRACTCONTROL_H
