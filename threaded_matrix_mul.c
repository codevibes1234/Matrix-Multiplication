#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct arguments
{
    int n,row_id;
    int *arr, *sq;
};

typedef struct arguments Args;

void* square_row(void* threadarg)
{
    Args* arg = (Args*)threadarg;
    for(int i = 0; i < arg->n; i++)
        for(int j = 0; j < arg->n; j++)
            *((arg->sq)+(arg->n)*(arg->row_id)+i) += (*((arg->arr)+(arg->n)*(arg->row_id)+j))*(*((arg->arr)+j*(arg->n)+i));
    return NULL;
}

void square(int N,int (*array)[N],int (*sqr)[N])
{
    Args args[N];
    for(int i = 0; i < N; i++)
    {
        args[i].n = N;
        args[i].arr = (int*)array;
        args[i].sq = (int*)sqr;
        args[i].row_id = i;
    }
    pthread_t pid[N];
    for(int i = 0; i < N; i++)
        pthread_create(pid+i,NULL,square_row,(void*)(args+i));
    for(int i = 0; i < N; i++)
        pthread_join(pid[i],NULL);
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
    int N = atoi(argv[argc-1]);
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