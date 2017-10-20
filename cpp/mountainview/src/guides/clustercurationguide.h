#ifndef CLUSTERANNOTATIONGUIDE_H
#define CLUSTERANNOTATIONGUIDE_H

#include <QWizard>
#include "mvmainwindow.h"

class ClusterCurationGuidePrivate;
class ClusterCurationGuide : public QWizard {
    Q_OBJECT
public:
    friend class ClusterCurationGuidePrivate;
    ClusterCurationGuide(MVContext* mvcontext, MVMainWindow* mw);
    virtual ~ClusterCurationGuide();
signals:
private slots:
    void slot_button_clicked();

private:
    ClusterCurationGuidePrivate* d;
};

#endif // CLUSTERANNOTATIONGUIDE_H
