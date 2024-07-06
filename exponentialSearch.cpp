#include<iostream>
using namespace std;

int binarySearch(int arr[] , int start , int end, int x)
{
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid] == x)
        {
            return mid;
        }
        else if(arr[mid] > x)
        {
            end = mid-1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int  exponentialSearch(int arr[] , int n , int x)
{
    if(arr[0] == x)
    {
        return 0;
    }

    int i=1 ;
    while(i < n && arr[i] <= x)
    {
        i = i * 2;
    }
    return binarySearch(arr , i/2 , min(i , n-1) , x);
}

int main(){
    int arr[10] = {3 , 4 , 5 , 6 , 11 , 13 , 14 , 15 , 56 , 70};

    int n = 10;

    int x = 56;

    int ans = exponentialSearch(arr , n , x);

    cout<<"Answer is = "<<ans<<endl;
}