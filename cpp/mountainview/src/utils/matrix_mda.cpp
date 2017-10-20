#include "matrix_mda.h"

Mda matrix_transpose(const Mda& A)
{
    Mda ret(A.N2(), A.N1());
    for (int i = 0; i < A.N1(); i++) {
        for (int j = 0; j < A.N2(); j++) {
            ret.set(A.get(i, j), j, i);
        }
    }
    return ret;
}

Mda matrix_multiply(const Mda& A, const Mda& B)
{
    int N1 = A.N1();
    int N2 = A.N2();
    int N2B = B.N1();
    int N3 = B.N2();
    if (N2 != N2B) {
        qWarning() << "Unexpected problem in matrix_multiply" << N1 << N2 << N2B << N3;
        exit(-1);
    }
    Mda ret(N1, N3);
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N3; j++) {
            double val = 0;
            for (int k = 0; k < N2; k++) {
                val += A.get(i, k) * B.get(k, j);
            }
            ret.set(val, i, j);
        }
    }
    return ret;
}

void matrix_print(const Mda& A)
{
    for (int r = 0; r < A.N1(); r++) {
        for (int c = 0; c < A.N2(); c++) {
            printf("%g ", A.get(r, c));
        }
        printf("\n");
    }
}
