class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();   // greed
        int m = s.size();   // size
        int l=0;
        int r=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(l<m && r<n){   // left less than size 
            if(g[r] <= s[l]){
                r++;
            }
            l++;
        }
        return r;
    }
};