#include<iostream>
using namespace std;

int findPivotIndex(int arr[] , int n)
{
    int start = 0;
    int end = n-1;

    int mid = start + (end-start)/2;

    while(start <= end)
    {
        // if there is only one element then whi humara pivot element hai
        if(start == end)
        {
            return start;
        }
        if(mid+1 < n && arr[mid] > arr[mid+1])
        {
            return mid;
        }
        else if(mid-1 >= 0 && arr[mid] < arr[mid-1])
        {
            return mid-1;
        }
        else if(arr[start] > arr[mid])
        {
            end = mid-1;
        }
        else 
        {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int binarySearch(int arr[] , int start , int end , int target)
{
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[7] = {4 , 5 , 6 , 7 , 0 , 1 , 2};

    int n=7;

    int target = 0;

    // find pivot Element so that we can find breaking point of array;
    int pivotIndex = findPivotIndex(arr , n);

    // search element in two half;
    // first -> 0 to pivotIndex and second->pivotIndex+1 to n-1;

    if(arr[pivotIndex] >= target && arr[0] <= target)
    {
        int ans = binarySearch(arr , 0 , pivotIndex , target);
        cout<<"Position of element is = "<<ans<<endl;
    }
    else
    {
        int ans = binarySearch(arr , pivotIndex+1 , n-1 , target);
        cout<<"Position of element is = "<<ans<<endl;
    }
}