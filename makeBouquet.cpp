#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 7 , 7 , 7 , 7 , 12 , 7 , 7 ;
bool canWeMakeBouquet(vector<int> &bloomDay , int m , int k , int mid)
{
    cout<<mid<<endl;
    int counter = 0;
    for(int i=0 ; i<bloomDay.size() ; i++)
    {
        if(bloomDay[i] <= mid)
        {
            counter++;
            cout<<"BloomDay = "<<bloomDay[i]<<endl;
            cout<<"Counter = "<<counter<<endl;
            if(counter == k)
            {
               m--;
               counter = 0;
               if(m == 0)
               break;
            }
        }
        if(bloomDay[i] > mid)
        {
            counter = 0;
        }
    }
    return m == 0;
}

int minimumDayToMakeBouquet(vector<int> &bloomDay , int m , int k)
{
    if(bloomDay.size() < m*k)
    {
        return -1;
    }
    int start = *min_element(bloomDay.begin() , bloomDay.end());
    int end = *max_element(bloomDay.begin() , bloomDay.end());

    int ans = -1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(canWeMakeBouquet(bloomDay , m , k , mid))
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
    vector<int>bloomDay{7 , 7 , 7 , 7 , 12 , 7 , 7 };

    int m = 2;

    int k = 3;

    int ans = minimumDayToMakeBouquet(bloomDay , m , k);

    cout<<"Minimum Day to make m boquet will be = "<<ans<<endl;
}