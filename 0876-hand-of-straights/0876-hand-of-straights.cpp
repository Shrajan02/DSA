// Sorting + HashMap approach
// TC: O(n*logn + n*groupSize)
// SC: O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }

        ranges::sort(hand);  
        std::map<int, int> cardFreq; // {element, frequency}
        for (int card: hand) {
            cardFreq[card]++;
        }

        while (!cardFreq.empty()) {
            int currCard = cardFreq.begin()->first;  // smallest card

            // check for consecutive sequence
            for (int i = 0; i < groupSize; i++) {
                if (cardFreq[currCard + i] == 0) {
                    return false;
                }
                cardFreq[currCard + i]--;
                if (cardFreq[currCard + i] < 1) {
                    cardFreq.erase(currCard + i);
                }
            }
        }

        return true;
    }
};