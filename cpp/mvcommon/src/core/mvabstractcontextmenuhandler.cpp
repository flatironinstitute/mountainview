#include "mvabstractcontextmenuhandler.h"

MVAbstractContextMenuHandler::MVAbstractContextMenuHandler(MVMainWindow* mw)
{
    m_main_window = mw;
}

MVMainWindow* MVAbstractContextMenuHandler::mainWindow() const
{
    return m_main_window;
}
