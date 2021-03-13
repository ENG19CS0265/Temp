#include<stdio.h>

typedef struct gradebook{
    char subjectName[20];
    int noOfStudent, noOfScores;
    float weight[20];
    char studentName[20][20];
    float score[20][20];
    float finalGrade[20];
    char grade;
}Gradebook;


int takeOfInput(){
  int n;
  printf("Enter no of Case \n");
  scanf("%d", &n);
  return n;
};

void getDetails(Gradebook *a, int n){
    int i, j, k;
    for(i = 0; i < n; i++){
        printf("Enter subject name\n");
        scanf("%s", a[i].subjectName);
        printf("Enter the no of students and courses\n");
        scanf("%d%d", &a[i].noOfStudent, &a[i].noOfScores);
        printf("Please Enter the weights\n");
        for(j = 0; j < a[i].noOfScores; j++){
            scanf("%f", &a[i].weight[j]);
        }
        
        //Student details
        printf("Please Enter students details\n");
        for(j = 0; j < a[i].noOfStudent; j++){
            printf("Enter student name:\n");
            scanf("%s", a[i].studentName[j]);
            printf("Enter the scores\n");
            for(k = 0; k < a[i].noOfScores; k++){
                scanf("%f", &a[i].score[j][k]);
            }
        }
        
        
    }
}

void calcNo(Gradebook *a, int n){
    int i, j, k;
    float temp;
    for(i = 0; i < n; i++){
        for(j = 0; j < a[i].noOfStudent; j++){
            temp = 0;
            for(k = 0; k < a[i].noOfScores; k ++){
                temp += a[i].score[j][k] * a[i].weight[k];
            }
            a[i].finalGrade[j] = temp;
        }
    }
}

int main(){
    int noOfCases;
    noOfCases = takeOfInput();
    Gradebook cases[noOfCases] ;
    getDetails(cases, noOfCases);
    calcNo(cases, noOfCases);
    
    
    return 0;
}
