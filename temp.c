#include<stdio.h>

typedef struct gradebook{
    char subjectName[20];
    int noOfStudent, noOfScores;
    float weight[20];
    char studentName[20][20];
    float score[20][20];
    float finalGrade[20];
    char *grade[20];
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
};

void calcNo(Gradebook *a, int n){
    int i, j, k;
    float temp1, temp2;
    for(i = 0; i < n; i++){
        for(j = 0; j < a[i].noOfStudent; j++){
            temp1 = 0;
            temp2 = 0;
            for(k = 0; k < a[i].noOfScores; k ++){
                temp1 += a[i].score[j][k] * a[i].weight[k];
                temp2 += a[i].weight[k];
                
            }
            a[i].finalGrade[j] = temp1/temp2;
        }
    }
};

void findGrade(Gradebook *a, int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0;j < a[i].noOfStudent;j++){
            if(0 <= a[i].finalGrade[j] && a[i].finalGrade[j] < 60){
                a[i].grade[j] = "F";
            }
            else if(60 <= a[i].finalGrade[j] && a[i].finalGrade[j] < 70){
                a[i].grade[j] = "D";
            }
            else if(70 <= a[i].finalGrade[j] && a[i].finalGrade[j] < 80){
                a[i].grade[j] = "C";
            }
            else if(80 <= a[i].finalGrade[j] && a[i].finalGrade[j] < 90){
                a[i].grade[j] = "B";
            }
            else if(90 <= a[i].finalGrade[j] && a[i].finalGrade[j] <= 100){
                a[i].grade[j] = "A";
            }
        }
    }
}

void  showOutput(Gradebook *a, int n){
    int i, j;
    for(i = 0; i < n; i++){
        printf("%s\n", a[i].subjectName);
        for(j = 0;j < a[i].noOfStudent;j++){
            printf("%s\t", a[i].studentName[j]);
            printf("%.2f\t", a[i].finalGrade[j]);
            printf("%s\n", a[i].grade[j]);
        }
    }
}

int main(){
    int noOfCases;
    noOfCases = takeOfInput();
    Gradebook cases[noOfCases] ;
    getDetails(cases, noOfCases);
    calcNo(cases, noOfCases);
    findGrade(cases, noOfCases);
    showOutput(cases, noOfCases);
    
    
    return 0;
}
