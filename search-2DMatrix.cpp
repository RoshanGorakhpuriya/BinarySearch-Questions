#include<iostream>
#include<vector>
using namespace std;

bool searchIn2DMatrix(vector<vector<int>>&arr , int target)
{
    int row = arr.size();
    int col = arr[0].size();

    int start = 0;
    int end = row*col-1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;
        int rowIndex = mid / col;
        int colIndex = mid % col;
        if(arr[rowIndex][colIndex] == target)
        {
            cout<<rowIndex<<" "<<colIndex<<endl;
            return true;
        }
        else if(arr[rowIndex][colIndex] > target)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return false;
}

int main(){
    int row = 3;
    int col = 3;
    vector<vector<int>>arr(row , vector<int>(col));

    for(int i=0 ; i<row ; i++)
    {
        cout<<"ith index\n";
        for(int j=0 ; j<col; j++)
        {
            cin>>arr[i][j];
        }
    }

    int target = 60;
    bool ans = searchIn2DMatrix(arr , target);

    if(ans)
    {
        cout<<"Element Found\n";
    }
    else
    {
        cout<<"Element not found\n";
    }
}

