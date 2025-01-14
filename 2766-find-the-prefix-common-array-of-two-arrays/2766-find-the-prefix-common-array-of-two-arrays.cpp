class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n, 0); // result
        vector<int> freq(n + 1, 0); // frequency array (1-indexed)
        
        for (int i = 0; i < n; i++) {
            int prefixSum = 0;
            freq[A[i]]++;
            freq[B[i]]++;

            for (int j = 1; j <= n; j++) {
                if (freq[j] == 2) {
                    prefixSum++;
                }
            }
            C[i] = prefixSum;
        }
        return C;
    }
};