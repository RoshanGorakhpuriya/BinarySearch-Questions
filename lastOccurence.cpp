#include<iostream>
using namespace std;

void lastOccurence(int arr[] , int start , int end , int target ,int &ansIndex){
    int mid = (start + end)/2;

    while(start <= end)
    {
        if(arr[mid] == target)
        {
            ansIndex = mid;
            start = mid + 1;
        }
        else if(arr[mid] > target)
        {
            end = mid - 1;
        }
        else if(arr[mid] < target)
        {
            start = mid + 1;
        }
        mid = (start + end)/2;
    }
}


int main(){
    int arr[5] = {10 , 10  , 20 , 20 , 60};

    int start = 0;
    int end = 4;
    int ansIndex = -1;
    int target = 20;

    lastOccurence(arr , start , end , target , ansIndex );

    cout<<ansIndex<<endl;
}