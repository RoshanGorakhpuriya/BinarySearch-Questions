#include<iostream>
using namespace std;

int firstOccurence(int arr[] , int start , int end , int target){
    int ansIndex = -1;
    int mid = (start + end)/2;

    while(start <= end)
    {
        if(arr[mid] == target)
        {
            ansIndex = mid;
            end = mid - 1;
        }
        else if(arr[mid] > target)
        {
            end = mid - 1;
        }
        else if(arr[mid] < target)
        {
            start = mid + 1;
        }
        mid = (start + end)/2;
    }
    return ansIndex;
}

int lastOccurence(int arr[] , int start , int end , int target){
    int ansIndex = -1;
    int mid = (start + end)/2;

    while(start <= end)
    {
        if(arr[mid] == target)
        {
            ansIndex = mid;
            start = mid + 1;
        }
        else if(arr[mid] > target)
        {
            end = mid - 1;
        }
        else if(arr[mid] < target)
        {
            start = mid + 1;
        }
        mid = (start + end)/2;
    }
    return ansIndex;
}


int main(){
    int arr[5] = {10 , 10  , 10 , 60 , 60};

    int start = 0;
    int end = 4;
    int ansIndex = -1;
    int target = 10;

    int first = firstOccurence(arr , start , end , target );

    int last = lastOccurence(arr , start , end , target);

    int total = last - first + 1;

    cout<<"Total Occurence of element is = "<<total<<endl;
}