#include "bits/stdc++.h"

using namespace std;

// class StockSpanner {
//     public:
//         stack<int> stocks;
//         unordered_map<int, int> stockSpan;
//         int count;
//         StockSpanner() {}
    
//         int next(int price) {
//             count = 1;
//             while (!stocks.empty() && stocks.top() <= price) {
//                 auto it = stockSpan.find(stocks.top());
//                 count += it->second;
//                 stocks.pop();
//             }
//             stocks.push(price);
//             stockSpan[price] = count;
//             return count;
//         }
//     };

class StockSpanner {
    public:
        stack<pair<int,int>> stocks;
        int count;
        StockSpanner() {}
    
        int next(int price) {
            count = 1;
            while (!stocks.empty() && stocks.top().first <= price) {
                count += stocks.top().second;
                stocks.pop();
            }
            stocks.push({price, count});
            return count;
        }
    };

int main(){
    int n,result=0;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<string> arguments(n+1);
    for(int i=0;i<=n;i++){
        cin>>arguments[i];
    }
    StockSpanner stock;
    for(int i=1;i<=n;i++){
        result = stock.next(nums[i-1]);
        cout<<result<<" ";
    }
    return 0;
}