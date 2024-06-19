class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Store the next bigger element in the unordered map
        unordered_map<int,int> mpp;
        stack<int> st;
        int n = nums2.size();
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            int element = nums2[i];
            while(!st.empty() && st.top()<=element){
                st.pop();
            }
            int res = (st.empty()) ? -1 : st.top();
            mpp.insert({element, res});
            st.push(element);
        }
        for(auto it: nums1){
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};