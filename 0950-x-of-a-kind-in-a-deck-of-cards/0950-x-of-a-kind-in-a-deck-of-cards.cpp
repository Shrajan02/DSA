#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric> // For gcd function

class Solution {
public:
    bool hasGroupsSizeX(std::vector<int>& deck) {
        unordered_map<int, int> hashTable;

        // Count the frequency of each card
        for (int card : deck) {
            hashTable[card]++;
        }

        // Find the GCD of all frequencies
        int gcdValue = 0; 
        for (const auto& pair : hashTable) {
            gcdValue = gcd(gcdValue, pair.second);
            // If at any point the GCD becomes 1, we can stop early
            if (gcdValue == 1) 
                return false;
        }

        return (gcdValue > 1);
    }
};
