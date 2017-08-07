#include <stdio.h>
#include <math.h>
#include <time.h>
#include "mpi.h"
#define N 10000+1

int main(int argc,char **argv)
{
    clock_t start,end;                       //initialize clock

    int i,j,k,l,rank,size,array[N];         //creating counters and array
    double total,total1[17];

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
        for(j=2;j<((sqrt(N-1)/16)+0.75);j++)        //2 to 6
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
    {                                         //if in node 2
        start=clock();
        for(j=((sqrt(N-1)/16)+0.75);j<((sqrt(N-1)/8)+0.5);j++)        //7 to 12
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
        total1[1]=(double)(end-start)/CLOCKS_PER_SEC;
    }


    if(rank==2)
    {                                               //if in node 3
        start=clock();
        for(j=((sqrt(N-1)/8)+0.5);j<((sqrt(N-1)*(3/16))+0.25);j++)    //13 to 18
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
        for(j=((sqrt(N-1)*(3/16))+0.25);j<(sqrt(N-1)/4);j++)    //19 to 24
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
        for(j=(sqrt(N-1)/4);j<((sqrt(N-1)*(5/16))+0.75);j++)    //25 to 31
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
        for(j=((sqrt(N-1)*(5/16))+0.75);j<((sqrt(N-1)*(3/8))+0.5);j++)    //32 to 37
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
        for(j=((sqrt(N-1)*(3/8))+0.5);j<((sqrt(N-1)*(7/16))+0.25);j++)    //38 to 43
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
        for(j=((sqrt(N-1)*(7/16))+0.25);j<((sqrt(N-1)/2));j++)    //44 to 49
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

    if(rank==8)
    {                                               //if in node 9
        start=clock();
        for(j=((sqrt(N-1)/2));j<((sqrt(N-1)*(9/16))+0.75);j++)    //50 to 56
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
        total1[8]=(double)(end-start)/CLOCKS_PER_SEC;
    }

    if(rank==9)
    {                                               //if in node 10
        start=clock();
        for(j=((sqrt(N-1)*(9/16))+0.75);j<((sqrt(N-1)*(5/8))+0.5);j++)    //57 to 62
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
        total1[9]=(double)(end-start)/CLOCKS_PER_SEC;
    }

    if(rank==10)
    {                                               //if in node 11
        start=clock();
        for(j=((sqrt(N-1)*(5/8))+0.5);j<((sqrt(N-1)*(11/16))+0.25);j++)    //63 to 68
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
        total1[10]=(double)(end-start)/CLOCKS_PER_SEC;
    }

    if(rank==11)
    {                                               //if in node 12
        start=clock();
        for(j=((sqrt(N-1)*(11/16))+0.25);j<(sqrt(N-1)*(3/4));j++)    //69 to 74
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
        total1[11]=(double)(end-start)/CLOCKS_PER_SEC;
    }
    if(rank==12)
    {                                               //if in node 13
        start=clock();
        for(j=(sqrt(N-1)*(3/4));j<((sqrt(N-1)*(13/16))+0.75);j++)    //75 to 81
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
        total1[12]=(double)(end-start)/CLOCKS_PER_SEC;
    }
    if(rank==13)
    {                                               //if in node 14
        start=clock();
        for(j=((sqrt(N-1)*(13/16))+0.75);j<((sqrt(N-1)*(7/8))+1.5);j++)    //82 to 88
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
        total1[13]=(double)(end-start)/CLOCKS_PER_SEC;
    }

    if(rank==14)
    {                                               //if in node 15
        start=clock();
        for(j=((sqrt(N-1)*(7/8))+1.5);j<((sqrt(N-1)*(15/16))+0.25);j++)    //89 to 93
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
        total1[14]=(double)(end-start)/CLOCKS_PER_SEC;
    }

    if(rank==15)
    {                                               //if in node 16
        start=clock();
        for(j=((sqrt(N-1)*(15/16))+0.25);j<=(sqrt(N-1));j++)    //94 to 100
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
        total1[15]=(double)(end-start)/CLOCKS_PER_SEC;
    }
    total=-1000000;

    for(i=0;i<=15;i++)
    {
        if(total1[i]>total)
        {
            total=(double)total1[i];
        }
    }


    if(rank==7)
    {
        printf("1. Find prime numbers:\n\n");
        printf("16 processes:\n\n");
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
