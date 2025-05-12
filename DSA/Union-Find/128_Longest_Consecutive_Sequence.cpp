#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        numSet.reserve(nums.size());  
        for (int num : nums) {
            numSet.insert(num);
        }        int longestStreak =0;
        
        for (int num: numSet){
            if (numSet.find(num-1) == numSet.end()){
                int currentNum = num;
                int currentStreak =1;
                
                while (numSet.find(currentNum+1)!= numSet.end()){
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak,currentStreak);
            }
        }
        return longestStreak;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums) << endl;  // Output: 4
    return 0;
}