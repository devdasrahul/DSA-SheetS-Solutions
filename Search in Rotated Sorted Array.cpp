#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Output for nums1: " << sol.search(nums1, target1) << endl; // Output: 4

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << "Output for nums2: " << sol.search(nums2, target2) << endl; // Output: -1

    vector<int> nums3 = {1};
    int target3 = 0;
    cout << "Output for nums3: " << sol.search(nums3, target3) << endl; // Output: -1

    return 0;
}
