#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int maxLength = 0;
        int start = 0;
        int end = 0;
        while (end < s.length()) {
            bool foundDuplicate = false;
            int duplicateIndex = -1;
            for (int i = start; i < end; ++i) {
                if (s[i] == s[end]) {
                    foundDuplicate = true;
                    duplicateIndex = i;
                    break;
                }
            }
            if (foundDuplicate) {
                start = duplicateIndex + 1;
            } else {
                count = end - start + 1;
                maxLength = max(maxLength, count);
            }
            end++;
        }
        return maxLength;
    }
};

int main() {
    Solution sol;

    sol.lengthOfLongestSubstring("aba");
    return 0;
}