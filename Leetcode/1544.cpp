class Solution {
public:
    string makeGood(string s) {
        // Using Stack  O(3N)
        stack<int> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            // checks if both are equal,lower has 32 more than upper in ASCII
            if(!st.empty() && (st.top()+32==s[i] || s[i]+32==st.top())){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        string ans ="";  // Extra space
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};