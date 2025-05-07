#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    // O(NlogK) ~ O(N) since k is constant(26)
        int leastInterval(vector<char>& tasks, int n) {
            vector<int> freq(26,0);
            for(char &ch: tasks){
                freq[ch-'A']++;
            }

            priority_queue<int> pq;
            for(int &i: freq){
                if(i>0){
                    pq.push(i);
                }
            }

            int time = 0;
            while(!pq.empty()){
                int cycle = n+1;
                vector<int> store;
                int taskCount = 0;

                while(cycle-- && !pq.empty()){
                    if(pq.top()>1){
                        store.push_back(pq.top()-1);
                    }
                    pq.pop();
                    taskCount++;
                }

                for(int &i: store){
                    pq.push(i);
                }

                time += (pq.empty() ? taskCount : n + 1);
            }
            return time;
        }
    };

int main(){
    int n,m;
    cin>>n>>m;
    vector<char> tasks(n);
    for(int i = 0; i < n; i++){
        cin>>tasks[i];
    }
    Solution s;
    cout<<s.leastInterval(tasks, m);
    return 0;
}