/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 10/25/2016
*******************************************************/

#include "mvgridviewpropertiesdialog.h"
#include "ui_mvgridviewpropertiesdialog.h"

class MVGridViewPropertiesDialogPrivate {
public:
    MVGridViewPropertiesDialog* q;
    Ui_MVGridPropertiesDialog ui;
    MVGridViewProperties m_properties;
};

MVGridViewPropertiesDialog::MVGridViewPropertiesDialog()
{
    d = new MVGridViewPropertiesDialogPrivate;
    d->q = this;

    d->ui.setupUi(this);
    QObject::connect(d->ui.use_fixed_number_of_columns, SIGNAL(clicked(bool)), this, SLOT(slot_update_enabled()));
    QObject::connect(d->ui.use_fixed_panel_sizes, SIGNAL(clicked(bool)), this, SLOT(slot_update_enabled()));
}

MVGridViewPropertiesDialog::~MVGridViewPropertiesDialog()
{
    delete d;
}

MVGridViewProperties MVGridViewPropertiesDialog::properties() const
{
    d->m_properties.use_fixed_panel_size = d->ui.use_fixed_panel_sizes->isChecked();
    d->m_properties.use_fixed_number_of_columns = d->ui.use_fixed_number_of_columns->isChecked();
    d->m_properties.fixed_panel_width = d->ui.fixed_panel_width->text().toInt();
    d->m_properties.fixed_panel_height = d->ui.fixed_panel_height->text().toInt();
    d->m_properties.fixed_number_of_columns = d->ui.fixed_number_of_columns->text().toInt();
    d->m_properties.font_size = d->ui.font_size->text().toInt();
    return d->m_properties;
}

void MVGridViewPropertiesDialog::slot_update_enabled()
{
    d->ui.fixed_panel_width->setEnabled(d->ui.use_fixed_panel_sizes->isChecked());
    d->ui.fixed_panel_height->setEnabled(d->ui.use_fixed_panel_sizes->isChecked());
    d->ui.fixed_number_of_columns->setEnabled(d->ui.use_fixed_number_of_columns->isChecked());
}

void MVGridViewPropertiesDialog::setProperties(MVGridViewProperties properties)
{
    d->m_properties = properties;
    d->ui.use_fixed_panel_sizes->setChecked(properties.use_fixed_panel_size);
    d->ui.use_fixed_number_of_columns->setChecked(properties.use_fixed_number_of_columns);
    d->ui.fixed_panel_width->setText(QString("%1").arg(properties.fixed_panel_width));
    d->ui.fixed_panel_height->setText(QString("%1").arg(properties.fixed_panel_height));
    d->ui.fixed_number_of_columns->setText(QString("%1").arg(properties.fixed_number_of_columns));
    d->ui.font_size->setText(QString("%1").arg(properties.font_size));
    slot_update_enabled();
}
