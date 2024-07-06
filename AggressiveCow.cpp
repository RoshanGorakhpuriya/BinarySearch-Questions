#include<iostream>
#include<algorithm>
using namespace std;

bool isPossibel(int arr[] , int n , int k , int mid)
{
    int cowCount = 1;
    int position = arr[0];

    for(int i=1 ; i<n ; i++)
    {
        if(arr[i] - position >= mid)
        {
            cowCount++;
            if(cowCount == k)
            {
                return true;
            }
            position = arr[i];
        }
    }
    return false;
}

int aggressiveCow(int arr[] , int n , int k)
{
    int ans = -1;
    sort(arr , arr+n);
    int start = 0;
    int end = arr[n-1] - arr[0];

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(isPossibel(arr , n , k , mid))
        {
            ans = mid;
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    int arr[5] = {1 , 2 , 4 , 8 , 9};

    int n = 5;

    int k = 3;


    int ans = aggressiveCow(arr , n , k);

    cout<<ans<<endl;
}