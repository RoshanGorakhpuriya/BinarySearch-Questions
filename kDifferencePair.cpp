#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// Brute-Appraoch
/*
int countKPair(vector<int> &arr , int k)
{
    set<pair<int , int>>ans;
    int n = arr.size();
    int count = 0;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if(abs(arr[j] - arr[i]) == k)
            {
                ans.insert({arr[i] , arr[j]});
            }
        }
    }
    for(auto nums : ans)
    {
        cout<<nums.first<<" "<<nums.second<<endl;
    }
    return ans.size();
}
*/

// Two-Pointer Approach
/*
int countKPair(vector<int> &arr , int k)
{ 
    // 1 1 3 4 5
    set<pair<int , int>>ans;
    int i=0;
    int j=1;

    while(j < arr.size())
    {
        int diff = arr[j] - arr[i];

        if(diff == k)
        {
            ans.insert({arr[i] , arr[j]});
            i++;
            j++;
        }
        else if(diff > k)
        {
            i++;
        }
        else 
        {
            j++;
        }
        if(i == j)
        {
            j++;
        }
    }
    for(auto nums : ans)
    {
        cout<<nums.first<<" "<<nums.second<<endl;
    }
    return ans.size();
}
*/

// Binary Search

int binarySearch(vector<int>&arr , int start , int target)
{
    int end = arr.size()-1;
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

int countKPair(vector<int>&arr , int k)
{
    set<pair<int , int>>ans;

    for(int i=0 ; i<arr.size() ; i++)
    {
        if(binarySearch(arr , i+1, arr[i]+k) != -1)
        {
            ans.insert({arr[i] , arr[i]+k});
        }
    }
    for(auto nums : ans)
    {
        cout<<nums.first<<" "<<nums.second<<endl;
    }
    return ans.size();

}
int main(){
    vector<int> arr {3 , 1 , 4 , 1 ,5};
    sort(arr.begin() , arr.end());
    int k = 2;
    int ans = countKPair(arr , k);

    cout<<"Distinct pairs are = "<<ans<<endl;
}

/*
3 , 1
3 , 4
3 , 1 , 
3 , 5 , 

1 , 4 
*/