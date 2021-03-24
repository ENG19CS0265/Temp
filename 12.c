#include <stdio.h>

typedef struct{
    int noOfUnit;
    int finalNum, finalDen;
    int egypt[20];
    
}fraction;

int noOfCases(){
    int n;
    printf("Please enter no of cases\n");
    scanf("%d", &n);
    return n;
}

fraction getDetailsOne(){
    fraction G;
    G.finalDen = 1;
    printf("Please enter the no of units:\n");
    scanf("%d", &G.noOfUnit);
    printf("Enter the positive integers\n");
    for(int i = 0; i < G.noOfUnit; i++){
        scanf("%d", &G.egypt[i]);
    }
    for(int i = 0; i < G.noOfUnit; i++){
        G.finalDen *= G.egypt[i];
    }
    return G;
}

fraction getDetailsN(fraction *E, int n){
    for(int i = 0; i<n ; i++){
        E[i] = getDetailsOne();
    }
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void computeOne(fraction *P){
    int sum = 0;
     
    for(int i = 0; i < P -> noOfUnit; i++){
        int tempnum = 1;
        for(int j =0; j < P -> noOfUnit; j++){
            if (i != j){
                tempnum *= P -> egypt[j];
            }
        } sum += tempnum;
    }
    
    P -> finalNum = sum / gcd(sum , P -> finalDen);
    P -> finalDen = P -> finalDen / gcd(sum , P -> finalDen);
    
}

void computeN(fraction *E, int n){
    for(int i = 0; i <n ; i++){
        computeOne(&E[i]);
    }
}

void outputOne(fraction G){
    for(int i = 0; i < G.noOfUnit; i++){
        if(i != G.noOfUnit -1){
            printf("1/%d +", G.egypt[i]);
        }
        else{
            printf("1/%d = %d/%d",G.egypt[i], G.finalNum, G.finalDen);
        }
    }
    printf("\n");
}

void outputN(fraction *E, int n){
    printf("Output\n");
    for(int i = 0; i <n ; i++){
        outputOne(E[i]);
    }
}

int main()
{
    int no;
    no = noOfCases();
    fraction allCases[no];
    getDetailsN(allCases, no);
    computeN(allCases, no);
    outputN(allCases, no);
    

    return 0;
}
