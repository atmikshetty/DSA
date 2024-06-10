class Solution {
public:
    int numberOfSubstrings(string s) {
        // Brute force
        int count=0;
        for(int i=0;i<s.size();i++){
            int hash[3] = {0};
            for(int j=i;j<s.size();j++){
                hash[s[j]-'a'] = 1;
                if(hash[0]+hash[1]+hash[2] == 3) count++; // all three present
            }
        }
        return count;
    }
};