#ifndef JSVM_H
#define JSVM_H

#include "svm.h"

#include <QVector>
#include <mda32.h>

//labels should be 1 and 2
bool get_svm_discrim_direction(double& cutoff, QVector<double>& direction, const Mda32& X, const QVector<int>& labels);

#endif // JSVM_H
