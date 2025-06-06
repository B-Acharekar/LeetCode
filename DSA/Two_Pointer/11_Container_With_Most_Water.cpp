#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left =0;
            int right = height.size()-1;
            int max_area = 0;

            while(left<right){
                int h = min(height[left],height[right]);
                int w = right -left;
                int area = h*w;
                max_area = max(max_area,area);

                if (height[left]<height[right]){
                    left += 1;
                }else{
                    right -=1;
                }
            }
            return max_area;
        }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; 

    Solution sol;
    int result = sol.maxArea(height);

    cout << "Maximum area: " << result << endl;

    return 0;
}