vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=A[i]){  // if greater at top remove them.
            st.pop();
        }
        if(i<n){
            if(st.empty()){
                ans[i] = -1;    // if no further smaller element found -1 is ans
            }else{
                ans[i] = st.top();
            }
        }
        st.push(A[i]);
    }
    return ans;
}
