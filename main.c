#include <stdio.h>
#define M 4
#define N 4

//the maze problem
int isSafe(int x, int y);
int solveMaze(int r, int c);
void printSolution();

int mazeMatrix[M][N] = {
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 1},
        {0, 0, 1, 0},

};

int solutionMatrix[M][N];
int main() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            solutionMatrix[i][j] = 0;
        }
        printf("Please input a starting point\n"); //note that for a valid answer in this case it must be (0, 0) r (0, 1)
        int x,y;
        scanf("%d %d",&x,&y);
        mazeMatrix[x][y];
        solveMaze(x,y);
        return 0;
    }
}
int solveMaze(int r, int c) {

    if ((r == M - 1) && (c == N - 1)) {
        printSolution();
        printf("----------\n");
        return 1;
        //check if algorithm is done
    }

    if (isSafe(r,c) && mazeMatrix[r][c]) {
        solutionMatrix[r][c] = 1;

        if (r + 1 < M && !solutionMatrix[r + 1][c]){
            solveMaze(r + 1, c);
            }

        if (r - 1 >= 0 && !solutionMatrix[r - 1][c]){
            solveMaze(r - 1, c);
            }

        if (c + 1 < N && !solutionMatrix[r][c + 1]){
            solveMaze(r, c + 1);
            }


        if ( c- 1 >= 0 && !solutionMatrix[r][c - 1]){
            solveMaze(r, c - 1);
            }
    }

    // backtrack from current cell and remove it from current path
    solutionMatrix[r][c] = 0;
    return 0;
}
int isSafe(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return 0;

    return 1;
}
void printSolution()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", solutionMatrix[i][j]);
        printf("\n");
    }
}
