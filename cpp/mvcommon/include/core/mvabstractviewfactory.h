#ifndef MVABSTRACTVIEWFACTORY_H
#define MVABSTRACTVIEWFACTORY_H

#include <QWidget>
#include "mvabstractview.h"

class MVMainWindow;
class MVContext;
class MVAbstractViewFactory : public QObject {
    Q_OBJECT
public:
    explicit MVAbstractViewFactory(MVMainWindow* mw, QObject* parent = 0);

    enum PreferredOpenLocation {
        North,
        South,
        Floating,
        NoPreference
    };

    virtual QString id() const = 0;
    virtual QString name() const = 0;
    virtual QString group() const;
    virtual QString toolTip() const;
    virtual QString title() const; /// TODO: move title to the view itself
    virtual PreferredOpenLocation preferredOpenLocation() const;
    virtual int order() const { return 0; }
    virtual bool isEnabled(MVAbstractContext* context) const;

    MVMainWindow* mainWindow();

    virtual MVAbstractView* createView(MVAbstractContext* context) = 0;
    virtual QList<QAction*> actions(const QMimeData& md);
signals:

private:
    MVMainWindow* m_main_window;
    bool m_enabled;
};

#endif // MVABSTRACTVIEWFACTORY_H
