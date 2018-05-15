/* Since we return indices of the two numbers rather than the
number itself, it is not a good idea to perform sorting on array */

/* Brute force: O(n^2) runtime, O(1) space */
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int len = nums.size();

    for (int i = 0; i < len - 1; i++) {
      for (int j = i + 1; j < len; j++) {
        if (nums[i] + nums[j] == target) {
          return vector<int> {i, j};
        }
      }
    }

    return vector<int>();
  }
};

/* Hash: O(n) run time, O(n) space */
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int len = nums.size();
    map<int, int> val_idx;

    for(int i = 0; i < len; i++) {
      if(val_idx.count(target - nums[i]) != 0) {
        return vector<int> {val_idx[target - nums[i]], i};
      }
      val_idx[nums[i]] = i;
    }

    return vector<int>();
  }
};
