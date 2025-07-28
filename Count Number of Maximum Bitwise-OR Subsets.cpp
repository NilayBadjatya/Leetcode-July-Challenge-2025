class Solution {
public:

    int solve(vector<int>& nums, int i, int orr, int maxOr){
        if(i == nums.size()){
            if(orr == maxOr){
                return 1;
            }
            return 0;
        }
        int take = solve(nums, i+1, orr | nums[i], maxOr);
        int skip = solve(nums, i+1, orr, maxOr);
        return take + skip;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto& x : nums){
            maxOr |= x;
        }
        // cout << maxOr << " ";
        return solve(nums, 0, 0, maxOr);
    }
};
