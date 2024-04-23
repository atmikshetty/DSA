#include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // use set since we need unique elements only
    // Brute force O(N4)
    int n  = nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;j<n;j++){
                for(int l=k+1;k<n;k++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum+= nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

    // 4 ptr approach O(N3)
    int n  = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j != i+1 && nums[j] ==nums[j-1]) continue;
            int k = j+1;
            int l=  n -1;
            while(k<l){
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target){
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++, l--;
                    while(k<l && nums[k] == nums[k-1]) k++;
                    while(k<l && nums[l] == nums[l+1]) l--;
                }else if(sum < target){
                    k++;
                }else l--;
            }
        }
    }
    return ans;
}