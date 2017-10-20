/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 10/1/2016
*******************************************************/
#ifndef RESOLVEPRVSDIALOG_H
#define RESOLVEPRVSDIALOG_H

#include <QDialog>

class ResolvePrvsDialogPrivate;
class ResolvePrvsDialog : public QDialog {
    Q_OBJECT
public:
    enum Choice {
        OpenPrvGui,
        AutomaticallyDownloadAndRegenerate,
        ProceedAnyway
    };

    friend class ResolvePrvsDialogPrivate;
    ResolvePrvsDialog();
    virtual ~ResolvePrvsDialog();
    Choice choice() const;

private:
    ResolvePrvsDialogPrivate* d;
};

#endif // RESOLVEPRVSDIALOG_H
