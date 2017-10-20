#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H

#include <QAction>

class ActionFactory {
public:
    enum ActionType {
        ZoomIn,
        ZoomOut,
        ZoomInHorizontal,
        ZoomOutHorizontal,
        ZoomInVertical,
        ZoomOutVertical,
        PanLeft,
        PanRight
    };
    static void addToToolbar(ActionType action, QWidget* container, const char* signalOrSlot)
    {
        addToToolbar(action, container, container, signalOrSlot);
    }
    static void addToToolbar(ActionType action, QWidget* container, QObject* receiver, const char* signalOrSlot);

private:
    ActionFactory();
};

#endif // ACTIONFACTORY_H
