#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:
        int rob(vector<int>& nums){
            int size = nums.size();
            if (size == 0){
                return 0;
            }else if (size == 1){
                return nums[0];
            }

            vector<int> includeFirst(size, 0);

            vector<int> excludeFirst(size, 0);

            includeFirst[0] = nums[0];
            for (int i = 1 ; i < size - 1; i ++ ){
                if (i == 1){
                    includeFirst[i] = max(nums[i], includeFirst[i-1]);
                    continue;
                }
                includeFirst[i] = max(includeFirst[i-1], includeFirst[i-2] + nums[i]);
            }

            excludeFirst[1] = nums[1];
            for (int i = 2 ; i < size; i ++ ){
                if (i == 2){
                    excludeFirst[i] = max(nums[i], excludeFirst[i-1]);
                    continue;
                }
                excludeFirst[i] = max(excludeFirst[i-1], excludeFirst[i-2] + nums[i]);
            }

            return max(includeFirst[size-2], excludeFirst[size-1]);
        }
};

int main(){
    vector<int> nums{1, 3, 1, 3, 100};
    Solution sol;
    int answer = sol.rob(nums);
    cout << answer << "\n";
    return 0;
}