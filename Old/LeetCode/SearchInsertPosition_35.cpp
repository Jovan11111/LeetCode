#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size()-1;
        while(st <= end){
            if(nums[st] == target) return st;
            else if(nums[end] == target) return end;
            int mid = st + (end-st) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end = mid-1;
            else st = mid+1;
        }
        return st;
    }
};