#include <stdlib.h>
#include <stdio.h>

int a[20][20];
int tD, n;///tD-Dimension of the table
int poz_x = 1, poz_y = 1;
int xMove[9] = {0, 1, 2,2,1,-1,-2,-2,-1};
int yMove[9] = {0,-2,-1,1,2, 2, 1,-1,-2};

void display() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    printf("\n");
    exit(0);
}

void readDim() {
    printf ("Enter table dimension: ");
    scanf("%d", &n);

    tD = n*n;
}

void backtracking(int x, int y, int number) {

    if(a[x][y]==0 && (x>0 && x<=n && y>0 && y<=n)) {
        a[x][y]=number;

        if(number==tD) {
            display();
        }

        for(int i=1;i<=8;i++) {
            backtracking(x+xMove[i], y+yMove[i], number+1);
        }

        a[x][y]=0;
    }
}

int main() {
    readDim();
    backtracking(poz_x, poz_y,1);
}
