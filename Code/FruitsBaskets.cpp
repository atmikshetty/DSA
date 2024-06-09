class Solution{
    public:
    int fruitIntoBasket(vector<int> &arr, int k){
        // Brute Force  O(N2)
        arr = [3,3,3,1,2,1,1,2,3,3,4]
        int maxLen = 0;
        int size = arr.size();
        for(int i=0;i<n;i++){
            set<int> st;
            for(int j=i;j<n;j++){
                st.push(arr[j]);
                if(st.size() <= k){
                    maxLen = max(maxLen, j-i+1);
                }
                else break;
            }
        }
        return maxLen;

        // Sliding window   O(2N)
        int n = arr.size();
        int left = 0, right = 0, maxLen = 0;
        vector<int> mpp;
        while(right<n){
            mpp[arr[right]]++;
            if(mpp.size()>k){
                while(mpp.size()>k){
                    mpp[arr[left]]--;
                    if(mpp[left] == 0) mpp.remove(arr[left]);
                    left++;
                }
            }
            if(mpp.size()<=k){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;

        // Optimal O(N)
        int n = arr.size();
        int left = 0, right = 0, maxLen = 0;
        map<int,int> mpp;
        while(right<n){
            mpp[arr[right]]++;
            if(mpp.size()>k){
                mpp[arr[left]]--;
                if(mpp[arr[left]] == 0) mpp.remove(mpp[arr[left]]);
                left++;
            }
            if(mpp.size()<=k){
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen;
    }
}