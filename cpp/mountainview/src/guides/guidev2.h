/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/5/2016
*******************************************************/

#ifndef GUIDEV2
#define GUIDEV2

#include <QWizard>
#include <mvcontext.h>
#include <mvmainwindow.h>

class GuideV2Private;
class GuideV2 : public QWizard {
    Q_OBJECT
public:
    friend class GuideV2Private;
    GuideV2(MVContext* mvcontext, MVMainWindow* mw);
    virtual ~GuideV2();

private slots:
    void slot_button_clicked();
    void slot_select_merge_candidates();
    void slot_merge_all_merge_candidates();

private:
    GuideV2Private* d;
};

#endif // GuideV2
