/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
*******************************************************/

#ifndef CORRELATIONMATRIXVIEW_H
#define CORRELATIONMATRIXVIEW_H

#include "mda.h"
#include <QWidget>

/**
 * \class CorrelationMatrixView
 * \brief Not used for now.
 *
 * It used to be a valuable view and we may use it again.
 *
 **/

class CorrelationMatrixViewPrivate;
class CorrelationMatrixView : public QWidget {
public:
    friend class CorrelationMatrixViewPrivate;
    CorrelationMatrixView(QWidget* parent = 0);
    virtual ~CorrelationMatrixView();
    void setMatrix(const Mda& CM);

protected:
    void paintEvent(QPaintEvent* evt);
    void mouseMoveEvent(QMouseEvent* evt);

signals:

public slots:

private:
    CorrelationMatrixViewPrivate* d;
};

#endif // CORRELATIONMATRIXVIEW_H
