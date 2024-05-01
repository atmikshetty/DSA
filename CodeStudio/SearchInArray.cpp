#include<bits/stdc++.h>

int search(vector<int> &arr, int n, int k) {
  // Write your code here.
  // Return the position of K in ARR else return -1.
//   //Linear Search O(N)
//   for (int i = 0; i < n; i++) {
//     if (arr[i] == k) {
//       return i;
//     }
//   }
//   return -1;

    // Binary search O(Log2N)
    int low = 0;
    int high = n-1;
    // sort(arr.begin(), arr.end());
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == k){
            return mid;
        }
        if (arr[low] <= arr[mid]){
            if(arr[low]<=k && k<=arr[mid]){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        else {
            if(arr[mid] <= k && k<=arr[high]){
                low=  mid + 1;
            }else{
                high = mid -1;
            }
        }
    }
    return -1;
}

