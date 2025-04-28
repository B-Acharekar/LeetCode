#include <iostream>
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
           if(s.empty()){
            return "";
           }
           int start = 0;
           int maxLength = 1;

           for (int i = 0 ; i<s.length();i++){
            expandAroundCenter(s,i,i,start,maxLength);
            expandAroundCenter(s,i,i+1,start,maxLength);
           }
           return s.substr(start, maxLength);
        }
        private:
        void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLength) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
    
            if (right - left - 1 > maxLength) {
                start = left + 1;  
                maxLength = right - left - 1;  
            }
        }
    };
    
    int main() {
        Solution sol;
        string input = "babad";
        string result = sol.longestPalindrome(input);
        cout << "Longest palindromic substring: " << result << endl;  // Output: "bab" or "aba"
        return 0;
    }