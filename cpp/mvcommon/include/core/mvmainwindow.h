/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
*******************************************************/

#ifndef MVMAINWINDOW_H
#define MVMAINWINDOW_H

#include <QWidget>
#include <QMimeData>
#include <QTabWidget>
#include "mvutils.h"
#include "mvabstractcontext.h"
#include "mvabstractcontrol.h"
#include "mvabstractview.h"
#include "mvabstractplugin.h"

class MVAbstractViewFactory;
class TabberTabWidget;
class Tabber;
class MVAbstractContextMenuHandler;

class MVMainWindowPrivate;
class MVMainWindow : public QWidget {
    Q_OBJECT
public:
    enum RecalculateViewsMode {
        All,
        AllVisible,
        Suggested,
        SuggestedVisible
    };

    friend class MVMainWindowPrivate;
    MVMainWindow(MVAbstractContext* context, QWidget* parent = 0);
    virtual ~MVMainWindow();

    //The context
    MVAbstractContext* mvContext() const;

    //Plugins
    void loadPlugin(MVAbstractPlugin* P);
    QStringList loadedPluginNames();
    MVAbstractPlugin* loadedPlugin(QString name);

    //View factories
    void registerViewFactory(MVAbstractViewFactory* f);
    void unregisterViewFactory(MVAbstractViewFactory* f);
    const QList<MVAbstractViewFactory*>& viewFactories() const;

    //Context menu handlers
    void registerContextMenuHandler(MVAbstractContextMenuHandler* h);
    void unregisterContextMenuHandler(MVAbstractContextMenuHandler* h);
    const QList<MVAbstractContextMenuHandler*>& contextMenuHandlers() const;

    //Controls
    void insertControl(int position, MVAbstractControl* control, bool start_expanded);
    void addControl(MVAbstractControl* control, bool start_expanded);

    //Manage views
    void openView(const QString& id);
    void setCurrentContainerName(const QString& name);
    void closeAllViews();
    QList<MVAbstractView*> allViews();
    void recalculateViews(RecalculateViewsMode mode);

    //Export
    QJsonObject exportStaticViews() const;

public slots:
    void slotCloseAllViews();

signals:
    void viewsChanged();

protected:
    void resizeEvent(QResizeEvent* evt);

signals:

public slots:

private slots:
    void slot_pop_out_widget();
    /// TODO: (HIGH) cluster curation guide doesn't belong in main window
    void slot_cluster_curation_guide();
    void slot_guide_v1();
    void slot_guide_v2();

    void slot_open_view(QObject*);
    void handleContextMenu(const QMimeData& dt, const QPoint& globalPos);

private:
    MVMainWindowPrivate* d;
};

#endif // MVMAINWINDOW_H
