/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 6/20/2016
*******************************************************/

#ifndef TABBERFRAME_H
#define TABBERFRAME_H

#include "mvabstractview.h"

class TabberFramePrivate;
class TabberFrame : public QWidget {
    Q_OBJECT
public:
    friend class TabberFramePrivate;
    TabberFrame(MVAbstractView* view);
    virtual ~TabberFrame();
    MVAbstractView* view();
    void setContainerName(QString name);
signals:
    void signalMoveToOtherContainer();
    void signalPopOut();
    void signalPopIn();
private slots:
    void slot_update_action_visibility();
    void slot_update_calculating();

private:
    TabberFramePrivate* d;
};

class TabberFrameOverlay : public QWidget {
public:
    QString calculating_message;

protected:
    void paintEvent(QPaintEvent* evt);
};

#endif // TABBERFRAME_H
