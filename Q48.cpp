class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        
        if (nums.size() == 0) {
            return 0;
        }
        
        while (L < R) {
            int M = (L + R) / 2;
            
            if (target == nums[M]) {
                return M;
            }
            
            else if (target < nums[M]) {
                R = M - 1;
            } 
            
            else if (target > nums[M]) {
                L = M + 1;
            }
        }
        
        return nums[L] < target ? L + 1 : L;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        
        if (nums.size() == 0) {
            return 0;
        }
        
        while (L <= R) {
            int M = (L + R) / 2;
            
            if (target == nums[M]) {
                return M;
            }
            
            else if (target < nums[M]) {
                R = M - 1;
            } 
            
            else if (target > nums[M]) {
                L = M + 1;
            }
        }
        
        return L;
    }
};