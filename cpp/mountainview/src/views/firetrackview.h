/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/12/2016
*******************************************************/

#ifndef FIRETRACKVIEW_H
#define FIRETRACKVIEW_H

#include <mvabstractview.h>
#include <mvabstractviewfactory.h>

class FireTrackViewPrivate;
class FireTrackView : public MVAbstractView {
public:
    friend class FireTrackViewPrivate;
    FireTrackView(MVAbstractContext* context);
    virtual ~FireTrackView();

protected:
    void prepareCalculation() Q_DECL_OVERRIDE;
    void runCalculation() Q_DECL_OVERRIDE;
    void onCalculationFinished() Q_DECL_OVERRIDE;

private:
    FireTrackViewPrivate* d;
};

class MVFireTrackFactory : public MVAbstractViewFactory {
    Q_OBJECT
public:
    MVFireTrackFactory(MVMainWindow* mw, QObject* parent = 0);
    QString id() const Q_DECL_OVERRIDE;
    QString name() const Q_DECL_OVERRIDE;
    QString title() const Q_DECL_OVERRIDE;
    MVAbstractView* createView(MVAbstractContext* context) Q_DECL_OVERRIDE;
};

#endif // FIRETRACKVIEW_H
