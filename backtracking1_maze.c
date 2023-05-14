#include <stdio.h>
#include <stdbool.h>
#define N 4

bool solution(int maze[N][N], int x, int y,int given[N][N]);
void solution_is(int given[N][N])
{
    int i,j;
    for ( i = 0; i < N; i++) {
        for ( j = 0; j < N; j++)
            printf(" %d ", given[i][j]);
        printf("\n");
    }
}
bool iscorrect(int maze[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
    return false;
}
bool solveMaze(int maze[N][N])
{
    int given[N][N] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };
    if (solution(maze, 0, 0, given) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }
    solution_is(given);
    return true;
}
bool solution(int maze[N][N], int x, int y, int given[N][N])
{
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        given[x][y] = 1;
        return true;
    }
    if (iscorrect(maze, x, y) == true)
        {

        if (given[x][y] == 1)
            return false;

        given[x][y] = 1;

        if (solution(maze, x + 1, y, given) == true)
            return true;

        if (solution(maze, x, y + 1, given) == true)
            return true;

        given[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };
    solveMaze(maze);
    return 0;
}
