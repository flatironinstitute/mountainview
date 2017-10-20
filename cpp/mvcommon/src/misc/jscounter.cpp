#include "jscounter.h"

JSCounter::JSCounter(const QString& name)
    : IAggregateCounter(name)
{
#if QT_VERSION >= 0x050600
    m_engine.installExtensions(QJSEngine::ConsoleExtension);
#endif
}
