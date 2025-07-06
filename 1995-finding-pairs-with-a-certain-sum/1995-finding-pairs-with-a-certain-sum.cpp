// Design + Hash Table approach
// TC: O((n + m) + q1 + (q2. n))
// SC: O(n + m)
class FindSumPairs {
private:
    vector<int> nums1, nums2;  // nums1 -> immutable, nums2 -> mutable
    unordered_map<int, int> freqMap; 

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num: nums2) {
            freqMap[num]++;
        }
    }
    
    void add(int index, int val) {
        freqMap[nums2[index]]--;
        nums2[index] += val;
        freqMap[nums2[index]]++;
    }
    
    int count(int tot) {
        // 2-sum problem
        int res = 0;
        for (int num: nums1) {
            int val = tot - num;
            if (freqMap.count(val)) {
                res += freqMap[val];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */