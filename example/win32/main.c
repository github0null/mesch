#include "matrix2.h"

/**
 * Here we need to use matrices and matrix factorisations (in particular, a
 * QR factorisation) in order to find the best linear least squares solution
 * to some data.  
 * 
 * Thus in order to solve the (approximate) equations
 *   A*x = b
 * 
*/
int main()
{
    MAT *A, *QR;
    VEC *b, *x, *diag;

    /* read in A matrix */
    printf("Input A matrix:");

    A = m_input(MNULL); /* A has whatever size is input */

    if (A->m < A->n)
    {
        printf("Need m >= n to obtain least squares fit");
        exit(0);
    }
    printf("# A =");
    m_output(A);
    diag = v_get(A->m);

    /* QR is to be the QR factorisation of A */
    QR = m_copy(A, MNULL);
    QRfactor(QR, diag);

    /* read in b vector */
    printf("Input b vector:");
    b = v_get(A->m);
    b = v_input(b);
    printf("# b =");
    v_output(b);

    /* solve for x */
    x = QRsolve(QR, diag, b, VNULL);
    printf("Vector of best fit parameters is");
    v_output(x);
}
