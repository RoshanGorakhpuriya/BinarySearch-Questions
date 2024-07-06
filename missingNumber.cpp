#include<iostream>
#include<algorithm>
using namespace std;

// Approach-1 -> Using Sum techinque
/*
int missingNumber(int arr[] , int n)
{
    int total_sum = 0;
    for(int i=0 ; i<=n ; i++)
    {
        total_sum = total_sum + i;
    }

    int given_arr_sum = 0;
    for(int i=0 ; i<n ; i++)
    {
        given_arr_sum = given_arr_sum + arr[i];
    }

    int finalAns = total_sum - given_arr_sum;
    return finalAns;
}
*/

// Approach-2 -> Using XOR techinque
/*
int missingNumber(int arr[] , int n)
{   
    // puri range ka XOR kr do
    int allXOR = 0;
    for(int i=0 ; i<=n ; i++)
    {
        allXOR = allXOR ^ i;
    }

    // present arr element ka range se XOR kara do
    for(int i=0 ; i<n ; i++)
    {
        allXOR = allXOR ^ arr[i];
    }
    return allXOR;  // single element milega;
}
*/

// Approach-3 -> Using binary Search
int missingNumber(int arr[] , int n)
{
    sort(arr , arr+n); // binarySearch humesha sorted array me lgti hai;

    int start = 0;
    int end = n-1;
    int ans = -1;

    while(start <= end)
    {
        int mid = (start + (end-start)/2);
        int number = arr[mid];
        int index = mid;
        int diff = number - index;

        if(diff == 0)
        {
            // right me chalo , sb shi chl rha hai;
            start = mid + 1;
        }
        if(diff == 1)
        {
            // ya tho yhi mid ans ho skta hai 
            // yha firr piche dekho khi wha pe same aana 
            //pehle se band tho ni ho gya
            ans = index;
            end = mid-1;
        }
    }

    if(ans == -1) // pura arr check kr liya khi bhi 1 diff ni aaya;
    {
        // matlab last(range ka last element) ans hoga
        return n;
    }
    return ans;
}


int main(){
    int arr[5] = {2 , 3 , 5 , 0 , 1};

    int ans = missingNumber(arr , 5);

    cout<<"Missing Element is = "<<ans<<endl;
}