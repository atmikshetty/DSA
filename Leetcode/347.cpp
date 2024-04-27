class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // any order hence use unotrdered map
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        //  use a min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it: mpp){
            pq.push(make_pair(it.second, it.first));
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            ans.push_back(temp.second);
            pq.pop();
        }
        return ans;
    }
};