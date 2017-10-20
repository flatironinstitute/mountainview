/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/5/2016
*******************************************************/

#ifndef GUIDEV1
#define GUIDEV1

#include <QWizard>
#include <mvcontext.h>
#include <mvmainwindow.h>

class GuideV1Private;
class GuideV1 : public QWizard {
    Q_OBJECT
public:
    friend class GuideV1Private;
    GuideV1(MVContext* mvcontext, MVMainWindow* mw);
    virtual ~GuideV1();

private slots:
    void slot_button_clicked();
    void slot_next_channel(int offset = 1);
    void slot_previous_channel();
    void slot_cluster_channel_matrix_computed();

private:
    GuideV1Private* d;
};

#endif // GUIDEV1
