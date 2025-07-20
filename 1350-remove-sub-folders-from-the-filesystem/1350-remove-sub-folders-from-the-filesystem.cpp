// Sorting + Greedy approach
// TC: O(nlogn)
// SC: O(logn)
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        std::sort(folder.begin(), folder.end());  // sort folders to ensure parent folders appear before subfolders 
        std::vector<std::string> result = {folder[0]};  

        for (int i = 1; i < n; i++) {
            string prev = result.back();

            // check if current folder is NOT a subfolder of the last folder in result
            if (folder[i].substr(0, prev.size() + 1) != prev + "/") {   // CAN BE USED: (folder[i].find(prev + "/") != 0)
                result.push_back(folder[i]);
            }
        }

        return result; 
    }
};