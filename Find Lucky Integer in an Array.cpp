class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size(), ans = -1;
        unordered_map<int, int> mp;
        for(auto& x : arr){
            mp[x]++;
        }
        for(auto& x : mp){
            if(x.first == x.second){
                ans = max(ans, x.first);
            }
        }
        return ans;
    }
};
