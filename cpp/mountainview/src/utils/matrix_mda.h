/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
*******************************************************/

#ifndef MATRIX_MDA_H
#define MATRIX_MDA_H

#include "mda.h"

Mda matrix_transpose(const Mda& A);
Mda matrix_multiply(const Mda& A, const Mda& B);
void matrix_print(const Mda& A);

#endif // MATRIX_MDA_H
