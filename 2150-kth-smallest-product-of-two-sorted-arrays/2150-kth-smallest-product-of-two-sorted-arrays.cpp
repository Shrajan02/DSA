// Binary Search on Answer + Binary Search approach
// TC: O(log(high - low) * n * log(m))
// SC: O(1)
using ll = long long;
class Solution {
private:
    // check how many products are smaller than or equal to the target product
    ll findCountSmallest(vector<int>& nums1, vector<int>& nums2, ll targetProduct) {
        int n = nums1.size(), m = nums2.size();
        ll productCount = 0;

        // nums1[i] * BS on nums2[j]
        for (int i = 0; i < n; i++) {
            // product will be negative & right side contains smaller products & left side contains larger products
            if (nums1[i] < 0) {
                int left = 0, right = m - 1;
                int firstValidIndex = m;    // init to right invalid bound
                while (left <= right) {
                    int mid = left + ((right - left) >> 1);
                    ll product = 1LL * nums1[i] * nums2[mid];

                    if (product <= targetProduct) {
                        firstValidIndex = mid;
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                productCount += (m - firstValidIndex);   // {-5, -15, -20, -30}
            } 

            else {
                int left = 0, right = m - 1;
                int lastValidIndex = -1;   // init to left invalid bound
                while (left <= right) {
                    int mid = left + ((right - left) >> 1);
                    ll product = 1LL * nums1[i] * nums2[mid];

                    if (product <= targetProduct) {
                        lastValidIndex = mid;
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                productCount += (lastValidIndex + 1);
            }
        }
        
        return productCount;
    }

public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll result = 0;
        ll low = -1e10; // minimum possible value
        ll high = 1e10; // maximum possible value

        while (low <= high) {
            ll midProduct = low + ((high - low) >> 1);

            // check if this product is kth smallest or not
            ll smallestCount = findCountSmallest(nums1, nums2, midProduct);

            if (smallestCount >= k) {
                result = midProduct;
                high = midProduct - 1;
            } 
            else {
                low = midProduct + 1;
            }
        }

        return result;
    }
};