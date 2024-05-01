#include<bits/stdc++.h>
using namespace std;

// // Iterative Approach
// int binarySearch(vector<int> &nums, int target){
//     int n = nums.size()-1;
//     int low = 0;
//     int high = n-1;
//     while(low<=high){
//         int mid = (low+high)/2;
//         if(nums[mid] == target) return mid;
//         else if(target>nums[mid]) low = mid + 1;
//         else high = mid -1;
//     }
//     return -1;
// }

// Recursive Approach
int binarySearch(vector<int> & nums, int low, int high, int target){
    if(low>high) return -1; // Base case

    int mid = (low+high)/2;

    if(nums[mid] == target){
        return mid;
    }
    else if(target>nums[mid]){
        return binarySearch(nums, mid+1, high, target);
    }
    else{
        return binarySearch(nums, low, mid-1, target);
    }
    return -1;
}

int main(){
    vector<int> a = {7,8,9,10,11,12,15,19,23};
    int target = 23;
    int ind = binarySearch(a,0,a.size()-1,target);
    if(ind == -1) cout << "target does not exist" << endl;
    else cout << "Target exists at index " << ind << endl;
    return 0;
}