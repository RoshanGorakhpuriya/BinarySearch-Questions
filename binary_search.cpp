#include<iostream>
using namespace std;

int binarySearch(int arr[] , int start , int end , int target)
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
            end = mid -1;
        }
        else if(arr[mid] < target)
        {
            start = mid + 1;
        }
        
       mid = (start + end)/2;
    }
    return -1;
}

int main(){
    int arr[10] = {10 , 20 , 30 , 40 , 42 , 44 , 46 , 48 , 50 , 70};

    int start = 0;

    int end = 9;

    int target = 40;

    int ans = binarySearch(arr , start , end , target);

    cout<<ans<<endl;
}