#include<iostream>
using namespace std;

int binarySearch(int arr[] , int start , int end , int x)
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
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int unboundedBS(int arr[] , int n , int x)
{
    int i = 0;
    int j = 1;

    while(arr[j] < x)
    {
        i = j;
        j = j * 2;
    }
    int start = i;
    int end = j;

    return binarySearch(arr , start , end , x);
}

int main(){
    int arr[10] = {3 , 4 , 5 , 6 , 11 , 13 , 14 , 15 , 56 , 70 };

    int n = 10;

    int x = 70;

    int ans = unboundedBS(arr , n , x);

    cout<<"Answer is = "<<ans<<endl;
}