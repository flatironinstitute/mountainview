/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
*******************************************************/

#ifndef IMAGESAVEDIALOG_H
#define IMAGESAVEDIALOG_H

#include <QDialog>

class ImageSaveDialogPrivate;
class ImageSaveDialog : public QDialog {
    Q_OBJECT
public:
    friend class ImageSaveDialogPrivate;
    ImageSaveDialog();
    virtual ~ImageSaveDialog();
    static void presentImage(const QImage& img);

    void setImage(const QImage& img);
private slots:
    void slot_save();
    void slot_save_as();
    void slot_cancel();

private:
    ImageSaveDialogPrivate* d;
};

#endif // IMAGESAVEDIALOG_H
