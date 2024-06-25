class Solution {
public:
    bool isSubsequence(string s, string t) {
        // use 2 pointers to compare sizes of two strings O(N)
        if (s.size() > t.size())
            return false; // subseq cannot be bigger than actual string

        int first = 0, second = 0;
        while (second < t.size()) {
            if (first < s.size() &&
                s[first] == t[second]) { // check if every element of subseq is
                                         // present in the main string
                first++;
            }
            second++;
        }
        if (first == s.size())
            return true; // found a subseq matching to the given
        return false;
    }
};