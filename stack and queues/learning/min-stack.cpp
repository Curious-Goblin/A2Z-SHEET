#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

struct List{
    int data;
    List *next;

    List(int val){
        data = val;
        next = nullptr;
    }
};

class MinStack {
    public:
    List *topNode = nullptr;
    List *minTop = nullptr;
    int minimum = INT_MAX;
        MinStack() {
        }
        
        void push(int val) {
            List *newNode = new List(val);
            newNode->next = topNode;
            topNode = newNode;
            int currentMin = (minTop == nullptr) ? val : min(val, minTop->data);
            List *newMinNode = new List(currentMin);
            newMinNode->next = minTop;
            minTop = newMinNode;
        }
        
        void pop() {
            topNode = topNode->next;
            minTop = minTop->next;
        }
        
        int top() {
            return topNode->data;
        }
        
        int getMin() {
            return minTop->data;
        }
};

int main(){
    int n,a;
    cin>>n;
    string s;
    vector<pair<string,int>> inputs(n);
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="MinStack" || s=="pop" || s=="getMin" || s=="top"){
            inputs[i] = {s,0};
        }
        else if(s=="push"){
            cin>>a;
            inputs[i]={s,a};
        }
    }
    MinStack stack;
    for(int i=1;i<n;i++){
        if(inputs[i].first ==  "push"){
            stack.push(inputs[i].second);
        }
        else if(inputs[i].first == "pop"){
            stack.pop();
        }
        else if(inputs[i].first == "top"){
            a = stack.top();
            cout<<a<<endl;
        }
        else if(inputs[i].first == "getMin"){
            a = stack.getMin();
            cout<<a<<endl;
        }
    }
    return 0;
}