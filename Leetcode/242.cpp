class Solution {
public:
    bool isAnagram(string s, string t) {
        // // O(NlogN) + O(NlogN)
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;

        // O(logN) + O(N)
        if(s.size() != t.size()) return false;
        map<char,int> s1, t1;
        for(int i=0;i<s.size();i++){
            s1[s[i]]++;
            t1[t[i]]++;
        }
        return s1 ==  t1;
    }
};