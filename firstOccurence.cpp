#include<iostream>
using namespace std;

void firstOccurence(int arr[] , int start , int end , int target ,int &ansIndex){
    int mid = (start + end)/2;

    while(start <= end)
    {
        if(arr[mid] == target)
        {
            ansIndex = mid;
            end = mid - 1;
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
    int arr[5] = {10 , 10  , 20 , 60 , 60};

    int start = 0;
    int end = 4;
    int ansIndex = -1;
    int target = 60;

    firstOccurence(arr , start , end , target , ansIndex );

    cout<<ansIndex<<endl;
}