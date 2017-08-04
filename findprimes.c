#include <stdio.h>
#include <math.h>
//#include "mpi.h"
#define N 100+1

int main(int argc,char **argv)
{
    int i,j,k,rank,size,array[N];
    int p=2,q=3,r=5,s=7;

    array[0]=0;
    array[1]=0;
    for(i=2;i<N;i++)
    {
        array[i]=i;
    }

    /*MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);*/

    for(j=2;j<sqrt(N-1);j++)
    {
        if(array[j]>0)
        {
            for(k=j*2;k<N;k+=j)
            {
                array[k]=0;
            }
        }

    }

    for(i=2;i<N;i++)
    {
        if(array[i]==0)
        {
            printf("- ");
        }
        else
        {
            printf("%d ",array[i]);
        }
    }

    return 0;
}
