#include "actionfactory.h"

void ActionFactory::addToToolbar(ActionType action, QWidget* container, QObject* receiver, const char* signalOrSlot)
{
    Q_ASSERT(container);
    Q_ASSERT(receiver);
    Q_ASSERT(signalOrSlot);

    QString name;
    QString tooltip;
    QIcon icon;

    switch (action) {
    case ActionType::ZoomIn:
        name = "Zoom In";
        tooltip = "Zoom in.";
        icon = QIcon(":/images/zoom-in.png");
        break;
    case ActionType::ZoomOut:
        name = "Zoom Out";
        tooltip = "Zoom out.";
        icon = QIcon(":/images/zoom-out.png");
        break;
    case ActionType::ZoomInVertical:
        name = "Vertical Zoom In";
        tooltip = "Vertical zoom in.";
        icon = QIcon(":/images/vertical-zoom-in.png");
        break;
    case ActionType::ZoomOutVertical:
        name = "Vertical Zoom Out";
        tooltip = "Vertical zoom out.";
        icon = QIcon(":/images/vertical-zoom-out.png");
        break;
    case ActionType::ZoomInHorizontal:
        name = "Horizontal Zoom In";
        tooltip = "";
        icon = QIcon(":/images/horizontal-zoom-in.png");
        break;
    case ActionType::ZoomOutHorizontal:
        name = "Horizontal Zoom Out";
        tooltip = "";
        icon = QIcon(":/images/horizontal-zoom-out.png");
        break;
    case ActionType::PanLeft:
        name = "Pan left";
        tooltip = "Pan left";
        icon = QIcon(":/images/left.png");
        break;
    case ActionType::PanRight:
        name = "Pan right";
        tooltip = "Pan right";
        icon = QIcon(":/images/right.png");
        break;
    default:
        break;
    }

    QAction* a = new QAction(icon, name, container);
    a->setProperty("action_type", "toolbar");
    a->setToolTip(tooltip);
    container->addAction(a);
    QObject::connect(a, SIGNAL(triggered(bool)), receiver, signalOrSlot);
}
