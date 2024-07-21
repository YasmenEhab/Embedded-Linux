#include <iostream>
#include<vector>
using namespace std;

 vector<vector<int>> transpose (vector<vector<int>> & matrix)
 {
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposed(cols,vector<int>(rows));
    for(int i=0 ; i<rows ; i++)
    {
        for(int j=0; j<cols ; j++)
        {
            transposed[j][i]=matrix[i][j];
        }
    }
    return transposed;
 }

void printMatrix (const vector<vector<int>> &matrix)
{
    for(const auto &row:matrix)
    {
        for(int num:row)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }

}
int main()
{
    vector<vector<int>> matrix1 = {{1,2,3,6},{4,5,6,5}};
    //cout<<matrix1.size()<<endl;
    //cout<<matrix1[0].size()<<endl;
    vector<vector<int>> matrix2 = transpose(matrix1);
    printMatrix(matrix2);


    return 0 ;
}
