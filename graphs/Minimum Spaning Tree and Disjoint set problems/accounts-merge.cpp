#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> par;
    vector<int> rank;
    void construct(int n) {
        rank.resize(n, 0);
        par.resize(n);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }
    int find(int x) {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    void unionFind(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        else {
            if (rank[pu] < rank[pv])
                par[pu] = pv;
            else if (rank[pu] > rank[pv])
                par[pv] = pu;
            else {
                par[pv] = pu;
                rank[pu]++;
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        construct(n);
        map<string, int> m;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                auto it = m.find(accounts[i][j]);
                if (it == m.end()) {
                    m[accounts[i][j]] = i;
                } else {
                    unionFind(it->second, i);
                }
            }
        }
        unordered_map<int, set<string>> merged;
        for (int i = 0; i < n; i++) {
            int parent = find(i);
            for (int j = 1; j < accounts[i].size(); j++) {
                merged[parent].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> result;
        for (auto& entry : merged) {
            vector<string> acc;
            acc.push_back(accounts[entry.first][0]);
            acc.insert(acc.end(), entry.second.begin(), entry.second.end());
            result.push_back(acc);
        }
        return result;
    }
};

int main(){
    int n,a;
    cin>>n;
    string s="";
    vector<vector<string>> accounts(n);
    for(int i=0;i<n;i++){
        cin>>a;
        for(int j=0;j<a;j++){
            cin>>s;
            accounts[i].push_back(s);
        }
    }
    Solution sol;
    vector<vector<string>> result = sol.accountsMerge(accounts);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}