/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 6/27/2016
*******************************************************/

#include "mvcontrolpanel2.h"
#include "qAccordion/qaccordion.h"

#include <QPushButton>
//#include "mlcommon.h"
#include "mvmainwindow.h"

class MVControlPanel2Private {
public:
    MVControlPanel2* q;
    QAccordion* m_accordion;
    QList<MVAbstractControl*> m_controls;
    MVAbstractContext* m_context;
    MVMainWindow* m_main_window;
};

MVControlPanel2::MVControlPanel2(MVAbstractContext* context, MVMainWindow* mw)
{
    d = new MVControlPanel2Private;
    d->q = this;

    d->m_context = context;
    d->m_main_window = mw;

    QHBoxLayout* top_layout = new QHBoxLayout;
    top_layout->setSpacing(20);
    top_layout->setMargin(20);
    {
        QPushButton* B = new QPushButton("Recalc Visible");
        top_layout->addWidget(B);
        QObject::connect(B, SIGNAL(clicked(bool)), this, SLOT(slot_recalc_visible()));
    }
    {
        QPushButton* B = new QPushButton("Recalc All");
        top_layout->addWidget(B);
        QObject::connect(B, SIGNAL(clicked(bool)), this, SLOT(slot_recalc_all()));
    }

    d->m_accordion = new QAccordion;
    d->m_accordion->setMultiActive(true);

    QScrollArea* SA = new QScrollArea;
    SA->setWidget(d->m_accordion);
    SA->setWidgetResizable(true);

    QVBoxLayout* vlayout = new QVBoxLayout;
    vlayout->setSpacing(0);
    vlayout->setMargin(0);
    vlayout->addLayout(top_layout);
    vlayout->addWidget(SA);
    this->setLayout(vlayout);
}

MVControlPanel2::~MVControlPanel2()
{
    delete d;
}

void MVControlPanel2::insertControl(int position, MVAbstractControl* mvcontrol, bool start_open)
{
    if (position < 0)
        d->m_controls << mvcontrol;
    else
        d->m_controls.insert(position, mvcontrol);

    QFrame* frame = new QFrame;
    QHBoxLayout* frame_layout = new QHBoxLayout;
    frame_layout->addWidget(mvcontrol);
    frame->setLayout(frame_layout);
    ContentPane* CP = new ContentPane(mvcontrol->title(), frame);
    CP->setMaximumHeight(1000);
    if (position < 0)
        d->m_accordion->addContentPane(CP);
    else
        d->m_accordion->insertContentPane(position, CP);
    if (start_open) {
        CP->openContentPane();
    }
    mvcontrol->updateControls();
    mvcontrol->updateContext(); //do this so the default values get passed on to the context
}

void MVControlPanel2::addControl(MVAbstractControl* mvcontrol, bool start_open)
{
    insertControl(-1, mvcontrol, start_open);
}

void MVControlPanel2::slot_recalc_visible()
{
    d->m_main_window->recalculateViews(MVMainWindow::SuggestedVisible);
}

void MVControlPanel2::slot_recalc_all()
{
    d->m_main_window->recalculateViews(MVMainWindow::Suggested);
}
