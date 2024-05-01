int binarySearch(vector<int> &nums, int target, int low, int high){
    if(low>high) return-1;

    int mid= (low+high)/2;
    // also can be written as
    // int mid  = low + (high-low)/2;
    if(nums[mid] == target) return mid;
    else if(target>nums[mid]){
        return binarySearch(nums, target, mid+1,high);
    }else{
        return binarySearch(nums, target,low, mid-1);
    }
    return -1;
}

int search(vector<int> &nums, int target) {
    // // Binary Search Iterative
    // int n = nums.size();
    // int low = 0;
    // int high = n-1;
    // while(low<=high){
    //     int mid = (low+high) / 2;
    //     if(nums[mid] == target) return mid;
    //     else if(target> nums[mid]) low = mid + 1;
    //     else high = mid - 1;
    // }
    // return -1;

    return binarySearch(nums, target, 0, nums.size()-1);
    // O(log2n)
}