#include<iostream>
using namespace std;

int findQuotient(int divident , int divisor)
{
  int start = 0;
  int end = divident;
  int ans = -1;
  int mid = start + (end - start)/2;

  while(start <= end)
  {
    int res = mid * divisor;
    if(divident == res)
    {
      return mid;
    }
    else if(divident > res)
    {
      ans = mid;
      start = mid + 1;
    }
    else 
    {
      end = mid - 1;
    }
    mid = start + (end - start)/2;
  }
  return ans;
}

int main(){
  int divident = -16;
  int divisor = -4;

  int result = findQuotient(abs(divident) , abs(divisor));
  if(divident <= 0 && divisor >=0  || divident >= 0 && divisor <= 0)
  {
    result = result * -1;
  }
  else
  {
    result = result * 1;
  }
  cout<<"Result is = "<<result<<endl;
}