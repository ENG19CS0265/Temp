
#include<stdio.h>

typedef struct gradebook{
    char subjectName[20];
    int noOfStudent, noOfScores;
    float weight[20];
    char studentName[20][20];
    float score[20][20];
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
        //
        printf("Please Enter students details\n");
        for(j = 0; j < a[i].noOfStudent; j++){
            printf("Enter student name:\n");
            scanf("%s", a[i].studentName[j]);
            printf("Enter the scores\n");
            for(k = 0; k < a[i].noOfScores; k++){
                scanf("%f", &a[i].score[j][k]);
            }
        }
        //
        printf("Test Test- - - - - ");
        for(j = 0; j < a[i].noOfStudent; j++){
            printf("student name:%s\n", a[i].studentName[j]);
            
            printf("scores\n");
            for(k = 0; k < a[i].noOfScores; k++){
                printf("%f", a[i].score[j][k]);
            }
        }
        
    }
}

int main(){
    int noOfCases;
    noOfCases = takeOfInput();
    Gradebook cases[noOfCases];
    getDetails(cases, noOfCases);
    
    return 0;
}
