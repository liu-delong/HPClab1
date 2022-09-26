#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
void init_matrix(vector<vector<int>> &A)
{
    srand(time(0));
    int m=A.size();
    int n=A[0].size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            A[i][j]=rand()%(1<<16);
        }
    }
}
void init_matrix(int N,int** A)
{
    srand(time(0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            A[i][j]=rand()%(1<<16);
        }
    }
}
int** create_matrix(int N)
{
    int **A=new int*[N];
    for(int i=0;i<N;i++)
    {
        A[i]=new int[N];
    }
    return A;
}
void delete_matrix(int N,int **A)
{
    for(int i=0;i<N;i++)
    {
        delete[] A[i];
    }
    delete A;
}

void print_matrix(vector<vector<int>> &A)
{
    int m=A.size();
    int n=A[0].size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%10d ",A[i][j]);
        }
        cout<<endl;
    }
}
void print_matrix(int **A,int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%10d ",A[i][j]);
        }
        printf("\n");
    }
}