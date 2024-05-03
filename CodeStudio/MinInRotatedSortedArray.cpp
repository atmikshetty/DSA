int findMin(vector<int>& arr)
{
	// // Brute Force(Partially accepted) O(N)
	// int mini = INT_MAX;
	// for(int i=0;i<arr.size();i++){
	// 	mini = min(mini, arr[i]);
	// }
	// return mini;

	// Binary Search O(NLogN)
	int n = arr.size();
	int low = 0;
	int high = n-1;
	int mini = INT_MAX;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(arr[low] <= arr[mid]){
			mini = min(mini, arr[low]);
			low = mid + 1;
		}else{
			mini = min(mini, arr[mid]);
			high = mid - 1;
		}
	}
	return mini;
}