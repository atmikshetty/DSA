int division(vector<int> arr, int val){
	int sum = 0;
	for(int i=0;i<arr.size();i++){
		sum += ceil((double)(arr[i])/(double)(val));
	}
	return sum;
}

int smallestDivisor(vector<int>& arr, int limit)
{
	int n = arr.size();
	int maxi = INT_MIN;
	for(int i=0;i<n;i++){
		maxi = max(maxi, arr[i]);
	}
	int low = 1;
	int high = maxi;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(division(arr, mid) <=limit){
			high = mid -1;
		}else{
			low = mid + 1;
		}
	}
	return low;
}