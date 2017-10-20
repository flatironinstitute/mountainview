/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 10/25/2016
*******************************************************/
#ifndef ClusterDetailViewPropertiesDialog_H
#define ClusterDetailViewPropertiesDialog_H

#include <QDialog>

struct ClusterDetailViewProperties {
    int cluster_number_font_size = 12;
    int export_image_width = 2000;
    int export_image_height = 800;
};

class ClusterDetailViewPropertiesDialogPrivate;
class ClusterDetailViewPropertiesDialog : public QDialog {
    Q_OBJECT
public:
    friend class ClusterDetailViewPropertiesDialogPrivate;
    ClusterDetailViewPropertiesDialog();
    virtual ~ClusterDetailViewPropertiesDialog();
    void setProperties(ClusterDetailViewProperties properties);
    ClusterDetailViewProperties properties() const;
private slots:
    void slot_update_enabled();

private:
    ClusterDetailViewPropertiesDialogPrivate* d;
};

#endif // ClusterDetailViewPropertiesDialog_H
