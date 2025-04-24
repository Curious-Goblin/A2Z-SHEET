// #include "bits/stdc++.h"

// using namespace std;

// // int minBitFlips(int start, int goal)
// // {
// //     vector<int> startBits, goalBits;
// //     int temp1 = start, temp2 = goal;
// //     while (start > 0)
// //     {
// //         startBits.push_back(start % 2);
// //         start = start / 2;
// //     }
// //     while (goal > 0)
// //     {
// //         goalBits.push_back(goal % 2);
// //         goal = goal / 2;
// //     }
// //     if (startBits.size() > goalBits.size())
// //     {
// //         while (goalBits.size() != startBits.size())
// //         {
// //             goalBits.push_back(0);
// //         }
// //     }
// //     else if (startBits.size() < goalBits.size())
// //     {
// //         while (goalBits.size() != startBits.size())
// //         {
// //             startBits.push_back(0);
// //         }
// //     }
// //     int count = 0;
// //     for (int i = 0; i < startBits.size(); i++)
// //     {
// //         if (startBits[i] != goalBits[i])
// //             count++;
// //     }
// //     return count;
// // }

// class Solution{
//     public:
//     // O(set bits in start ^ goal)
//     int minBitFlips(int start, int goal){
//         int count = 0;
//         start = start ^ goal;
//         while(start!=0){
//             start = start & (start-1);
//             count++;
//         }
//         return count;
//     }
// };

// int main()
// {
//     int start, goal;
//     cin >> start >> goal;
//     Solution s;
//     cout << s.minBitFlips(start, goal);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int fib = round(pow(1.618,n)/sqrt(5));
    cout<<fib<<endl;
}