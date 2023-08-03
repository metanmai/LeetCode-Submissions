/* This is a pretty good problem, Tanmai. Basically, for every element in arr, 
you check how far to the left and right you can go, with arr[i] being the minimum. 
So you use a monotonically increasing stack going both directions. */

class Solution {
public:
  int sumSubarrayMins(vector<int>& arr) {
      int MOD = 1e9 + 7, n = arr.size(), answer = 0;
      vector<int> left(n), right(n);
      stack<pair<int, int>> st1, st2;
      
      for(int i = 0; i < n; i++)
          left[i] =  i + 1, right[i] = n - i;
      
      for(int i = 0; i < n; i++)
      {
          while(!st1.empty() and st1.top().first > arr[i]) 
              st1.pop();
          
          left[i] = st1.empty() ? i + 1: i - st1.top().second;
          st1.push({arr[i], i});
          
          while(!st2.empty() and st2.top().first > arr[i])
          {
              auto x = st2.top(); st2.pop();
              right[x.second] = i - x.second;
          }
          
          st2.push({arr[i], i});
      }
      
      for(int i = 0; i < n; i++)
          answer = (answer + ((((long long) arr[i] * left[i]) % MOD) * right[i]) % MOD) % MOD;
      
      return answer;
    }
};