class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result;
        unordered_map<int, int> mpBall; // {ball -> color}
        unordered_map<int, int> mpColor; // {color -> count}
        int colors = 0;

        for (const auto& query : queries) {
            int ball = query[0];
            int color = query[1];

            // if ball already exists, remove the color
            if (mpBall.find(ball) != mpBall.end()) {
                int prevColor = mpBall[ball];

                // decrease count of previous color
                mpColor[prevColor]--;
                if (mpColor[prevColor] == 0) {
                    colors--; // no more distinct
                }
            }

            // if new ball
            mpBall[ball] = color;
            if (mpColor[color] == 0) {
                colors++;  // new distinct color
            }
            mpColor[color]++;
            result.push_back(colors);
        }
        return result;
    }
};
