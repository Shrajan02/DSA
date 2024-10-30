class Solution {
public:
    long long calculateSum(vector<int>& nums, int divisor) {
        long long sum = 0;
        for (auto num : nums) {
            sum += ceil(double(num) / divisor);  // appropriate typecasting
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = nums[0];
        for (auto i : nums) {
            maxi = max(i, maxi);
        }

        int low = 1, // start with 1 to not miss the smallest possible
                     // divisor that could satisfy the threshold
            high = maxi;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long result = calculateSum(nums, mid);
            if (result <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};