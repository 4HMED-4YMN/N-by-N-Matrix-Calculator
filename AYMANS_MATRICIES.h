
#include <iostream>
#include <cmath>

using namespace std;

const int max_col=10;

int det_2 ( int arr [max_col][max_col]);

//|X|
long long det_NxN ( int arr [][max_col], const int size);

const int mcols=10; //MAX COLUMN LENGTH
//AxB
void mat_multiply(const int a[][mcols],const int b[][mcols],int Brow_Acol,int res_rows,int res_cols);

//A+B
void mat_add_or_sub (const int a[][mcols],const int b[][mcols],int rows,int cols, char op);

void cofactors (int arr[][mcols],int size);

void adjoint (int arr[][mcols],int size);

//A*(inverse B)
void mat_div(int matA[][10], int matB[][10],int Brow_Acol,int res_rows,int res_cols);


