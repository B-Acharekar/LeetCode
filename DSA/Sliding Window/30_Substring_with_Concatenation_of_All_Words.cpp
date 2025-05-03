#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        if (words.empty() || s.empty()) return result;

        int word_len = words[0].size();
        int word_count = words.size();
        int total_len = word_len * word_count;

        if (s.length() < total_len) return result;

        unordered_map<string, int> word_freq;
        for (string& word : words) {
            word_freq[word]++;
        }

        for (int i = 0; i < word_len; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int right = i; right + word_len <= s.length(); right += word_len) {
                string word = s.substr(right, word_len);

                if (word_freq.find(word) != word_freq.end()) {
                    seen[word]++;
                    count++;

                    while (seen[word] > word_freq[word]) {
                        string left_word = s.substr(left, word_len);
                        seen[left_word]--;
                        left += word_len;
                        count--;
                    }

                    if (count == word_count) {
                        result.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right + word_len;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar", "foo", "the"};
    vector<int> result = sol.findSubstring(s, words);

    for (int idx : result) {
        cout << idx << " ";
    }
    return 0;
}
