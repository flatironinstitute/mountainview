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

#include "clusterdetailplugin.h"

#include <clusterdetailview.h>

class ClusterDetailPluginPrivate {
public:
    ClusterDetailPlugin* q;
};

ClusterDetailPlugin::ClusterDetailPlugin()
{
    d = new ClusterDetailPluginPrivate;
    d->q = this;
}

ClusterDetailPlugin::~ClusterDetailPlugin()
{
    delete d;
}

QString ClusterDetailPlugin::name()
{
    return "ClusterDetail";
}

QString ClusterDetailPlugin::description()
{
    return "View the average waveform and other details for each cluster";
}

void ClusterDetailPlugin::initialize(MVMainWindow* mw)
{
    mw->registerViewFactory(new ClusterDetailFactory(mw));
}

ClusterDetailFactory::ClusterDetailFactory(MVMainWindow* mw, QObject* parent)
    : MVAbstractViewFactory(mw, parent)
{
}

QString ClusterDetailFactory::id() const
{
    return QStringLiteral("open-cluster-details");
}

QString ClusterDetailFactory::name() const
{
    return tr("Cluster Detail");
}

QString ClusterDetailFactory::title() const
{
    return tr("Detail");
}

MVAbstractView* ClusterDetailFactory::createView(MVAbstractContext* context)
{
    ClusterDetailView* X = new ClusterDetailView(context);
    return X;
}
