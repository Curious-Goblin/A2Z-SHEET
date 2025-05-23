#include "bits/stdc++.h"

using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class LRU
{
public:
    unordered_map<int, Node *> cache;
    Node *head;
    Node *tail;
    int capacity;

    LRU(int capacity)
    {
        this->capacity = capacity;
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }

    void add(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = tail;
        newNode->prev = tail->prev;
        tail->prev->next = newNode;
        tail->prev = newNode;
        cache[val] = newNode;

        if (cache.size() > capacity)
        {
            Node *lru = head->next;
            cache.erase(lru->data);
            remove(lru);
        }
    }

    void remove(Node *node)
    {
        Node *temp = node->prev;
        Node *next = node->next;
        temp->next = next;
        next->prev = temp;
        delete (node);
    }
    int get(int val)
    {
        if (cache.find(val) != cache.end())
        {
            auto it = cache.find(val);
            cache.erase(val);
            remove(it->second);
            add(val);
            return 1;
        }
        add(val);
        return -1;
    }
};

class Solution
{
public:
    int pageFaults(int N, int C, int pages[])
    {
        LRU solution(C);
        int pageFaults = 0, result = 0;
        for (int i = 0; i < N; i++)
        {
            result = solution.get(pages[i]);
            if (result == -1)
            {
                pageFaults++;
            }
        }
        return pageFaults;
    }
};

int main()
{
    int n, c;
    cin >> n >> c;
    int pages[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    Solution solve;
    cout << solve.pageFaults(n, c, pages);
    return 0;
}