//
// Created by htbc4 on 1/7/2020.
//

#include <stdio.h>



int recursive(int x, int p);
int nonRecursive(int x, int p);


int main(){

    printf("Enter the value of x \n");
    int x;
    scanf("%d",&x);
    printf("Enter the largest power \n");
    int p;
    scanf("%d",&p);
    printf("%d \n",recursive(x, p));
    printf("%d \n",nonRecursive(x, p));
    return 0;
}

int recursive(int x, int p){

    if (p == 0) {
        return 1;
    } else


    if (p == 1) {
        return 2 * x;
    } else {
        return (2*p*recursive(x, p- 1) - 2 * (p - 1) * recursive(x, p - 2));
    }
}




int nonRecursive(int x, int p){

    int result, hn1, hn2;
    hn2 = 1;
    hn1 = 2 * x;

    if (p == 0)
        return hn2;

    if (p == 1)
        return hn1;

    for (int i = 2; i <= p; i++){
        result = 2*i*hn1 - 2 * (i - 1) * hn2;
        hn2 = hn1;
        hn1 = result;
    }

    return result;

}