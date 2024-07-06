// Two incresing array are given
#include<iostream>
using namespace std;

int pivotElement(int arr[] , int n)
{
    int start = 0;
    int end = n-1;

    int mid = start + (end-start)/2;
    while(start <= end)
    {
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
        else {
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main(){
    int arr[7] = {50 , 60 , 70 , 80 , 90 , 100 , 10};

    int ans = pivotElement(arr , 7);

    cout<<"Pivot Element is = "<<arr[ans]<<endl;

}