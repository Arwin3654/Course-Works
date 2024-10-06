/*
Name: Arwin Jasper Johnson
Date: 10/05/2024
Course: CIS 2107 Section 003
Lab 6: Arrays of Pointers to functions
Project: Processing arrays using pointers. Using an arrays of pointers
to point to the specific function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);

int main() {
    unsigned int Choice;
    int students = 0;
    int exams = 0;
    
    void (*processGrades[])(int,int,int (*)[exams]) = {printArray,minimum,maximum,average};
    
    printf("Let's build an 2D array for the exam\n");
    printf("Enter the number of students: ");
    scanf("%d",&students);
    printf("Enter the number of exams each students took: ");
    scanf("%d",&exams);
    printf("\n");
    
    int grades[students][exams];
    
    for(int i = 0; i < students; i++){
        for(int j = 0; j < exams; j++){
            printf("Enter for grades for grades[%d][%d]: ",i+1,j+1);
            scanf("%d",&grades[i][j]);
        }
    }
    
    while(Choice != 4){
        printf("\nEnter a choice:\n");
        printf("\t0  Print the array of grades\n");
        printf("\t1  Find the minimum grades\n");
        printf("\t2  Find the maximum grades\n");
        printf("\t3  Print the average on all tests for each student\n");
        printf("\t4  End Program\n");
        printf("INPUT: ");
        scanf("%u", &Choice);
        printf("\n");
        if(Choice < 4 && Choice >= 0){
            (*processGrades[Choice])(students,exams,grades);
        }
        else if(Choice == 4){
            printf("Thank you!\n");
        }
    }
}
// Prints the implemented array
void printArray(int students, int exams, int grades[students][exams]) {
    printf("Here is the array:\n");
    for(int i = 0;i < students; i++){
        printf("[");
        for(int j = 0;j < exams; j++){
            if(j < exams-1){
                printf("%d, ",grades[i][j]);
            }
            else{
                printf("%d",grades[i][j]);
            }
        }
        printf("]\n");
    }
}
//Finds the minimum value in the array
void minimum(int students, int exams, int grades[students][exams]) {
    int min = INT_MAX;
    
    for(int i = 0; i < students; i++){
        for(int j = 0; j < exams; j++){
            if(grades[i][j] < min){
                min = grades[i][j];
            }
        }
    }
    printf("The minimum grade of all student is: %d\n",min);
}
//Finds the maximum value in the array
void maximum(int students, int exams, int grades[students][exams]) {
    int max = INT_MIN;
    for(int i = 0; i < students; i++){
        for(int j = 0; j < exams; j++){
            if(grades[i][j] > max){
                max = grades[i][j];
            }
        }
    }
    printf("The maximum grade of all students is: %d\n",max);
}
//Find the average of each student
void average(int students, int exams, int grades[students][exams]) {
    double average = 0;
    
    int total_exams = students*exams;
    for(int i = 0; i < students; i++){
        int sum = 0;
        for(int j = 0; j < exams; j++){
            sum += grades[i][j];
        }
        average = (double)sum/exams;
        printf("The average of student %d: %.2f\n",i+1,average);
    }
    
    
}