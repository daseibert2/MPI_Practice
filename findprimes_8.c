#include <stdio.h>
#include <math.h>
#include <time.h>
#include "mpi.h"
#define N 10000+1

int main(int argc,char **argv)
{
    clock_t start,end;                       //initialize clock

    int i,j,k,l,rank,size,array[N];         //creating counters and array
    double total,total1[9];

    array[0]=0;
    array[1]=0;                             //filling array
    for(l=2;l<N;l++)
    {
        array[l]=l;
    }

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if(rank==0)
    {                                         //if in first node
        start=clock();
        for(j=2;j<((sqrt(N-1)/8)+1.5);j++)        //2 to 13
        {
            if(array[j]>0)                  //if unassigned
            {
                for(k=j*2;k<N;k+=j)         //2j,2j+j,2j+2j,...
                {
                    array[k]=0;             //reassign to 0
                }
            }

        }
        end=clock();
        total1[0]=(double)(end-start)/CLOCKS_PER_SEC;
    }


    if(rank==1)
    {                                               //if in node 2
        start=clock();
        for(j=((sqrt(N-1)/8)+1.5);j<((sqrt(N-1)/4)+2);j++)    //14 to 26
        {
            if(array[j]>0)                      //if unassigned
            {
                for(k=j*2;k<N;k+=j)             //2j,2j+j,2j+2j,...
                {
                    array[k]=0;                 //reassign to 0
                }
            }

        }
        end=clock();
        total1[1]=(double)(end-start)/CLOCKS_PER_SEC;
    }

    if(rank==2)
    {                                               //if in node 3
        start=clock();
        for(j=((sqrt(N-1)/4)+2);j<((sqrt(N-1)*(3/8))+1.5);j++)    //27 to 38
        {
            if(array[j]>0)                      //if unassigned
            {
                for(k=j*2;k<N;k+=j)             //2j,2j+j,2j+2j,...
                {
                    array[k]=0;                 //reassign to 0
                }
            }

        }
        end=clock();
        total1[2]=(double)(end-start)/CLOCKS_PER_SEC;
    }
    if(rank==3)
    {                                               //if in node 4
        start=clock();
        for(j=((sqrt(N-1)*(3/8))+1.5);j<((sqrt(N-1)/2)+2);j++)    //39 to 51
        {
            if(array[j]>0)                      //if unassigned
            {
                for(k=j*2;k<N;k+=j)             //2j,2j+j,2j+2j,...
                {
                    array[k]=0;                 //reassign to 0
                }
            }

        }
        end=clock();
        total1[3]=(double)(end-start)/CLOCKS_PER_SEC;
    }
    if(rank==4)
    {                                               //if in node 5
        start=clock();
        for(j=((sqrt(N-1)/2)+2);j<((sqrt(N-1)*(5/8))+1.5);j++)    //52 to 63
        {
            if(array[j]>0)                      //if unassigned
            {
                for(k=j*2;k<N;k+=j)             //2j,2j+j,2j+2j,...
                {
                    array[k]=0;                 //reassign to 0
                }
            }

        }
        end=clock();
        total1[4]=(double)(end-start)/CLOCKS_PER_SEC;
    }
    if(rank==5)
    {                                               //if in node 6
        start=clock();
        for(j=((sqrt(N-1)*(5/8))+1.5);j<((sqrt(N-1)*(3/4))+2);j++)    //63 to 76
        {
            if(array[j]>0)                      //if unassigned
            {
                for(k=j*2;k<N;k+=j)             //2j,2j+j,2j+2j,...
                {
                    array[k]=0;                 //reassign to 0
                }
            }

        }
        end=clock();
        total1[5]=(double)(end-start)/CLOCKS_PER_SEC;
    }
    if(rank==6)
    {                                               //if in node 7
        start=clock();
        for(j=((sqrt(N-1)*(3/4))+2);j<((sqrt(N-1)*(7/8))+1.5);j++)    //77 to 88
        {
            if(array[j]>0)                      //if unassigned
            {
                for(k=j*2;k<N;k+=j)             //2j,2j+j,2j+2j,...
                {
                    array[k]=0;                 //reassign to 0
                }
            }

        }
        end=clock();
        total1[6]=(double)(end-start)/CLOCKS_PER_SEC;
    }
    if(rank==7)
    {                                               //if in node 8
        start=clock();
        for(j=((sqrt(N-1)*(7/8))+1.5);j<=(sqrt(N-1));j++)    //89 to 100
        {
            if(array[j]>0)                      //if unassigned
            {
                for(k=j*2;k<N;k+=j)             //2j,2j+j,2j+2j,...
                {
                    array[k]=0;                 //reassign to 0
                }
            }

        }
        end=clock();
        total1[7]=(double)(end-start)/CLOCKS_PER_SEC;
    }
    total=-1000000;

    for(i=0;i<=7;i++)
    {
        if(total1[i]>total)
        {
            total=(double)total1[i];
        }
    }


    if(rank==0)
    {
        printf("1. Find prime numbers:\n\n");
        printf("4 processes:\n\n");
        for(i=0;i<N;i++)
        {
            if(array[i]==0)
            {
                printf("- ");                   //if 0, print -
            }
            else
            {
                printf("%d ",array[i]);        //else, print #
            }
        }
        printf("\n\nRuntime: %lf seconds",total);
        printf("\n");
    }

    MPI_Finalize();

    return 0;
}
