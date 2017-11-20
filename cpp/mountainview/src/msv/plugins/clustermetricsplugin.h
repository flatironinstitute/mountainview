/*
 * Copyright 2016-2017 Flatiron Institute, Simons Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
