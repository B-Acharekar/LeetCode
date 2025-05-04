#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combined(nums1.size() + nums2.size());
        int i = 0, j = 0, k = 0;

        while(i < nums1.size()){
            combined[k++] = nums1[i++];
        }
        while (j < nums2.size()) {
            combined[k++] = nums2[j++];
        }

        sort(combined.begin(), combined.end());

        int n = combined.size();
        if(n % 2 == 1){
            return combined[n/2];
        } else {
            return (combined[n/2 - 1] + combined[n/2]) / 2.0;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};

    double median = sol.findMedianSortedArrays(nums1, nums2);

    cout << "Median is: " << median << endl;

    return 0;
}
