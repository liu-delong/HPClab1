#include<vector>
using namespace std;
void init_matrix(vector<vector<int>> &A);
void init_matrix(int N,int** A);
int** create_matrix(int N);
void delete_matrix(int N,int **A);
void print_matrix(vector<vector<int>> &A);
void print_matrix(int **A,int N);