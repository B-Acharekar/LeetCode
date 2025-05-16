#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i = 0;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    Solution sol;
    int k = sol.removeDuplicates(nums);

    cout << "k = " << k << "\n";
    cout << "Updated array: ";
    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";

    return 0;
}
