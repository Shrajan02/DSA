// Frequency Sort approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result;

        // construct frequency array
        std::vector<int> frequency(201, 0);
        for (int num: nums) {
            frequency[num + 100]++;
        }

        // form buckets by frequency
        std::vector<vector<int>> buckets(n + 1);
        for (int val = -100; val <= 100; val++) {
            int count = frequency[val + 100];
            if (count > 0) {
                buckets[count].push_back(val);
            }
        } 

        // process buckets from high to low frequency
        for (int i = 1; i <= n; i++) {
            vector<int> temp = buckets[i];
            int bucket_size = temp.size();
            
            // already in descending order from 100 to -100
            for (int j = bucket_size - 1; j >= 0; j--) {
                int counter = i;
                while (counter--) {
                    result.push_back(temp[j]);
                }
            }
        }

        return result;
    }
};