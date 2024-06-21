#include <bits/stdc++.h>
int platformsNeeded(int arrival[], int departure[], int n) {
  // Write your code here.
  sort(arrival, arrival + n);
  sort(departure, departure + n);
  int i = 0, j = 0, count = 0, maxCount = 0;
  while (i < n && j<n) {
    if (arrival[i] <= departure[j]) {
      count++;
      i++;
    } else {
      count--;
      j++;
    }
    maxCount = max(maxCount, count);
  }
  return maxCount;
}