#include "bits/stdc++.h"

using namespace std;

struct Node{
    int val;
    int key;
    Node *next;
    Node *prev;

    Node(int k, int v): val(v), key(k), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    public:
        unordered_map<int, Node *> cache;
        int size =0;
        Node *head,*tail;

        void remove (Node * node){
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }

        void insertAtEnd(Node *node){
            node->prev = tail->prev;
            node->next = tail;
            tail->prev->next = node;
            tail->prev = node;
        }

        LRUCache(int capacity) {
            size = capacity;
            head = new Node(0,0);
            tail = new Node(0,0);
            head->next = tail;
            tail->prev = head;
        }
        
        int get(int key) {
            if(cache.find(key)==cache.end()){
                return -1;
            }
            Node *node = cache[key];
            remove(node);
            insertAtEnd(node);
            return node->val;
        }
        
        void put(int key, int value) {
            if(cache.find(key)!=cache.end()){
                Node *node = cache[key];
                node->val = value;
                remove(node);
                insertAtEnd(node);
            }
            else{
                if(cache.size() == size){
                    Node *node = head->next;
                    cache.erase(node->key);
                    remove(node);
                    delete node;
                }
                Node *newNode = new Node(key, value);
                cache[key] = newNode;
                insertAtEnd(newNode);
            }
        }
    };

int main(){
    int a, b, n;
    cin>>n;
    vector<string> arguments(n);
    cin>>a;
    LRUCache obj(a);
    for(int i=1;i<n;i++){
        cin>>arguments[i];
        if(arguments[i]=="put"){
            cin>>a>>b;
            obj.put(a,b);
        }
        else if(arguments[i]=="get"){
            cin>>a;
            cout<<obj.get(a)<<" ";
        }
    }
    return 0;
}