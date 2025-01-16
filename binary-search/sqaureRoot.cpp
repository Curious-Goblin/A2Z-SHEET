#include "iostream"

using namespace std;

int floorSqrt(int n)
{
    int low =1,high = n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if((mid*mid)==n){
            return mid;
        }
        else if((mid*mid)>n){
            high = mid-1;
        }
        else if((mid*mid)<n){
            low = mid+1;
        }
    }
    return high;
}

int main()
{
    int n;
    cin >> n;
    int result = floorSqrt(n);
    cout<<result;
    return 0;
}