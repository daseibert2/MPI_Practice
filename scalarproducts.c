#include <stdio.h>
#include <time.h>
#include "mpi.h"
#define N 5000

time_t t;

int main(int argc,char **argv)
{
    int i,rank,size,count1=1,count2=5;
    double a_local[N],b_local[N];
    double s_local,s;

    srand(time(&t));

    for(i=0;i<N;i++)
    {
        /*count1*=3;
        count2+=3;
        a_local[i]=count1;
        b_local[i]=count2;*/
        a_local[i]=rand()%10;
        b_local[i]=rand()%10;
    }

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;

    /*Set the values for the arrays a_local and b_local
      e.g. by reading them from a file*/

    s_local=0;

    if(rank==0)
    {
        for(i=0;i<N/2;i++)
        {
            s_local=s_local+a_local[i]*b_local[i];
        }

        /*Send the local result to rank 1*/
        MPI_Send(&s_local,1,MPI_DOUBLE,1,0,MPI_COMM_WORLD);
        /*Receive data from rank 0*/
        MPI_Recv(&s,1,MPI_DOUBLE,1,0,MPI_COMM_WORLD,&status);
    }

    if(rank==1)
    {
        for(i=N/2;i<N;i++)
        {
            s_local=s_local+a_local[i]*b_local[i];
        }

        MPI_Recv(&s,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD,&status);
        MPI_Send(&s_local,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD);
    }

    /*Calculate global result*/
    s=s+s_local;
    printf("%lf\n",s);
    MPI_Finalize();
    return(0);
}
