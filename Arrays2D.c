/*
Name: Arwin Jasper Johnson
Date: 09/28/2024
Course: CIS 2107 Section 003
Lab 5: Processing 2D Arrays
Project: Processing 2D Arrays: Program to produce and manipulate 2-Dimensional array of
user prompted input to find the sum of the arrays in rows and columns, to find if the 2D array
is a square array, to print the array in a proper manner and to find the max number given in
the array.
*/

#include <stdio.h>

static int rows;
static int columns;
void max(int rows, int columns, int array[rows][columns]);
void rowSum(int rows,int array[rows][columns]);
void columnSum(int columns, int array[rows][columns]);
void isSquare(int rows, int columns);
void displayOutputs(int rows, int columns, int array[rows][columns]);


int main(){
    
    
    
    printf("Let's create a 2Dim array!\n");
    puts("");
    printf("\tHow many rows? ");
    scanf("%d", &rows);
    printf("\tHow many columns? ");
    scanf("%d", &columns);
    printf("\n");
    
    int array[rows][columns];
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("\tenter [%d][%d]: ",i,j);
            scanf("%d", &array[i][j]);
        }
    }
    
    //Calling sum of rows
    rowSum(rows,array);
    
    //Calling function for sum of columns
    columnSum(columns,array);
    puts("\n");
    
    //Checking for square array
    isSquare(rows,columns);
    puts("");
    
    //calling print array
    displayOutputs(rows,columns,array);
    puts("");
    
}

// Finds the maximum value presents in the 2D array
void max(int rows, int columns, int array[rows][columns]){
    int max;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            max = array[i][j];
            if(array[i][j] > max){
                max = array[i][j];
            }
        }
    }
    printf("Max: %d", max);
}

//Iterates through each element in the 2D array to find the sum of each row
void rowSum(int rows,int array[rows][columns]){
    
    for(int i = 0; i < rows; i++){
        int sum = 0;
        printf("\nSum of row %d: ",i+1);
        for(int j = 0; j < columns; j++){
            sum += array[i][j];
        }
        printf("%d",sum);
    }
    printf("\n");
}

//Iterates through each element in the 2D array to find the sum of each column
void columnSum(int colums, int array[rows][colums]){
    for(int i = 0; i < columns; i++){
        int sum = 0;
        printf("\nSum of columns %d: ",i+1);
        for(int j = 0; j < rows; j++){
            sum += array[j][i];
        }
        printf("%d",sum);
    }
}

// Finds if the 2D array is a sqaure array or not
void isSquare(int rows, int columns){
    if(rows == columns){
        printf("This is a square array.\n");
    }
    else{
        printf("This is not a square array.\n");
    }
}

// Iterates and prints the 2D array in a proper manner
void displayOutputs(int rows, int columns, int array[rows][columns]){
    printf("Here is your 2Dim array:\n");
    for(int i = 0;i < rows; i++){
        printf("[");
        for(int j = 0;j < columns; j++){
            if(j < columns-1){
                printf("%d, ",array[i][j]);
            }
            else{
                printf("%d",array[i][j]);
            }
            
        }
        printf("]\n");
    }
}

