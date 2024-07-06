// Leetcode- 875;

#include<iostream>
#include<limits.h>
#include<math.h>
using namespace std;

bool canKokoEatenBanana(int piles[] , int n , int h , int mid)
{
    int totalTime = 0;
    for(int i=0 ; i<n ; i++)
    {
        totalTime = totalTime + (ceil(piles[i]/double(mid))); // dono int m value rehti isliye double kiya hai ni tho ceil ka koi use ni rehta
    }
    return totalTime <= h;
}

int kokoEatenBanana(int piles[] , int n , int h)
{
    int start = 1;
    int end = INT_MIN;
    for(int i=0 ; i<n ; i++)
    {
        if(piles[i] >= end)
        {
            end = piles[i];
        }
    }
    cout<<end<<endl;

    int ans = -1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(canKokoEatenBanana(piles , n , h , mid))
        {
            // koko can eat all banana within given hours without being caught
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
    int piles[4] = {3 , 6 , 7 , 11};

    int n = 4;

    int h = 8;

    // we have to find minimum time for koko to eat banana in each hours 
    // h denotes the no of hours given;

    int ans = kokoEatenBanana(piles , n , h);

    cout<<"Minimum time to eat per banana in each hours will be = "<<ans<<endl;
}