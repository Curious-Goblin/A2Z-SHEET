#include "bits/stdc++.h"

using namespace std;

class Solution{
    private:
    vector<vector<int>> buildAdList(int numCourses, vector<vector<int>> &prerequisites){
        map<int, set<int>> adlist;
        vector<vector<int>> result(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            adlist[prerequisites[i][1]].insert(prerequisites[i][0]);
        }

        for(auto &it:adlist){
            result[it.first] = vector<int>(it.second.begin(), it.second.end());
        }
        return result;
    }
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites){
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
        if(result.size()<numCourses){
            return {};
        }
        return result;
    }
};

int main(){
    int numCourses, E;
    cin >> numCourses >> E;
    vector<vector<int>> prerequisites(E, vector<int>(2));
    for (int i = 0; i < E; i++)
    {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    Solution sol;
    vector<int> result = sol.findOrder(numCourses, prerequisites);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}