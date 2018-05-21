/* Method 1 */
/* Binary search + Two pointers */
/* Add: O(logN) time */
/* Find: O(N) time */
/* O(N) space */

class TwoSum {
private:
  vector<int> nums;
public:
  /* Linear insertion */
  void add(int val) {
    vector<int>::iterator it = nums.begin();
    while (it < nums.end() && *it < val) {
      it++;
    }
    nums.insert(it, val);
  }

  /* Binary insertion */
  void add(int target) {
    int L = 0;
    int R = (int)nums.size() - 1;
    int index = 0;
    
    if (nums.size() == 0) {
      nums.insert(nums.begin(), target);
      return;
    }
    
    while (L < R) {
      int M = (L + R) / 2;
      
      if (target == nums[M]) {
        index = M;
        break;
      }
      
      else if (target < nums[M]) {
        R = M - 1;
      }
      
      else if (target > nums[M]) {
        L = M + 1;
      }
    }
    
    index = nums[L] < target ? L + 1 : L;
    nums.insert(nums.begin() + index, target);
  }

  bool find(int target) {
    int left = 0;
    int right = (int)nums.size() - 1;
    int sum = nums[left] + nums[right];

    while (left < right && sum != target) {
      if (sum < target) {
        left++;
      } else if (sum > target) {
        right--;
      }
      sum = nums[left] + nums[right];
    }

    return left < right && target == nums[left] + nums[right];
  }
};
