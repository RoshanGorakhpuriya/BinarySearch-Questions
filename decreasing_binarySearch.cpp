#include<iostream>
using namespace std;

int decreasing_binarySearch(int arr[] , int start , int end , int target)
{
    int mid = (start + end)/2;
    while(start <= end)
    {
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            start = mid + 1;
        }
        else if(arr[mid] < target)
        {
            end = mid - 1;
        }
        
       mid = (start + end)/2;
    }
    return -1;
}

int main(){
    int arr[10] = {90 , 80 , 70 , 60 , 55 , 50 , 40 , 30 , 20 , 10};

    int start = 0;

    int end = 9;

    int target = 50;

    int ans = decreasing_binarySearch(arr , start , end , target);

    cout<<ans<<endl;
}