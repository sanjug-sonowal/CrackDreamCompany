// Last updated: 18/10/2025, 09:07:45
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax = 0,rightmax = 0,water = 0,maxheight = height[0],index = 0;

        //find max height of the building
        for(int i = 1; i < n; i++)
        {
            if(maxheight < height[i])
            {
                maxheight = height[i];
                index = i;
            }
        }
        //find left part
        for(int i = 0;i < index;i++)
        {
            if(leftmax > height[i])
            {
                water += leftmax - height[i];
            }else{
                leftmax = height[i];
            }
        }

        //find right part
        for(int i = n - 1;i > index;i--)
        {
            if(rightmax > height[i])
            
                water += rightmax - height[i];
           else
                rightmax = height[i];
            
        }
        return water;
    }
};