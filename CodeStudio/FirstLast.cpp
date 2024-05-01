#include <bits/stdc++.h> 

int firstOccurence(vector<int>& arr, int n, int k){
    int low = 0;
    int high = n -1;
    int first = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == k){
            first = mid;
            high = mid -1;
        }
        else if(arr[mid] < k){
            low = mid + 1;
        }else{
            high = mid -1;
        }
    }
    return first;
}

int secondOccurence(vector<int>& arr, int n, int k){
    int low = 0;
    int high = n -1;
    int last = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == k){
            last = mid;
            low = mid +1;
        }else if (arr[mid]<k){
            low = mid + 1;
        }else{
            high  = mid -1;
        }
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // // 2 * (log2N)
    // int lb = lower_bound(arr.begin(), arr.end(), k)-arr.begin();
    // if(lb == n || arr[lb] != k) return {-1,-1};
    // int ub = upper_bound(arr.begin(), arr.end(), k) - arr.begin() - 1;
    // return {lb,ub};

    int first  = firstOccurence(arr, n, k);
    if(first == -1) return {-1,-1};
    int last = secondOccurence(arr, n, k);
    return {first, last};
}