// Priority Queue + Map approach
// TC: O(n*logn)
// SC: O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }

        std::unordered_map<int, int> freqMap;
        for (int card: hand) {
            freqMap[card]++;
        }

        // push unique cards to heap
        std::priority_queue<int, std::vector<int>, std::greater<int>> minH;
        for (auto [card, _]: freqMap) {
            minH.push(card);
        }

        while (!minH.empty()) {
            int smallest = minH.top();

            // skip card that are already used up
            if (freqMap[smallest] == 0) {
                minH.pop();
                continue;
            }

            // check consecutive group of cards exist
            // DO NOT pop in the middle of group formation
            for (int i = 0; i < groupSize; i++) {
                int currCard = smallest + i;
                if (freqMap[currCard] == 0) {
                    return false;
                }

                freqMap[currCard]--;
            }
        }

        return true;
    }
};