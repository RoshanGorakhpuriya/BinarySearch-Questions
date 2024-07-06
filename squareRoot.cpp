#include<iostream>
using namespace std;

int squareRoot(int n)
{
    int start = 0;
    int end = n;
    int mid = (start + end)/2;

    while(start <= end)
    {
        if(mid * mid == n)
        {
            return mid;
        }
        else if(mid * mid > n)
        {
            end = mid - 1;
        }
        else if(mid * mid < n)
        {
            start = mid + 1;
        }
        mid = (start + end)/2;
    }
    return mid;
}

int main(){
    int n;
    cout<<"Enter n\n";
    cin>>n;

    int ans = squareRoot(n);

    cout<<"Answer is = "<<ans<<endl;


}