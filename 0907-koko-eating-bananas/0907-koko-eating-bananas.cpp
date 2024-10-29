class Solution {
public:
    long long calculateHours(vector<int>& piles, int hourly) {
        long long totalHours = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalHours += ceil((double)piles[i] / hourly);
        }
        return totalHours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = piles[0];
        long long result;

        // Finding max element
        for (int i = 1; i < piles.size(); i++) {
            maxi = max(piles[i], maxi);
        }
        
        // Binary Search
        int low = 1, high = maxi;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            result = calculateHours(piles, mid);
            if (result > h) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};