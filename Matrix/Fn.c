#include <stdio.h>
#include <stdlib.h>

double** mat_alloc(int r, int c)
{
    int i;
    double **m = (double**)malloc(r * sizeof(double*));
    if (m == NULL) return NULL;

    for (i = 0; i < r; i++)
    {
        m[i] = (double*)malloc(c * sizeof(double));
        if (m[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(m[j]);
            free(m);
            return NULL;
        }
    }
    return m;
}

// Free matrix
void mat_free(double **m, int r)
{
    for (int i = 0; i < r; i++)
        free(m[i]);
    free(m);
}

// Input matrix
void mat_input(double **m, int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%lf", &m[i][j]);
}

// Print matrix
void mat_print(double **m, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%.2lf ", m[i][j]);
        printf("\n");
    }
}

// Addition
double** mat_add(double **A, double **B, int r, int c)
{
    double **C = mat_alloc(r, c);
    if (!C) return NULL;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            C[i][j] = A[i][j] + B[i][j];

    return C;
}

// Subtraction
double** mat_sub(double **A, double **B, int r, int c)
{
    double **C = mat_alloc(r, c);
    if (!C) return NULL;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            C[i][j] = A[i][j] - B[i][j];

    return C;
}

// Multiplication
double** mat_mul(double **A, double **B, int rA, int cA, int cB)
{
    double **C = mat_alloc(rA, cB);
    if (!C) return NULL;

    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            C[i][j] = 0.0;
            for (int k = 0; k < cA; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    return C;
}

// Transpose
double** mat_transpose(double **A, int r, int c)
{
    double **T = mat_alloc(c, r);
    if (!T) return NULL;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            T[j][i] = A[i][j];

    return T;
}

int main()
{
    int rA, cA, rB, cB;
    double **A, **B, **C;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &rA, &cA);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &rB, &cB);

    A = mat_alloc(rA, cA);
    B = mat_alloc(rB, cB);

    if (!A || !B)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements of Matrix A:\n");
    mat_input(A, rA, cA);

    printf("Enter elements of Matrix B:\n");
    mat_input(B, rB, cB);

    // Addition & Subtraction check
    if (rA == rB && cA == cB)
    {
        printf("\nAddition:\n");
        C = mat_add(A, B, rA, cA);
        mat_print(C, rA, cA);
        mat_free(C, rA);

        printf("\nSubtraction:\n");
        C = mat_sub(A, B, rA, cA);
        mat_print(C, rA, cA);
        mat_free(C, rA);
    }
    else
    {
        printf("\nAddition/Subtraction not possible (dimension mismatch)\n");
    }

    // Multiplication check 
    if (cA == rB)
    {
        printf("\nMultiplication:\n");
        C = mat_mul(A, B, rA, cA, cB);
        mat_print(C, rA, cB);
        mat_free(C, rA);
    }
    else
    {
        printf("\nMultiplication not possible (cA != rB)\n");
    }

    // Transpose A
    printf("\nTranspose of Matrix A:\n");
    C = mat_transpose(A, rA, cA);
    mat_print(C, cA, rA);
    mat_free(C, cA);

    mat_free(A, rA);
    mat_free(B, rB);

    return 0;
}