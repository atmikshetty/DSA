int floorSqrt(int n) {
  // //STL
  // return sqrt(n);

  // // Brute O(N)
  // int ans = 1;
  // for(int i=1;i<=n;i++){
  //     if(i*i<=n){
  //         ans = i;
  //     }else{
  //         break;
  //     }
  // }
  // return ans;

  // Binary Search
  int low = 1;
  int high = n;
  while (low <= high) {
    long long mid = low + (high - low)/2;
    long long ans = 1;
    if(mid*mid <= n){
        ans = mid;
        low = mid + 1;
    }
    else high = mid - 1;
  }
  return high;
}
