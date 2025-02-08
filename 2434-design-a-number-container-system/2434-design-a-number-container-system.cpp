class NumberContainers {
private:
    unordered_map<int, int> container;  // {index -> number}
    unordered_map<int, set<int>> sorted;  // {number -> sorted(indices)}

public:
    NumberContainers() {}

    // insert or replace: O(logn)
    void change(int index, int number) {
        // remove old mapping if index exists
        if (container.find(index) != container.end() && container[index] != number) {
            int oldNum = container[index];
            sorted[oldNum].erase(index);
            if (sorted[oldNum].empty()) {
                sorted.erase(oldNum);
            }
        }

        // update mappings
        container[index] = number;
        sorted[number].insert(index);
    }

    // find the smallest index : O(1)
    int find(int number) {
        if (sorted[number].empty()) {
            return -1;
        }
        return *sorted[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index, number);
 * int param_2 = obj->find(number);
 */
