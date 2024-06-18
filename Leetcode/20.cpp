class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (!st.empty()) {
                    char close = st.top();
                    if (close == '(' && ch == ')' ||
                        close == '{' && ch == '}' ||
                        close == '[' && ch == ']') {
                        st.pop();
                    } else {
                        return false;
                    }

                } else {
                    return false;
                }
            }
        }
        if (!st.empty())
            return false;
        else
            return true;
    }
};