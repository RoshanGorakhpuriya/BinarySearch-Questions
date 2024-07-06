#include<iostream>
using namespace std;


bool isPossible(int arr[] , int n , int m , int mid)
{
    int pageSum = 0;
    int c = 1;

    for(int i=0 ; i<n ; i++)
    {
        if(arr[i] > mid)
        {
            return false;
        }
        if(pageSum+arr[i] > mid)
        {
            c++;
            pageSum = 0;
            pageSum = arr[i];
            if(c > m)
            {
                return false;
            }
        }
        else
        {
            pageSum += arr[i];
        }
    }
    return true;
}

int minimumPages(int arr[] , int n , int m)
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
        if(isPossible(arr , n , m , mid))
        {
            ans = mid;
            end = mid-1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}




int main(){
    int arr[4] = {12 , 34,  67 , 90};

    int n = 4;

    int m = 2;

    int ans = minimumPages(arr , n , m);

    cout<<"Answer is = "<<ans<<endl;
}

