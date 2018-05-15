class TwoSum {
private:
  vector<int> nums;
public:
  void add(int val) {
    vector<int>::iterator it = nums.begin();
    while (it < nums.end() && *it < val) {
      it++;
    }
    nums.insert(it, val);
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
