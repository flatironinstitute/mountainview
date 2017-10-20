#ifndef MVSTATUSBAR_H
#define MVSTATUSBAR_H

#include <QWidget>

class MVStatusBarPrivate;
class MVStatusBar : public QWidget {
    Q_OBJECT
public:
    friend class MVStatusBarPrivate;
    MVStatusBar();
    virtual ~MVStatusBar();
private slots:
    void slot_update_quantities();
    void slot_update_tasks();

private:
    MVStatusBarPrivate* d;
};

#endif // MVSTATUSBAR_H
