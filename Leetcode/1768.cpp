class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int first = 0;
        int last = 0;
        string ans = "";
        while (first < n || last < m) {
            if (first < n) {
                ans += word1[first];
            }
            if (last < m) {
                ans += word2[last];
            }
            first++;
            last++;
            // if(first>n) ans += word1[first];
            // if(last>m) ans += word2[last];
        }

        return ans;
    }
};