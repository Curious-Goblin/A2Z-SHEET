#include <iostream>
#include <vector>
 
using namespace std;

void reverseArray(vector<int> &nums,int index){
    if(index >= nums.size()/2){
        return;
    }
    int top = nums[nums.size()-index-1];
    nums[nums.size()-index-1] = nums[index];
    nums[index]=top;
    reverseArray(nums,index+1);
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    reverseArray(nums,0);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}