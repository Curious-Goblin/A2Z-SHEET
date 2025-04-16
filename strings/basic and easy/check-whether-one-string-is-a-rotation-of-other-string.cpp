#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    // o(3n) s(n)
    // bool rotateString(string s, string goal)
    // {
    //     if(s.length()!=goal.length()){
    //         return false;
    //     }
    //     char first_character_goal = goal[0];
    //     int a;
    //     string rotated = "";
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         if (s[i] == first_character_goal)
    //         {
    //             a = i;
    //         }
    //     }
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         if (i >= a)
    //         {
    //             rotated += s[i];
    //         }
    //     }
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         if (i < a)
    //         {
    //             rotated += s[i];
    //         }
    //     }
    //     if(rotated==goal){
    //         return true;
    //     }
    //     return false;
    // }

    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
        {
            return false;
        }
        string doubled = s+s;
        if(doubled.find(goal)!=string::npos){
            return true;
        }
        return false;
    }
};

int main()
{
    string s, goal;
    cin >> s >> goal;
    Solution solve;
    bool result = solve.rotateString(s, goal);
    cout << result;
}