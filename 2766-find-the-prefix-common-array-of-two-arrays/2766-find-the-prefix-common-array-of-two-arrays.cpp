// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n, 0); // result
        vector<int> freq(n + 1, 0); // frequency array (1-indexed)
        
        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            if (freq[A[i]] == 2) 
                prefixSum++;

            freq[B[i]]++;
            if (freq[B[i]] == 2) 
                prefixSum++;

            C[i] = prefixSum;
        }
        
        return C;
    }
};