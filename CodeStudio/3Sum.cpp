#include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Brute Force O(N3)
    set<vector<int>> ls;
    for(int i=0;i<n;i++){ 
        for(int j=i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    ls.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(ls.begin(), ls.end());
    return ans;

    // Hashing O(N2) log N
    set<vector<int>> ls;
    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=1+i;j<n;j++){
            int third = -(arr[i] + arr[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {arr[i], arr[j], third};
                 sort(temp.begin(), temp.end());
                  ls.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
     vector<vector<int>> ans(ls.begin(), ls.end());
    return ans;

    // Most optimal
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}
