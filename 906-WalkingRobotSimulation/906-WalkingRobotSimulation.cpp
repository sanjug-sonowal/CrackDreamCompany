// Last updated: 18/10/2025, 09:04:32
class Solution {
public:
   int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions are in the order: North, East, South, West
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0; // Starting point
        int directionIndex = 0; // Starting by facing North
        
        // Use a set to store obstacles for O(1) lookup
        unordered_set<string> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }
        
        int maxDistanceSquared = 0;
        
        for (int command : commands) {
            if (command == -2) {
                // Turn left
                directionIndex = (directionIndex + 3) % 4;
            } else if (command == -1) {
                // Turn right
                directionIndex = (directionIndex + 1) % 4;
            } else {
                // Move forward `command` units
                for (int i = 0; i < command; ++i) {
                    int newX = x + directions[directionIndex].first;
                    int newY = y + directions[directionIndex].second;
                    
                    // Check if the next position is an obstacle
                    if (obstacleSet.count(to_string(newX) + "," + to_string(newY)) == 0) {
                        // Move to the new position
                        x = newX;
                        y = newY;
                        // Calculate the current distance squared and update the max
                        maxDistanceSquared = max(maxDistanceSquared, x * x + y * y);
                    } else {
                        // Hit an obstacle, stay in current position
                        break;
                    }
                }
            }
        }
        
        return maxDistanceSquared;
    }
};