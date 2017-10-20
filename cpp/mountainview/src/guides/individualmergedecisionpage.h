/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 7/7/2016
*******************************************************/

#ifndef INDIVIDUALMERGEDECISIONPAGE_H
#define INDIVIDUALMERGEDECISIONPAGE_H

#include <QWizard>
#include <mvcontext.h>
#include <mvmainwindow.h>

class IndividualMergeDecisionPagePrivate;
class IndividualMergeDecisionPage : public QWizardPage {
    Q_OBJECT
public:
    friend class IndividualMergeDecisionPagePrivate;
    IndividualMergeDecisionPage(MVContext* context, MVMainWindow* mw);
    virtual ~IndividualMergeDecisionPage();
private slots:
    void slot_goto_previous_pair();
    void slot_goto_next_pair();
    void slot_button_clicked();
    void slot_add_merge_candidate_tag();
    void slot_remove_merge_candidate_tag();
    void slot_add_mua_and_reject_tags();
    void slot_update_candidates();

private:
    IndividualMergeDecisionPagePrivate* d;
};

#endif // INDIVIDUALMERGEDECISIONPAGE_H
