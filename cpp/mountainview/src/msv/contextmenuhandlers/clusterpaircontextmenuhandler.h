#ifndef MVCLUSTERPAIRCONTEXTMENUHANDLER_H
#define MVCLUSTERPAIRCONTEXTMENUHANDLER_H

#include <QObject>
#include <mvcontext.h>
#include "mvabstractcontextmenuhandler.h"
#include "mvabstractcontext.h"

class MVClusterPairContextMenuHandler : public QObject, public MVAbstractContextMenuHandler {
public:
    MVClusterPairContextMenuHandler(MVMainWindow* mw, QObject* parent = 0);

    bool canHandle(const QMimeData& md) const Q_DECL_OVERRIDE;
    QList<QAction*> actions(const QMimeData& md) Q_DECL_OVERRIDE;

private:
    QAction* addTagMenu(const QSet<ClusterPair>& cluster_pairs) const;
    QAction* removeTagMenu(const QSet<ClusterPair>& cluster_pairs) const;
    QStringList validTags() const;
};

#endif // MVCLUSTERPAIRCONTEXTMENUHANDLER_H
