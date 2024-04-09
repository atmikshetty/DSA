long long maxSubarraySum(vector<int> arr, int n)
{
    // O(N)
    long long sum = 0, maxi = LONG_MIN;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum<0){
            sum = 0;
        }
        if(sum>maxi){
            maxi = sum;
        }
        if(maxi<0){
            maxi = 0;
        }
    } 
    return maxi;
}