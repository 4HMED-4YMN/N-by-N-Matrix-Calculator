#include"AYMANS_MATRICIES.h"



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
int det_2 ( int arr [max_col][max_col])
{

	int res = arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1];

	return res;

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
long long det_NxN ( int arr [][max_col], const int size)
{
	int c;
	long long res = 0 ;
	int temp [10][10];
	 ///A Base CONDITION :)  Finally
	if(size==0)
	{
		return 1;
	}
	if(size==1)
	{
		return arr[0][0];
	}
	if (size==2)
	{
		return det_2(arr);
	}

		for ( c =0 ; c < size ; c++)
		{
			int row1=0,col1=0;

			//create temp_c (sub matrix)

			int ca = c;
			for ( int rt = 0 ; rt < size-1 ; rt++)
			{   row1++;
				col1=0;
				for ( int ct = 0 ; ct < size-1 ; ct++)
				{
					if (col1==ca)
					{
						ct--;
						col1++;
						continue;
					}
					temp[rt][ct]=arr[row1][col1];
					col1++;
				}
			}


			if (c%2==0)
				{
					res=res+arr[0][c]*det_NxN(temp,size-1);
				}
				else
				{
					res=res-arr[0][c]*det_NxN(temp,size-1);
				}
		}

			return res;

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void mat_multiply(const int a[][mcols],const int b[][mcols],int Brow_Acol,int res_rows,int res_cols)
{
    int res [10][10];
    int r,c;
    for (r=0 ; r<res_rows ; r++)
        {
            for( c=0 ; c<res_cols; c++)
            {
                res[r][c]=0; //important

                for(int i=0;i<Brow_Acol;i++)
                {
                    res[r][c] =a[r][i]*b[i][c]+res[r][c];
                }

            }

        }
    for(int i =0 ;i<res_rows;i++)
    {
        for(int j=0;j<res_cols ;j++)
        {
        	cout<<res[i][j]<<" ";
        }

        cout<<"\n";
    }

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void mat_add_or_sub (const int a[][mcols],const int b[][mcols],int rows,int cols, char op)
{
    // matA + matB = matRES

    int res[10][10];
    int r,c ; //loop counters


        //ADDITION
    if(op=='+')
    {
        for (r=0 ; r<rows ; r++)
        {
            for( c=0 ; c<cols ; c++)
                res[r][c]=a[r][c]+b[r][c];
        }
    }

        //SUBTRACTION
    if (op=='-')
    {
        for (r=0 ; r<rows ; r++)
        {
            for( c=0 ; c<cols ; c++)
                res[r][c]=a[r][c] - b[r][c];
        }
    }

        //PRINTING RESULT
    for(int i =0 ;i<rows;i++)
    {
        for(int j=0;j<cols ;j++)
            cout<<res[i][j]<<" ";

        cout<<"\n";
    }

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void cofactors (int arr[][mcols],int size)
{
	int temp[mcols][mcols];
	int cofactor [mcols][mcols];
	int r,c;
	/*****************************************************************/
    // this section creates the sub matrices and gets its determinant
	for (r=0;r<size;r++)
	{
		int ra = r; //actual row

		for ( c =0 ; c < size ; c++)
		{
			int row1=0,col1=0;

			//create temp_r_c (sub matrix)

			int ca = c; //actual column
			for ( int rt = 0 ; rt < size-1 ; rt++)
			{
				if(row1==ra)
				{
					rt--;
					row1++;
					continue;
				}


				col1=0;
				for ( int ct = 0 ; ct < size-1 ; ct++)
				{
					if (col1==ca)
					{
						ct--;
						col1++;
						continue;
					}
					temp[rt][ct]=arr[row1][col1];
					col1++;
				}
				row1++;
			}

			if (r%2==0)
			{
				if (c%2==0)
				{
					cofactor[r][c]=det_NxN(temp,size-1);
				}
				else
				{
					cofactor[r][c]=-1*det_NxN(temp,size-1);
				}
			}
			else
			{
				if (c%2==0)
				{
					cofactor[r][c]=-1*det_NxN(temp,size-1);
				}
				else
				{
					cofactor[r][c]=det_NxN(temp,size-1);
				}
			}
		}
	}
	/*****************************************************************/

	//storing cofactor matrix in arr
	for (r=0;r<size;r++)
	{
		for(c=0;c<size;c++)
		{
			arr[r][c]=cofactor[r][c];
		}
	}

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void adjoint (int arr[][mcols],int size)
{
	int rev [mcols][mcols];

	int r ,c;

    /****************************/
	//create  reverse
	for (r=0;r<size;r++)
	{
		for(c=0;c<size;c++)
		{
			rev[r][c]=arr[c][r];
		}
	}

	/****************************/
	//reverse arr values
	for (r=0;r<size;r++)
	{
		for(c=0;c<size;c++)
		{
			arr[r][c]=rev[r][c];
		}
	}

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void mat_div(int matA[][10], int matB[][10],int Brow_Acol,int res_rows,int res_cols)
{
	double inverse_mat_B[10][10];
	long long det_B;
    //---------------------------------------//
    // 1) get determinant of matB

	det_B=det_NxN(matB,Brow_Acol);


	//---------------------------------------//
	// 2) get matrix of cofactors
	cofactors(matB,Brow_Acol);

	//---------------------------------------//
	// 3) get the adjoint or transpose of cofactors matrix
	adjoint(matB,Brow_Acol);

	//---------------------------------------//
	// 4) get the inverse of matB by multiplying the reciprocal of its determinant by every element of the adjoint matrix
	for(int i =0 ;i<Brow_Acol;i++)
    {
        for(int j=0;j<Brow_Acol;j++)
        	{
        		inverse_mat_B[i][j]=(1.0/det_B)*matB[i][j];
        		//1.0/det_B -> (float/int)=float    I added more 1.0s just to make sure :)
        	}
    }

    //---------------------------------------//
    // 5) Multiplying matA with inverse_mat_B
    double res [10][10];
    int r,c;
    for (r=0 ; r<res_rows ; r++)
        {
            for( c=0 ; c<res_cols; c++)
            {
                res[r][c]=0; //important

                for(int i=0;i<Brow_Acol;i++)
                {
                    res[r][c] =matA[r][i]*inverse_mat_B[i][c]+res[r][c];
                }
            }
        }

    //---------------------------------------//
    // 6) printing the result and rounding the output to the nearest integer
        //using llround() function in cmath library
    for(int i =0 ;i<res_rows;i++)
    {
        for(int j=0;j<res_cols;j++)
        {
            cout<<llround(res[i][j])<<" ";
        }

        cout<<"\n";
    }

}
