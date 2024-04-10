vector<int> getFrequencies(vector<int>& v) {
    // Write Your Code Here
    vector<int> ans;
    map<int,int> mpp;
    int n = v.size();
    for(int i=0;i<n;i++){
        mpp[v[i]]++;
    }
    int highest = INT_MIN;
    int lowest = INT_MAX;
    int highIndex;
    int loweIndex;

    for(auto it: mpp){
        if(it.second>highest){
            highest = it.second;
            highIndex = it.first;
        }
        if(it.second < lowest){
            lowest = it.second;
            loweIndex = it.first;
        }
    }
    ans.push_back(highIndex);
    ans.push_back(loweIndex);
    return ans;
}