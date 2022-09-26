#include"js.h"
#include"matrix_tool.h"
#include"universal.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int main(int argc,char** argv)
{
    int m=atoi(argv[1]);

    int n=atoi(argv[2]);

    int k=atoi(argv[3]);
    vector< vector<int> > A(m,vector<int>(n));
    vector< vector<int> > B(n,vector<int>(k));
    vector< vector<int> > C(m,vector<int>(k));
    init_matrix(A);
    init_matrix(B);

    jser js;
    js.begin();
    universal(A,B,C);
    long long int cost=js.end_ns();
    printf("m=%d n=%d k=%d cost:%lldns\n",m,n,k,cost);
    printf("A\n");
    print_matrix(A);
    printf("B\n");
    print_matrix(B);
    printf("C\n");
    print_matrix(C);
}