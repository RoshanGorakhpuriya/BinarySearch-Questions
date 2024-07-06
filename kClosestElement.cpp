#include<iostream>
#include<vector>
using namespace std;


// Brute Approach
/*
Step-1 -> calculate the differnce from (x - arr[i]) to every element;
Step-2 -> sort the difference
Step-3 -> Return the starting K element
*/

// Binary Search + Two-pointer

int lowerBound(vector<int> &arr , int x)
{
    int start = 0;
    int end = arr.size()-1;
    int ans = end;

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid] >= x)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

vector<int> bs_method(vector<int> &arr , int k , int x)
{
    // Step-1 -> Find the lower bound
    // Step-2 -> Take l = h-1;
    // Step-3 -> Make the window from [l , h] expanding the window;

    int h = lowerBound(arr , x);  // lower bound m difficulty hui thi ;
    cout<<h<<endl;
    int l = h-1;

    while(k--)
    {
        if(l < 0)
        {
            h++;
        }
        else if(h >= arr.size())
        {
            l--;
        }
        else if(x-arr[l] > arr[h]-x)
        {
            h++;
        }
        else
        {
            l--;
        }
    }
    return vector<int> (arr.begin()+l+1 , arr.begin()+h);
}


// Two-pointer approach
/*
vector<int> twoPointer(vector<int> &arr , int k , int x)
{
    int l = 0;
    int h = arr.size()-1;

    while(h-l >= k)
    {
        if(x-arr[l] > arr[h]-x)
        {
            l++;
        }
        else
        {
            h--;
        }
    }
    return vector<int> (arr.begin()+l , arr.begin()+h+1);
}
*/
int main(){
    // vector<int> arr{12 , 16 , 22 , 30 , 35 , 39 , 42 , 45 , 48 , 50 , 53 , 55 , 56};

    vector<int>arr{1 , 2 ,3 , 4 , 5};
    int k=4;
    int x=3;
    // vector<int>ans = twoPointer(arr , k , x);
    vector<int>ans = bs_method(arr , k , x);
    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}