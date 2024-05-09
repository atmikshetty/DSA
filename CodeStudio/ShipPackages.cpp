int days(vector<int> &weights, int capacity){
    int days = 1, load = 0;
    for(int i=0;i<weights.size();i++){
        if(weights[i] + load>capacity){
            days += 1;
            load = weights[i];
        }else{
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while(low<=high){
        int mid = low + (high-low)/2;
        int totaldays = days(weights, mid);
        if(totaldays <= d){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}