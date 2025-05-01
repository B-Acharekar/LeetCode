#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> stk;
            unordered_map<char, char> bracket_map = {
                {')', '('}, {']', '['}, {'}', '{'}};
            for (char c : s) {
                if (c == '(' || c == '[' || c == '{') {
                    stk.push(c);
                } else {
                    if (stk.empty() || stk.top() != bracket_map[c]) {
                        return false;
                    }
                    stk.pop();
                }
            }
            return stk.empty();
        }
    };

int main() {
    string s = "()[]{}"; // You can change this input for testing
    Solution sol;

    bool result = sol.isValid(s);
    cout << boolalpha << "Is valid? " << result << endl;

    return 0;
}