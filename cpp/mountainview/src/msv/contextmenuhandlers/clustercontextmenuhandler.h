#ifndef MVCLUSTERCONTEXTMENUHANDLER_H
#define MVCLUSTERCONTEXTMENUHANDLER_H

#include <QObject>
#include "mvabstractcontextmenuhandler.h"

class MVClusterContextMenuHandler : public QObject, public MVAbstractContextMenuHandler {
    Q_OBJECT
public:
    MVClusterContextMenuHandler(MVMainWindow* mw, QObject* parent = 0);

    bool canHandle(const QMimeData& md) const Q_DECL_OVERRIDE;
    QList<QAction*> actions(const QMimeData& md) Q_DECL_OVERRIDE;

private slots:
    void slot_extract_selected_clusters();

private:
    QAction* addTagMenu(const QSet<int>& clusters) const;
    QAction* removeTagMenu(const QSet<int>& clusters) const;
    QStringList validTags() const;
    bool can_unmerge_selected_clusters(MVContext* context, const QSet<int>& clusters);
};

#endif // MVCLUSTERCONTEXTMENUHANDLER_H
