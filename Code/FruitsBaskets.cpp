class Solution{
    public:
    int fruitIntoBasket(vector<int> &arr){
        // Brute Force
        // arr = [3,3,3,1,2,1,1,2,3,3,4]
        int maxLen = 0;
        int size = arr.size();
        for(int i=0;i<n;i++){
            set<int> st;
            for(int j=i;j<n;j++){
                st.push(arr[j]);
                if(st.size() <= 2){
                    maxLen = max(maxLen, j-i+1);
                }
                else break;
            }
        }
        return maxLen;
    }
}