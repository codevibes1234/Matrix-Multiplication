#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void square(int N,int arr[][N],int square[][N])
{
    for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
    for(int k = 0; k < N; k++)
    square[i][j] += (arr[i][k])*(arr[k][j]);
}

void print(int N,int arr[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        printf("%d ",arr[i][j]);
        putchar('\n');
    }
}

int main(int argc, char* argv[])
{
    const int N = atoi(argv[argc-1]);
    int arr[N][N];
    time_t t;
    srand(time(&t));
    for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
    arr[i][j] = rand() % 10;
    print(N,arr);
    int sq[N][N];
    for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
    sq[i][j] = 0;
    square(N,arr,sq); 
    print(N,sq);
}