// Last updated: 18/10/2025, 08:58:56
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
           unordered_map<int, int> ballToColor; 
        unordered_map<int, int> colorFrequency; 
        vector<int> result;
        int distinctColors = 0;
        
        for (auto& query : queries) {
            int ball = query[0], color = query[1];
            
            if (ballToColor.find(ball) != ballToColor.end()) {
                int oldColor = ballToColor[ball];
                if (oldColor != color) {
                    colorFrequency[oldColor]--;
                    if (colorFrequency[oldColor] == 0) {
                        distinctColors--;
                    }
                } else {
                
                    result.push_back(distinctColors);
                    continue;
                }
            }
            
            ballToColor[ball] = color;
            if (colorFrequency[color] == 0) {
                distinctColors++; 
            }
            colorFrequency[color]++;
            
            result.push_back(distinctColors);
        }
        
        return result;
    }
};