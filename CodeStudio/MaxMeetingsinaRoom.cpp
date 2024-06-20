int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Using the Greedy Approach
    vector<pair<int,int>> v;
    for(int i=0;i<start.size();i++){
        v.push_back({start[i], end[i]});
    }

    sort(v.begin(), v.end(), [](const pair<int,int> &a, const pair<int,int> &b){
        return a.second < b.second; // lambda expression like in python sorts the vector based on the ending time list
    });
        

    int freeTime =0;
    int count = 0;

    for(auto it: v){
        if(it.first > freeTime){
            count++;
            freeTime = it.second;
        }
    }

    return count;
}