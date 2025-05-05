#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            if (digits.empty())
                return {};
    
            vector<string> result;
            string current;
            vector<string> phoneMap = {"",    "",    "abc",  "def", "ghi",
                                       "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
            backtrack(digits, 0, current, result, phoneMap);
            return result;
        };
    
    private:
        void backtrack(const string& digits, int index, string& current,
                       vector<string>& result, const vector<string>& phoneMap) {
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }
            string letters = phoneMap[digits[index] - '0'];
            for (char letter : letters) {
                current.push_back(letter);
                backtrack(digits, index + 1, current, result, phoneMap);
                current.pop_back();
            }
        }
    };

int main()
{
    Solution sol;
    string input = "23";
    vector<string> output = sol.letterCombinations(input);

    for (const string &combination : output)
    {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
