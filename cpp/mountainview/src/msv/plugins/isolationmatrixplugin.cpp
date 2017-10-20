/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 8/24/2016
*******************************************************/

#include "isolationmatrixplugin.h"

#include "isolationmatrixview.h"

class IsolationMatrixPluginPrivate {
public:
    IsolationMatrixPlugin* q;
};

IsolationMatrixPlugin::IsolationMatrixPlugin()
{
    d = new IsolationMatrixPluginPrivate;
    d->q = this;
}

IsolationMatrixPlugin::~IsolationMatrixPlugin()
{
    delete d;
}

QString IsolationMatrixPlugin::name()
{
    return "IsolationMatrix";
}

QString IsolationMatrixPlugin::description()
{
    return "";
}

void IsolationMatrixPlugin::initialize(MVMainWindow* mw)
{
    mw->registerViewFactory(new IsolationMatrixFactory(mw));
}

IsolationMatrixFactory::IsolationMatrixFactory(MVMainWindow* mw, QObject* parent)
    : MVAbstractViewFactory(mw, parent)
{
}

QString IsolationMatrixFactory::id() const
{
    return QStringLiteral("open-isolation-matrix");
}

QString IsolationMatrixFactory::name() const
{
    return tr("Isolation Matrix");
}

QString IsolationMatrixFactory::title() const
{
    return tr("Isolation Matrix");
}

MVAbstractView* IsolationMatrixFactory::createView(MVAbstractContext* context)
{
    MVContext* c = qobject_cast<MVContext*>(context);
    Q_ASSERT(c);
    IsolationMatrixView* X = new IsolationMatrixView(c);
    return X;
}
