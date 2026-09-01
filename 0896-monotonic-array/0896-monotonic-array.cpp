class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
       bool inc = false;
       bool dec = false;
       int n = nums.size();
       
       for(int idx = 0; idx < n -1; idx++){
           if(nums[idx] < nums[idx + 1]) {
               inc = true;
           }
           else if(nums[idx] > nums[idx + 1]){
               dec = true;
           }
           else continue;
           
           if(inc && dec) return false;
       }
       if(inc && dec) return false;
       return true;
    }
};