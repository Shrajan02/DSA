class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0;
        while (k > 0) {
            int maxi = INT_MIN, pile = 0;
            for (int i = 0; i < gifts.size(); i++) {
                if (gifts[i] > maxi) {
                    maxi = gifts[i];
                    pile = i;
                }
            }
            gifts[pile] = sqrt(maxi);
            k--;
        }

        for (int i: gifts) {
            sum += i;
        }
        return sum;
    }
};