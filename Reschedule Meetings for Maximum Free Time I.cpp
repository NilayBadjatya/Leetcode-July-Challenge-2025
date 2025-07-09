class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<vector<int>> nums;
        for(int i = 0; i < n; i++){
            nums.push_back({startTime[i], endTime[i]});
        }
        sort(nums.begin(), nums.end());
        vector<int> freeTime;
        int prev = 0;
        for(int i = 0; i < n; i++){
            freeTime.push_back(nums[i][0] - prev);
            prev = nums[i][1];
        }
        freeTime.push_back(eventTime - prev);
        k++;
        int size = freeTime.size();
        int i = 0, j = 0, sum = 0, ans = 0;
        while(j < size){
            sum += freeTime[j];
            if(j - i + 1 < k){
                j++;
                ans = max(ans, sum);
            }else if(j - i + 1 == k){
                ans = max(ans, sum);
                sum -= freeTime[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};
