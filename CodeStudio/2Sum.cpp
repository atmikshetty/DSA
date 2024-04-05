#include <bits/stdc++.h>
string read(int n, vector<int> book, int target)
{
    // Brute Force  O(N2)
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(book[i] + book[j] == target){
                return "YES";
            }
        }
    }
    return "NO";

    // HashMap O(N)
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int a = book[i];
        int more = target - a;
        if(mpp.find(more) != mpp.end()) return "YES";
        mpp[a] = i;
    }
    return "NO";

     // 2PTR Approach O(N)  Greeedy Approach
    int l = 0;
    int r = n-1;
    sort(book.begin(), book.end());
    for(int i=0;i<n;i++){
        if(book[l]+book[r] == target) return "YES";
        else if(book[l] + book[r] > target) r--;
        else l++;
    }
    return "NO";
}
