#define N 4
#include <stdbool.h>
#include <stdio.h>

void solution(int arr[N][N])
{
    int i,j;
    for ( i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            if(arr[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}
bool iscorrect(int arr[N][N], int r, int c)
{
    int i, j;
    for (i = 0; i < c; i++)
        if (arr[r][i])
            return false;
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (arr[i][j])
            return false;
    for (i = r, j = c; j >= 0 && i < N; i++, j--)
        if (arr[i][j])
            return false;

    return true;
}

bool queen(int arr[N][N], int c)
{
int i,j;
    if (c >= N)
        return true;


    for (i = 0; i < N; i++) {


        if (iscorrect(arr, i, c))
            {
            arr[i][c] = 1;


            if (queen(arr, c + 1))
                return true;
            arr[i][c] = 0;
        }
    }

    return false;
}
bool solve()
{
    int arr[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0} };

    if (queen(arr, 0) == false) {
        printf("Solution does not exist");
        return false;
    }

    solution(arr);
    return true;
}

int main()
{
    solve();
    return 0;
}
