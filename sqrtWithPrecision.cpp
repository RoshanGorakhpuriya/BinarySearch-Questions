#include<iostream>
using namespace std;

int squareRoot(int n)
{
    int start = 0;
    int end = n;
    int mid = (start + end)/2;
    int ans = -1;
    
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
        else
        {
            ans = mid;
            start = mid + 1;
        }
        mid = (start + end)/2;
    }
    return ans;
}

double squareRootM2(int n)
{
    double start = 0;
    double end = n;
    double mid = (start + end)/2;
    double ans = -1;
    

    // start < end 
    // 0 < (end - start)
    // (end - start) > 0  we are not doing for interger we are doing for precision
    // (end - start) > 0.00001
    while((end - start)  >= 0.00000000000001)
    {
        if(mid * mid == n)
        {
            return mid;
        }
        else if(mid * mid > n)
        {
            end = mid;
            // agr mid+1 kr de tho mid<->mid+1 m bhi ans ho skta hai in float range m isliye mid+1 ni kiya only mid hi kiya
        }
        else
        {
            ans = mid;
            start = mid;
        }
        mid = (start + end)/2;
    }
    return ans;
}

double precisionSqrt(int n)
{
    double sqrt = squareRoot(n); 
    int precision = 13;
    double step = 0.1;
    
     while(precision--)
    {
        double j = sqrt; // hr step pe increase krne k liye use hua hai
        while(j * j <= n)
        {
            sqrt = j; // jo bhi shi ans hai usko update kr rh hai as the final ans;
            j = j + step;
            // hr step pe bad rha hai step ki duration s;
        }
        step = step / 10;
    }
    return sqrt;
}

int main(){
    int n;
    cout<<"Enter n\n";
    cin>>n;

    double finalAnsM2 = squareRootM2(n);
    cout<<finalAnsM2<<endl;
    
    int ans = squareRoot(n);
    cout<<"Answer is = "<<ans<<endl;
    
    double finalAns = precisionSqrt(n);
    // cout<<"Answer is = "<<finalAns<<endl;
    
    // cout only 5 value print krta hai;
    // to get more use printf function
    printf("Precision Sqrt : %.13f\n" , finalAns);

    double ans2 = squareRootM2(n);
    printf("Precision Sqrt : %.13f\n" , ans2);

}