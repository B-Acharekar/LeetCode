#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";

        unordered_map<char, int> t_freq;
        for (char c : t)
            t_freq[c]++;

        int required = t_freq.size();
        int left = 0, right = 0;
        int formed = 0;
        unordered_map<char, int> window_counts;

        int min_len = INT_MAX, min_left = 0;

        while (right < s.size()) {
            char c = s[right];
            window_counts[c]++;

            if (t_freq.count(c) && window_counts[c] == t_freq[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_left = left;
                }

                char left_char = s[left];
                window_counts[left_char]--;
                if (t_freq.count(left_char) &&
                    window_counts[left_char] < t_freq[left_char]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum window substring: " << minWindow(s, t) << endl;
    return 0;
}
