// Min Heap approach
class KthLargest {
private: 
    int idx;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minH;

public:
    KthLargest(int k, vector<int>& nums) {
        this->idx = k;
        for (int num: nums) {
            minH.push(num);
            if (minH.size() > idx) {
                minH.pop();
            }
        }
    }
    
    int add(int val) {
        minH.push(val);
        if (minH.size() > idx) {
            minH.pop();
        }

        int top = minH.top();
        return top;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */