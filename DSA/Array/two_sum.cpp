#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        
        for (int i=0; i <nums.size();i++){
            int complement = target -nums[i];
            
            if(numMap.find(complement) != numMap.end()){
                return{numMap[complement],i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Standard test case with a solution
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);
    if (!result1.empty()) {
        cout << "Test case 1 - Indices: " << result1[0] << ", " << result1[1] << endl; // Expected: 0, 1
    } else {
        cout << "Test case 1 - No two sum solution found." << endl;
    }

    // Test case 2: No solution available
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int target2 = 10;
    vector<int> result2 = sol.twoSum(nums2, target2);
    if (!result2.empty()) {
        cout << "Test case 2 - Indices: " << result2[0] << ", " << result2[1] << endl;
    } else {
        cout << "Test case 2 - No two sum solution found." << endl; // Expected: No solution
    }

    // Test case 3: Multiple pairs, first valid pair found
    vector<int> nums3 = {3, 2, 4, 7};
    int target3 = 6;
    vector<int> result3 = sol.twoSum(nums3, target3);
    if (!result3.empty()) {
        cout << "Test case 3 - Indices: " << result3[0] << ", " << result3[1] << endl; // Expected: 1, 2
    } else {
        cout << "Test case 3 - No two sum solution found." << endl;
    }

    // Test case 4: Negative numbers involved
    vector<int> nums4 = {-3, 4, 3, 90};
    int target4 = 0;
    vector<int> result4 = sol.twoSum(nums4, target4);
    if (!result4.empty()) {
        cout << "Test case 4 - Indices: " << result4[0] << ", " << result4[1] << endl; // Expected: 0, 2
    } else {
        cout << "Test case 4 - No two sum solution found." << endl;
    }

    // Test case 5: Single element, no solution
    vector<int> nums5 = {1};
    int target5 = 2;
    vector<int> result5 = sol.twoSum(nums5, target5);
    if (!result5.empty()) {
        cout << "Test case 5 - Indices: " << result5[0] << ", " << result5[1] << endl;
    } else {
        cout << "Test case 5 - No two sum solution found." << endl; // Expected: No solution
    }
    
    return 0;
}