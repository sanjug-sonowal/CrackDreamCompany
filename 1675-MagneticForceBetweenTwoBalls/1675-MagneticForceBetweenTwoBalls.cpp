// Last updated: 18/10/2025, 09:02:01
class Solution {
public:
    bool canPlace(int forceMid, vector<int> &pos, int m) {
        int prev = pos[0];
        int count = 1;
        for (int i = 1; i < pos.size(); i++) {
            if (pos[i] - prev >= forceMid) {
                count++;
                prev = pos[i];
            }
            if (count == m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int minForce = 1;
        int maxForce = position[n - 1] - position[0];
        int result = 0;

     

        while(minForce <= maxForce){
            int mid = minForce + (maxForce - minForce)/2;
            if(canPlace(mid,position,m)){
                result = mid;
                minForce = mid + 1;
            }else{
                maxForce = mid - 1;
            }
        }
        return result;
    }
};