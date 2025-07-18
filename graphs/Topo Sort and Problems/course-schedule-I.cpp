#include "bits/stdc++.h"

using namespace std;

class Solution{
    private:
    vector<vector<int>> buildAdList(int V, vector<vector<int>> &edges){
        map<int, set<int>> adlist;
        vector<vector<int>> result(V);

        for(int i=0;i<edges.size();i++){
            adlist[edges[i][1]].insert(edges[i][0]);
        }

        for(auto &it:adlist){
            result[it.first] = vector<int>(it.second.begin(), it.second.end());
        }
        return result;
    }
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adlist = buildAdList(numCourses, prerequisites);
        queue<int> qu;
        vector<int> inDegree(numCourses, 0);
        vector<int> result;
        for(int i=0;i<numCourses;i++){
            for(int &neighbor:adlist[i]){
                inDegree[neighbor]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                qu.push(i);
            }
        }
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            result.push_back(node);
            for(int& it:adlist[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    qu.push(it);
                }
            }
        }
        if(result.size() < numCourses) return false;

        return true;
    }
};

int main(){
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges(e, vector<int>(2));
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution sol;
    cout<<sol.canFinish(v, edges)<<endl;
    return 0;
}