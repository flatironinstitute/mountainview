/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 3/25/2016
*******************************************************/

#ifndef CLOSEMEHANDLER_H
#define CLOSEMEHANDLER_H

#include <QObject>

class CloseMeHandlerPrivate;
class CloseMeHandler : public QObject {
    Q_OBJECT
public:
    friend class CloseMeHandlerPrivate;
    CloseMeHandler();
    virtual ~CloseMeHandler();
    static void start();
private slots:
    void slot_timer();

private:
    CloseMeHandlerPrivate* d;
};

#endif // CLOSEMEHANDLER_H
