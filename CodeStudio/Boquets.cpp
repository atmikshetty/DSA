int possible(vector<int> arr, int k, int m, int day){
	int n = arr.size();
	int noOfDays = 0;
	int count = 0;
	for(int i=0;i<n;i++){
		if(arr[i]<=day){
			count++;
		}
		else{
			noOfDays += (count / k);
			count  = 0;
		}
	}
	noOfDays += (count/k);
	return noOfDays >= m;
}

int roseGarden(vector<int> arr, int k, int m)
{
	long long val = k * 1LL * m * 1LL;
	if(val>arr.size()) return -1;
	int mini = INT_MAX, maxi = INT_MIN;
    for(int i=0;i<arr.size();i++){
		maxi = max(maxi, arr[i]);
		mini = min(mini, arr[i]);
	}
	int low = mini, high = maxi;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(possible(arr,k, m, mid)){
			high = mid -1;
		}else{
			low = mid + 1;
		}
	}
	return low;
}

