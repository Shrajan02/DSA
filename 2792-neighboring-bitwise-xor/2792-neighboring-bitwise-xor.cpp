class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // XOR of all elements must be 0 for original array to form a valid cyclic sequence
        // Commutativity: a⊕b = b⊕a
        // Associativity: (a⊕b)⊕c = a⊕(b⊕c)
        int sum = 0;
        for (int i: derived) {
            sum ^= i;
        }
        return (sum == 0);
    }
};