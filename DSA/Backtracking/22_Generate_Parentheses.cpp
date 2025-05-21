#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backtrack(int open, int close, string current, vector<string>& result) {
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }

        // add an opening parenthesis if any left
        if (open > 0) {
            backtrack(open - 1, close, current + '(', result);
        }

        // add a closing parenthesis if it won't make the string invalid
        if (close > open) {
            backtrack(open, close - 1, current + ')', result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n, n, "", result);
        return result;
    }
};

int main() {
    Solution solution;
    int n = 3; 
    vector<string> combinations = solution.generateParenthesis(n);

    cout << "Generated Parentheses for n = " << n << ":\n";
    for (const string& s : combinations) {
        cout << s << endl;
    }

    return 0;
}
