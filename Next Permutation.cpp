class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = n - 2;

        // Step 1: Find the first decreasing element from the end
        while (index >= 0 && nums[index] >= nums[index + 1]) {
            index--;
        }

        if (index < 0) {
            // Entire array is in descending order, just reverse it
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find element just larger than nums[index] from the end
        int high = n - 1;
        while (high > index && nums[high] <= nums[index]) {
            high--;
        }

        // Step 3: Swap
        swap(nums[index], nums[high]);

        // Step 4: Reverse the suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};
