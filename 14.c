#include<stdio.h>
#include<string.h>

typedef struct timeCard{
char name[20];
float mins; 
}timeCard;

typedef struct employee{
char name[20];
float wage;
float hour;
float totalPay;
}Employee;

void inputOne(Employee *E){
printf("Enter the details of the employee\n");
printf("Name ,  Hour:\n");
scanf("%s%f",E->name, &E->wage);
}
void inputN(int n, Employee E[]){
for(int i=0;i<n;i++){
inputOne(&E[i]);
}
}
void inputTimeCard(int n,timeCard T[]){
for(int i=0;i<n;i++){
printf("Enter name & min worked:\n");
scanf("%s%f", T[i].name,&T[i].mins);
}
}

float calcHours(Employee *E, int n, timeCard T[]){
float totalMin=0,totalHour=0;
for(int i=0;i<n;i++){
int c = strcmp(E->name,T[i].name);
if(c==0){
totalMin += T[i].mins;
}
}
totalHour = totalMin/60;
return totalHour;
}

void computeOne(Employee *E, int n, timeCard T[]){
E->hour = calcHours(E, n, T);
if(E->hour > 40){
E->totalPay = (40 * E->wage + (E->hour - 40)*(1.5 * E->wage));
} 
else{
E->totalPay= E-> hour * E-> wage;
}
}

void computeN(int n,Employee E[], int m, timeCard T[]){
for(int i =0;i<n;i++){
computeOne(&E[i], m, T);
}
}

void outputOne(Employee *E){
if(E->hour !=0){
printf("%s: %.2f hours, $%.2f \n", E->name,E->hour,E->totalPay);
}
}

void outputN(int n, Employee E[]){
for(int i = 0;i<n;i++){
outputOne(&E[i]);
}
}

int main(){
int noOfEmp, n;
printf("Enter the no of employee:\n");
scanf("%d", &noOfEmp);
Employee E[noOfEmp];
inputN(noOfEmp, E);
printf("nter the no of Time Cards");
scanf("%d",&n);
timeCard T[n];
inputTimeCard(n, T);
computeN(noOfEmp, E, n, T);
outputN(noOfEmp, E); 
return 0;
}
