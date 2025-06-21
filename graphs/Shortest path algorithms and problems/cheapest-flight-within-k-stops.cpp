#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<pair<int,int>>> buildAdList(int V, vector<vector<int>> &edges){
        vector<vector<pair<int,int>>> result(V);
        for(int i=0;i<edges.size();i++){
            result[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        return result;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        vector<vector<pair<int,int>>> adlist = buildAdList(n, flights);
        vector<vector<int>> visited(n, vector<int>(k+2, INT_MAX));
        vector<int> cost(n, INT_MAX);
        vector<int> stops(n,0);
        pq.push({0,0,src});
        cost[src] = 0;
        while(!pq.empty()){
            auto element = pq.top();
            pq.pop();

            int currCost = get<0>(element);
            int currStops = get<1>(element);
            int node = get<2>(element);

            if(node == dst) return currCost;
            if(currStops > k) continue;

            if(visited[node][currStops] <= currCost) continue;
            visited[node][currStops] = currCost;

            for(auto &edges:adlist[node]){

                int nextNode = edges.first;
                int weight = edges.second;

                if(currStops <= k){
                    pq.push({currCost + weight, currStops + 1, nextNode});
                }
            }
        }
        return -1;
    }
};

int main(){
    int n, edges, src, dst, k;
    cin>>n>>edges>>src>>dst>>k;
    vector<vector<int>> flights(edges, vector<int>(3));
    for(int i=0;i<edges;i++){
        cin>>flights[i][0]>>flights[i][1]>>flights[i][2];
    }
    Solution sol;
    cout<<sol.findCheapestPrice(n, flights, src, dst, k);
    return 0;
}