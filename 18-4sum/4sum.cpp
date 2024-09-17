class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i =0; i< n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j= i+1; j < n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1, right = n-1;
                while(left < right){
                    long long sum = nums[i] + nums[j];
                    sum+=nums[left]+nums[right];
                    if(sum < target) left++;
                    else if(sum > target) right--;
                    else{
                        ans.push_back({nums[i], nums[j], nums[left],nums[right]});
                        left++, right--;
                        while(left < right && nums[left] == nums[left-1]) left++;
                        while(left < right && nums[right] == nums[right+1])right--;
                    }
                }
            }
        }
        return ans;
    }
};