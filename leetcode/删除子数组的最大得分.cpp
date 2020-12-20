class Solution {
public:

    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        //unordered_map<int,int> hash;
        int hash[10010];
        memset(hash,0x00,sizeof hash);

        int le = 0;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            while(le < i && hash[nums[i]]) {
                hash[nums[le]] = 0;
                sum -= nums[le++];
            }

            hash[nums[i]] = 1;
            ans = max(ans,sum);
        }

        return ans;
    }
};


给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。删除子数组的 得分 就是子数组各元素之 和 。

返回 只删除一个 子数组可获得的 最大得分 。

如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r] ，那么它就是?a 的一个子数组。

?

示例 1：

输入：nums = [4,2,4,5,6]
输出：17
解释：最优子数组是 [2,4,5,6]
示例 2：

输入：nums = [5,2,1,2,5,2,1,2,5]
输出：8
解释：最优子数组是 [5,2,1] 或 [1,2,5]
?

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-erasure-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
