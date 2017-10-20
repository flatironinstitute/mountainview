/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 10/1/2016
*******************************************************/

#include "resolveprvsdialog.h"
#include "ui_resolveprvsdialog.h"

class ResolvePrvsDialogPrivate {
public:
    ResolvePrvsDialog* q;
    Ui_ResolvePrvsDialog ui;
};

ResolvePrvsDialog::ResolvePrvsDialog()
{
    d = new ResolvePrvsDialogPrivate;
    d->q = this;
    d->ui.setupUi(this);
}

ResolvePrvsDialog::~ResolvePrvsDialog()
{
    delete d;
}

ResolvePrvsDialog::Choice ResolvePrvsDialog::choice() const
{
    if (d->ui.open_prv_gui->isChecked())
        return ResolvePrvsDialog::OpenPrvGui;
    else if (d->ui.automatically_download->isChecked())
        return ResolvePrvsDialog::AutomaticallyDownloadAndRegenerate;
    else if (d->ui.proceed_anyway->isChecked())
        return ResolvePrvsDialog::ProceedAnyway;
    else
        return ResolvePrvsDialog::ProceedAnyway;
}
