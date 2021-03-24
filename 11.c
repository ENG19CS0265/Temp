#include <stdio.h>
#include <string.h>

typedef struct{
    char studentName[20];
    float score[20];
    float finalGradeNo;
    char grade;
}StudentDetails;

typedef struct{
    char subjectName[20];
    int noOfStudent, noOfScores;
    float weight[20];
    StudentDetails student[20];
    float totalweight;
}GradeBook;

int GetNoOfCases(){
    int temp;
    printf("Please enter the no of cases:\n");
    scanf("%d",&temp);
    return temp;
}

StudentDetails getStudentDetails(int n){
    StudentDetails S;
    printf("Please enter the student name\n");
    scanf("%9s", S.studentName);
    printf("Please enter the student marks\n");
    for(int i = 0; i<n; i++){
        printf("\nScore %d:", i+1);
        scanf("%f", &S.score[i]);
    }
    return S;
}

GradeBook getDetailsOne(){
    GradeBook G;
    printf("Enter the sub name\n");
    scanf("%9s", G.subjectName);
    printf("Please enter the no of student and scores\n");
    scanf("%d%d", &G.noOfStudent, &G.noOfScores);
    printf("Please enter the no of weights");
    for(int j = 0; j < G.noOfScores; j++)
    {
        scanf("%f", &G.weight[j]);
        G.totalweight = G.totalweight + G.weight[j];
    }
    for(int j = 0;j < G.noOfStudent; j++){
        G.student[j] = getStudentDetails(G.noOfScores);
    }
    return G;
}

GradeBook getDetailsN(GradeBook *a, int n){
    for(int i=0;i<n;i++){
        a[i] = getDetailsOne();
    }
}

char getGrade(float s)
{
    char grade;
    if (s < 60)
    {
        grade = 'F';
        return grade;
    }
    else if (s >= 60 && s < 70)
    {
        grade = 'D';
        return grade;
    }
    else if (s >= 70 && s < 80)
    {
        grade = 'C';
        return grade;
    }
    else if (s >= 80 && s < 90)
    {
        grade = 'B';
        return grade;
    }
    else
    {
        grade = 'A';
        return grade;
    }
}

void computeOne(GradeBook *p){
    for(int i = 0; i < p -> noOfStudent; i++){
        float sum = 0;
        for(int j =0; j < p -> noOfScores; j++){
            sum = sum + (p -> weight[j] * p -> student[i].score[j]);
        }
        sum = sum / p -> totalweight;
        p->student[i].finalGradeNo = sum;
        p ->student[i].grade = getGrade(sum);
    }
}

void computeN(GradeBook *G, int n){
    for(int i = 0; i < n; i++){
        computeOne(&G[i]);
    }
}

void showOutputOne(GradeBook G){
    for (int i = 0; i < G.noOfStudent; i++)
    {
        printf("%s      %0.2f      %c\n", G.student[i].studentName, G.student[i].finalGradeNo, G.student[i].grade);
    }
    printf("\n \n");
}

void showOutputN(GradeBook *G, int n){
    printf("\n Output: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", G[i].subjectName);
        showOutputOne(G[i]);
    }
    
    
}

int main()
{
    int noOfCases;
    noOfCases = GetNoOfCases();
    GradeBook details[noOfCases];
    getDetailsN(details, noOfCases);
    computeN(details, noOfCases);
    showOutputN(details, noOfCases);
    return 0;
}
