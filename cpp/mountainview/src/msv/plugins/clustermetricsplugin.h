/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 8/24/2016
*******************************************************/
#ifndef ClusterMetricsPLUGIN_H
#define ClusterMetricsPLUGIN_H

#include "mvmainwindow.h"

#include <QThread>

class ClusterMetricsPluginPrivate;
class ClusterMetricsPlugin : public MVAbstractPlugin {
public:
    friend class ClusterMetricsPluginPrivate;
    ClusterMetricsPlugin();
    virtual ~ClusterMetricsPlugin();

    QString name() Q_DECL_OVERRIDE;
    QString description() Q_DECL_OVERRIDE;
    void initialize(MVMainWindow* mw) Q_DECL_OVERRIDE;

private:
    ClusterMetricsPluginPrivate* d;
};

class ClusterMetricsFactory : public MVAbstractViewFactory {
    Q_OBJECT
public:
    ClusterMetricsFactory(MVMainWindow* mw, QObject* parent = 0);
    QString id() const Q_DECL_OVERRIDE;
    QString name() const Q_DECL_OVERRIDE;
    QString title() const Q_DECL_OVERRIDE;
    MVAbstractView* createView(MVAbstractContext* context) Q_DECL_OVERRIDE;
private slots:
    //void openClipsForTemplate();
};

class ClusterPairMetricsFactory : public MVAbstractViewFactory {
    Q_OBJECT
public:
    ClusterPairMetricsFactory(MVMainWindow* mw, QObject* parent = 0);
    QString id() const Q_DECL_OVERRIDE;
    QString name() const Q_DECL_OVERRIDE;
    QString title() const Q_DECL_OVERRIDE;
    MVAbstractView* createView(MVAbstractContext* context) Q_DECL_OVERRIDE;
private slots:
    //void openClipsForTemplate();
};

class basic_metrics_calculator : public QThread {
    Q_OBJECT
public:
    //input
    QString timeseries;
    QString firings;
    double samplerate;

    //output
    QString cluster_metrics_path;
    QString cluster_pair_metrics_path;

    //used in slot_on_finished
    MVContext* mv_context;

    void run();

private slots:
    void slot_on_finished();
};

#endif // ClusterMetricsPLUGIN_H
