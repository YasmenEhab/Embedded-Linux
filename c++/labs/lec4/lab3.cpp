#include <iostream>
#include<vector>
using namespace std;

 vector<vector<int>> function (vector<vector<int>> & v1)
 {
    
    int rows = v1.size();
    int cols = v1[0].size();
    vector<vector<int>> v2(cols,vector<int>(rows));
    for(const auto &rows:v1 )
    { 
        int i=0;
        for(const auto cols :v1)
        {
        v2[i].push_back(v1[i][]);
        }
        i++;
    }

 }

int main()
{
    vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix2 = function(matrix1);



    return 0 ;
}
