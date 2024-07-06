#include<iostream>
using namespace std;

bool isPossible(int arr[] , int n , int k , int mid)
{
    int timeCount = 0;
    int count = 1;
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i] > mid)
        {
            return false;
        }
        if(arr[i] + timeCount > mid)
        {
            count++;
            if(count > k)
            return false;

            timeCount = 0;
            timeCount = arr[i];
        }
        else
        {
            timeCount += arr[i];
        }
    }
    return true;
}

int painterPartition(int arr[] , int n , int k)
{
    int ans = -1;
    int start = 0;
    int end = 0;

    for(int i=0 ; i<n ; i++)
    {
        end += arr[i];
    }

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(isPossible(arr , n ,k , mid))
        {
            ans = mid;
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[4] = {10 , 20 , 30 , 40};

    int n = 4;

    int k = 2;

    int ans = painterPartition(arr , n , k);

    cout<<"Answer is = "<<ans<<endl;
}