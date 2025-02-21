#include "bits/stdc++.h"

using namespace std;


/*
the question was to give the kth largest element so we create a minheap which is having the k largest
element from the vector and then the top element will be the kth largerst element and thats the answer*/ 
class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int num : nums)
        {
            minHeap.push(num);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if(minHeap.size()>k){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
