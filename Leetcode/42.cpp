class Solution {
public:
    int trap(vector<int>& height) {
        // Brute
        int n = height.size();
        int count = 0;
        for(int i=1;i<n-1;i++){
            int lmax = height[i];
            for(int j=0;j<i;j++){
                lmax = max(lmax, height[j]);
            }

            int rmax= height[i];
            for(int j=i+1;j<n;j++){
                rmax = max(rmax, height[j]);
            }

            count = count + (min(lmax,rmax)) - height[i];
        }
        return count;

        // Optimal
        int n = height.size();
        int lmax[n];
        lmax[0] = height[0];
        for(int i=1;i<n;i++){
            int temp = max(lmax[i-1], height[i]);  // i-1 to check for the left
            lmax[i] = temp;
        }

        int rmax[n];
        rmax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            int temp = max(rmax[i+1], height[i]);  // i+1 to check for the right
            rmax[i] = temp;
        }

        int water = 0;
        for(int i=1;i<n-1;i++){
            water += min(lmax[i], rmax[i]) - height[i];
        }

        return water;
    }
};