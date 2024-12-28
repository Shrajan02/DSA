class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> hashTable;
        for (int num : arr) {
            if (hashTable.count(num * 2) || (num % 2 == 0 && hashTable.count(num / 2))) {
                return true;
            }
            hashTable.insert(num);
        }
        return false;
    }
};
