/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 5/23/2016
*******************************************************/

#ifndef CLUSTERMERGE
#define CLUSTERMERGE

#include <QJsonObject>
#include <QMap>
#include <QSet>

class ClusterMergePrivate;
class ClusterMerge {
public:
    friend class ClusterMergePrivate;
    ClusterMerge();
    ClusterMerge(const ClusterMerge& other);
    virtual ~ClusterMerge();
    void operator=(const ClusterMerge& other);
    bool operator==(const ClusterMerge& other) const;
    void clear();
    void merge(const QSet<int>& labels);
    void merge(const QList<int>& labels);
    void unmerge(int label);
    void unmerge(const QSet<int>& labels);
    void unmerge(const QList<int>& labels);

    int representativeLabel(int label) const;
    QList<int> representativeLabels() const;
    QList<int> getMergeGroup(int label) const;
    void setFromJsonObject(QJsonObject obj);
    QJsonObject toJsonObject() const;
    QString toJson() const;
    QMap<int, int> labelMap(int K) const;
    QVector<int> mapLabels(const QVector<int>& labels) const;

    QString clusterLabelText(int label);

    static ClusterMerge fromJson(const QString& json);

private:
    ClusterMergePrivate* d;
};

#endif // CLUSTERMERGE
