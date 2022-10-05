#include<cstdio>
#include"matrix_tool.h"
#include"Strassen.h"
#include"universal.h"
#include<vector>
#include<string>
#include"js.h"
using namespace std;
vector< vector<long long int> > time_cost_list;
vector<int> scale;
int main()
{
    for(int i=0;i<=9;i++)
    {
        scale.push_back(1<<(i+5));
    }
    for(int i=0;i<scale.size();i++)
    {
        int n=scale[i];
        auto A=create_matrix(n);
        auto B=create_matrix(n);
        auto C=create_matrix(n);

        auto A2=create_matrix(n);
        auto B2=create_matrix(n);
        auto C2=create_matrix(n);

        init_matrix(n,A);
        init_matrix(n,B);
        
        copy_matrix(A,A2,n);
        copy_matrix(B,B2,n);

        timer.begin();
        Strassen(n,A,B,C);
        auto cost_time=timer.end_ns();

        timer.begin();
        universal(n,A2,B2,C2);
        auto cost_time2=timer.end_ns();

        time_cost_list.resize(2);

        time_cost_list[0].push_back(cost_time);
        time_cost_list[1].push_back(cost_time2);
        delete_matrix(n,A);
        delete_matrix(n,B);
        delete_matrix(n,A2);
        delete_matrix(n,B2);

    }
    printf("%20s %20s %20s\n","scale","Strassen","universal");
    for(int i=0;i<scale.size();i++)
    {
        printf("%20d %20lld %20lld\n",scale[i],time_cost_list[0][i],time_cost_list[1][i]);
    }
}