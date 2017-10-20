#include "eigenvalue_decomposition.h"
#include <QDebug>
#include <QTime>

/*
#define HAVE_LAPACK_CONFIG_H
#define LAPACK_COMPLEX_CPP
bool eigenvalue_decomposition_sym(Mda& U, Mda& S, Mda& X)
{
    //X=U*diag(S)*U'
    //X is MxM, U is MxM, S is 1xM
    //X must be real and symmetric

    int M = X.N1();
    if (M != X.N2()) {
        qWarning() << "Unexpected problem in eigenvalue_decomposition_sym" << X.N1() << X.N2();
        exit(-1);
    }

    U.allocate(M, M);
    S.allocate(1, M);
    double* Uptr = U.dataPtr();
    double* Sptr = S.dataPtr();
    double* Xptr = X.dataPtr();

    for (int ii = 0; ii < M * M; ii++) {
        Uptr[ii] = Xptr[ii];
    }

    //'V' means compute eigenvalues and eigenvectors (use 'N' for eigenvalues only)
    //'U' means upper triangle of A is stored.
    //QTime timer; timer.start();
    int info=LAPACKE_dsyevd(LAPACK_COL_MAJOR,'V','U',M,Uptr,M,Sptr);

    //printf("Time for call to LAPACKE_dsyev: %g sec\n",timer.elapsed()*1.0/1000);
    if (info != 0) {
        qWarning() << "Error in LAPACKE_dsyev" << info;
        return false;
    }
    return true;
}
*/
