class Solution {
public:
    bool calculateSpeed(vector<int>& piles, int v, int h) {
        long long total = 0;
        for (int i = 0; i < piles.size(); i++) {
            total += (ceil)((double)piles[i] / v);
        }
        return (total <= h);
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxi;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            bool possible = calculateSpeed(piles, mid, h);
            if (possible)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return low;
    }
};