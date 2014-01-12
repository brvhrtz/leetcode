/*
 *  3 Sum 
 *  Natrual extension from 2 sum algorithm
 * Sum on 2sum
    Algorithm1: 
 *   1. Hash map of index of each elemtns
     2. Walk through all element a[i] and see if Target-a[i] is in the hash
     3. This has worst complexith of n^2 as hash map add hash add and find both can have a worst complexity of O(N)
    Algorithm2: 
     1. Sort vector
     2. using start and end pointers   if(a+b)>target end--; if(a+b)<target start++; if(a+b)==target res.push_back(pair(a,b))
     3. This will definitely find the pair and if you keep looping on, it will find all pairs. 
 */

set<vector<int> > find_triplets(vector<int> arr) {
  sort(arr.begin(), arr.end());
  set<vector<int> > triplets;
  vector<int> triplet(3);
  int n = arr.size();
  for (int i = 0;i < n; i++) {
    int j = i + 1;
    int k = n - 1;
    while (j < k) {
      int sum_two = arr[i] + arr[j];
      if (sum_two + arr[k] < 0) {
        j++;
      } else if (sum_two + arr[k] > 0) {
        k--;
      } else {
        triplet[0] = arr[i];
        triplet[1] = arr[j];
        triplet[2] = arr[k];
        triplets.insert(triplet);
        j++;
        k--;
      }
    }
  }
  return triplets;
}
