#include<cstdio>
#include"matrix_tool.h"
#include"Strassen.h"
#include"universal.h"
#include"loop_expansion.h"
#include"CoppersmithWinograd.h"
#include<vector>
#include<string>
#include"js.h"
using namespace std;
vector< vector<long long int> > time_cost_list;
vector<int> scale;
int main()
{
    for(int i=0;i<7;i++)
    {
        scale.push_back(1<<(i+5));
    }
    vector<string> algorithm_name_list={"universal","Strassen","CoppersmithWinograd","loop_expansion"};
    time_cost_list.resize(algorithm_name_list.size());
    for(int i=0;i<scale.size();i++)
    {
        int n=scale[i];
        auto A=create_matrix(n);
        auto B=create_matrix(n);
        auto C=create_matrix(n);

        init_matrix(n,A);
        init_matrix(n,B);

        int index=0;

        timer.begin();
        universal(n,A,B,C);
        time_cost_list[index++].push_back(timer.end_ns());
        timer.begin();
        Strassen(n,A,B,C);
        time_cost_list[index++].push_back(timer.end_ns());

        timer.begin();
        CoppersmithWinograd(n,A,B,C);
        time_cost_list[index++].push_back(timer.end_ns());

        timer.begin();
        loop_expansion(n,A,B,C);
        time_cost_list[index++].push_back(timer.end_ns());


        delete_matrix(n,A);
        delete_matrix(n,B);
        delete_matrix(n,C);

    }
    printf("%-20s","scale");
    for(int i=0;i<algorithm_name_list.size();i++)
    {
        printf("%-20s",algorithm_name_list[i].c_str());
    }
    printf("\n");
    for(int i=0;i<scale.size();i++)
    {
        printf("%-20d",scale[i]);
        for(int j=0;j<time_cost_list.size();j++)
        {
            printf("%-20lld",time_cost_list[j][i]);
        }
        printf("\n");
    }
}