class Solution{
    public:
        int ans(string s, int k){
            // brute Force
            int maxLen = 0;
            map<char,int> mpp;
            for(int i=0;i<n;i++){
                mpp.clear();
                for(int j=i;j<n;j++){
                    mpp[s[j]]++;
                    if(mpp.size()<=k){
                        maxLen = max(maxLen, j - i + 1);
                    }
                    else break;
                }
            }
            return maxLen;
        }
}