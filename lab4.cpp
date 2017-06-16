#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <mpi.h>
                                                                                                                                                     
using namespace std;
                                                                                                                                                     
int main(int argc, char** argv)
{                                                                                                                                                    
                                                                                                                                                     
  MPI_Init(&argc, &argv);                                                                                                                            
                                                                                                                                                     
  //  int world_size;     
  //  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
                                                                                                                                                     
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);                                                                                                        
                                                                                                                                                     
                                                                                                                                                     
  printf("Process: %i ", world_rank);
                                                                                                                                                     
  clock_t tstart = clock(), tend;
                                                                                                                                                     
  if (argc<2)
  {                                                                                                                                                  
    printf("Empty params. Need 1 arg.");
    return 0;
  }                                                                                                                             

unsigned long long int num = atof(argv[(1+world_rank)]);
  unsigned long long int  i = 2;
                                                                                                                                                     
  printf("Num: %i = ", num);
                                                                                                                                                     
  while (i <= num)
  {                                                                                                                                                  
    if (num%i == 0)
    {                                                                                                                                                
      printf("%d", i);
      num = num / i;                                                                                                                                 
      if (num>1)
      {                                                                                                                                              
        printf("*");
      }                                                                                                                                              
    }                                                                                                                                                
    else
    {                                                                                                                                                
      i = i + 1;
    }                                                                                                                                                
                                                                                                                                                     
  }                                                                                                                                                  
                                                                                                                                                     
  tend = clock() - tstart;                                                                                                                           
  double timeexec = (double)tend / (double)CLOCKS_PER_SEC;
  printf("Time: %.6f \n", timeexec);
  MPI_Finalize();                                                                                                                                    
}                                                                                                                                               
                                                                                                                                                                                                                                               