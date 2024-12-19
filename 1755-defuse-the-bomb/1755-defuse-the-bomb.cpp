class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        if (k == 0)
            return result;

        for (int i = 0; i < n; i++) {
            int temp = abs(k);
            int j = i, sum = 0;
            while (temp--) {
                if (k > 0) {
                    j = (j + 1) % n;
                }  
                else {
                    j = (j - 1 + n) % n;
                }   
                sum += code[j];
            }
            result[i] = sum;
        }

        return result;
    }
};