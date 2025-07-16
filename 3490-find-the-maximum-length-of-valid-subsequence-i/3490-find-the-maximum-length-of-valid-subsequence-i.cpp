// Greedy counting approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // if same -> even => count(max(odd, even))
        // if different -> odd => count(alternate)

        // [1,2,3,4,5,7,9,12,14,15,16,17,18,19]
        // [odd,even,odd,even,odd,odd,odd,even,even,odd,even,odd,even,odd]
        // odd -> 8, even -> 6
        // odd-even -> 11, even-odd -> 10

        // count odd & even
        int odds = 0, evens = 0;
        for (int num: nums) {
            (num % 2 == 0) ? evens++ : odds++;
        }

        // count alternate combinations between odd & even 
        int alts = 0;
        bool expectOdd = true, expectEven = true;
        for (int num: nums) {
            if (num % 2 == 0 && expectEven) {
                alts++;
                expectEven = false;
                expectOdd = true;
            }
            else if (num % 2 == 1 && expectOdd) {
                alts++;
                expectOdd = false;
                expectEven = true;
            }
        }

        int maxSub = max({odds, evens, alts});
        return maxSub;
    }
};