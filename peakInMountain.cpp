// increasing array then suddenly decreasing;
#include<iostream>
using namespace std;

int peakElement(int arr[] , int n)
{
    int start = 0;
    int end = n-1;
    int ans = -1;
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(mid+1 <n && arr[mid] < arr[mid+1])
        {
            start = mid + 1;
        }
        else
        {
            ans = mid;
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    int arr[4] = {0 , 2 , 1 , 0};

    int n=4;

    int ans = peakElement(arr , n);

    cout<<"Peak Element is = "<<ans<<endl;
}