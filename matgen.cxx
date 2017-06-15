#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
void generate(int n, int m, int max_threads) {
        int** A = new int*[n];
        for (int i = 0; i < n; i++)
        {                                                                                                                                                                                                                                                                                                  
                A[i] = new int[m];
        }                                                                                                                                                                                                                                                                                                  
        for (int i = 0; i < n; i++)
        {                                                                                                                                                                                                                                                                                                  
                for (int j = 0; j < m; j++)
                {                                                                                                                                                                                                                                                                                          
                        A[i][j] = rand() % 1000;
                }                                                                                                                                                                                                                                                                                          
        }                                                                                                                                                                                                                                                                                                  
        ofstream* fileArray = new ofstream[max_threads];
                                                                                                                                                                                                                                                                                                           
        for (int i = 0; i < max_threads; i++)
        {                                                                                                                                                                                                                                                                                                  
                char file[30];
                snprintf(file, sizeof(file), "%s%d%s", "in",i+1, ".txt");
                fileArray[i].open(file);                                                                                                                                                                                                                                                                   
                int s = (float(n) / float(max_threads)) * i;
                int e = (float(n) / float(max_threads)) * (i + 1);
                for (int k = s; k < e; k++)
                {                                                                                                                                                                                                                                                                                          
                        for (int j = 0; j < m; j++)
                        {                                                                                                                                                                                                                                                                                  
                                fileArray[i] << A[k][j] << " ";
                        }                                                                                                                                                                                                                                                                                  
                        fileArray[i] << endl;                                                                                                                                                                                                                                                              
                }                                                                                                                                                                                                                                                                                          
                fileArray[i].close();                                                                                                                                                                                                                                                                      
        }                                                                                                                                                                                                                                                                                                  
        delete[] fileArray;
        for (int i = 0; i < n; i++)
        {                                                                                                                                                                                                                                                                                                  
                delete[] A[i];
        }                                                                                                                                                                                                                                                                                                  
        delete[] A;
}                                                                                                                                                                                                                                                                                                          
int main(int argc, char* argv[]) {
        srand(time(NULL));
        double start, end;
        int max_threads = atoi(argv[1]);
        int n = atoi(argv[2]);
        int m = atoi(argv[3]);
        ofstream file;                                                                                                                                                                                                                                                                                     
        file.open("meta.txt");
        file << max_threads << endl;                                                                                                                                                                                                                                                                       
        file << n << endl;                                                                                                                                                                                                                                                                                 
        file << m << endl;                                                                                                                                                                                                                                                                                 
        file.close();                                                                                                                                                                                                                                                                                      
        generate(n, m, max_threads);                                                                                                                                                                                                                                                                       
}