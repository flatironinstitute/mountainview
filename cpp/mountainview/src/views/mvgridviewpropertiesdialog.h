/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 10/25/2016
*******************************************************/
#ifndef MVGRIDVIEWPROPERTIESDIALOG_H
#define MVGRIDVIEWPROPERTIESDIALOG_H

#include <QDialog>

struct MVGridViewProperties {
    bool use_fixed_panel_size = false;
    bool use_fixed_number_of_columns = false;
    int fixed_panel_width = 600, fixed_panel_height = 350;
    int fixed_number_of_columns = 5;
    int font_size = 14;
    QColor font_color = Qt::blue; // not yet implemented
};

class MVGridViewPropertiesDialogPrivate;
class MVGridViewPropertiesDialog : public QDialog {
    Q_OBJECT
public:
    friend class MVGridViewPropertiesDialogPrivate;
    MVGridViewPropertiesDialog();
    virtual ~MVGridViewPropertiesDialog();
    void setProperties(MVGridViewProperties properties);
    MVGridViewProperties properties() const;
private slots:
    void slot_update_enabled();

private:
    MVGridViewPropertiesDialogPrivate* d;
};

#endif // MVGRIDVIEWPROPERTIESDIALOG_H
