#include<iostream>
#include<vector>
using namespace std;

int singleElement(vector<int>& arr)
{
    int start = 0;
    int end = arr.size()-1;
    int ans = -1;
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(mid%2 == 0)
        {
            if(mid+1 < arr.size() && arr[mid] == arr[mid+1])
            {
                // sb shi chl rha hai , ans aage milega;
                start  = mid+2;
            }
            else
            {
                // mid tho even hai pr uske aage apna element ni hai
                // may be ans ho skta hai
                // store and compute
                ans = mid;
                end = mid-1;
            }
        }
        else
        {
            if(mid-1 >= 0 && arr[mid] == arr[mid-1])
            {
                // sb shi hai , ans right m hoga
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
    }
    return ans;
}

int main(){
    vector<int>arr{1 , 1 , 2 , 2 , 3 , 3 , 4 ,  5 , 5 , 6 , 6};
    
    int ans = singleElement(arr);
    
    cout<<"Single Element is = "<<arr[ans]<<endl;
}