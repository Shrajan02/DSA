// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int asteroid : asteroids) {
            bool destroyed = false;
            // when collision occurs
            while (!st.empty() && st.top() > 0 && asteroid < 0) {
                int top = st.top();
                if (abs(top) == abs(asteroid)) {
                    st.pop();  // both destroy each other
                } 
                else if (abs(top) < abs(asteroid)) {
                    st.pop();  // destroy +ve top 
                    continue;  // current persists
                }
                destroyed = true;  
                break;         // current is destroyed
            }
            if (!destroyed) {
                st.push(asteroid);
            }
        }

        int rem = st.size();
        vector<int> res(rem);
        for (int i = rem - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};