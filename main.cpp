//  main.cpp
//  Project 1
//  Nicholas Debeurre 1207169947
//  Professor Xue

#include <fstream>
#include <cstdlib>
#include "foreignsub.h"

using namespace std;

int main()
{
    FILE *fp1;                                                  //creates a pointer to "input.txt"
    FILE *fp2;                                                  //creates a pointer to "output1.txt"
    FILE *fp3;                                                  //creates a pointer to "output2.txt"
    int *A;                                                     //creates a pointer to the first array
    int *B;                                                     //creates a pointer to the second array
    int *C;                                                     //creates a pointer to the third array
    int n;                                                      //creates an int n to store the size of the file
    int ref;                                                    //creates a reference value for error checking in loop
    int temp1, temp2, temp3;                                    //creates temporary variables
    
    fp1 = fopen("input.txt", "r");
    if (fp1 == NULL)
    {
        printf("Error: File does not exist or cannot be opened");
        exit;
    }
    
    fscanf(fp1, "%d", &n);
    A = (int *) malloc (n * sizeof (int));                      //allocates memory of size n for A
    B = (int *) malloc (n * sizeof (int));                      //allocates memory of size n for B
    C = (int *) malloc (n * sizeof (int));                      //allocates memory of size n for C
    
    for (int i = 1; i < n + 1; i++)
    {
        ref = fscanf(fp1, "%d %d %d", &temp1, &temp2, &temp3);   //scans a line of the file and stores the three values in temp variables
        if (ref != 3)
        {
            printf("Invalid line");                             //checks to make sure there are 3 values in each line
        }
        else
        {
            A[i - 1] = temp1;                                   //adds the first number in the line to A
            B[i - 1] = temp2;                                   //adds the second number in the line to B
            C[i - 1] = temp3;                                   //adds the third number in the line to C
        }
    }
    fclose(fp1);
    
    fp2 = fopen("output1.txt", "w");
    if (fp2 == NULL)
    {
        printf("Error: File does not exist or cannot be opened");
        exit;
    }
    
    fprintf(fp2, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        fprintf(fp2, "%d %d %d\n", A[i], B[i], C[i]);
    }
    fclose(fp2);
    
    int result = sub(n, A, B, C);
    
    fp3 = fopen("output2.txt", "w");
    if (fp3 == NULL)
    {
        printf("Error: File does not exist or cannot be opened");
        exit;
    }
    
    fprintf(fp3, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        fprintf(fp3, "%d %d %d\n", A[i], B[i], C[i]);
    }
    fprintf(fp3, "%d", result);
    fclose(fp3);
    
    return 0;
}
