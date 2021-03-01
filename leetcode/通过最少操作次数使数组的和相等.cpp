class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s = 0, t = 0;
        vector<int> c1(10,0),c2(10,0);
        for(auto& e : nums1) {
            s += e;
            c1[e] ++;
        }
        for(auto& e : nums2) {
            t += e;
            c2[e] ++;
        }
            
        if(s < t) {
            swap(s,t);
            nums1.swap(nums2);
            c1.swap(c2);
        }
        
        int res = 0, i = 6, j = 1;
        while(s > t && (i >= 2 || j <= 5)) {
            int sub = s - t;
            res ++;
            while(i >= 1 && !c1[i]) i--;
            while(j <= 6 && !c2[j]) j++;
            if(abs(i - 6) <= abs(j - 1)) {
                c1[i] --;
                if(i - sub >= 1) {
                    s -= sub;
                    c1[i - sub] ++;
                } else {
                    s -= i - 1;
                    c1[1] ++;
                }
            } else {
                c2[j] --;
                if(j + sub <= 6) {
                    t += sub;
                    c2[j + sub] ++;
                } else {
                    t += 6 - j;
                    c2[6] ++;
                }
            }
        }
        
        
        if(s == t) return res;
        return -1;
    }
};


给你两个长度可能不等的整数数组?nums1 和?nums2?。两个数组中的所有值都在?1?到?6?之间（包含?1?和?6）。

每次操作中，你可以选择 任意?数组中的任意一个整数，将它变成 1?到 6?之间 任意?的值（包含 1?和 6）。

请你返回使 nums1?中所有数的和与?nums2?中所有数的和相等的最少操作次数。如果无法使两个数组的和相等，请返回 -1?。

?

示例 1：

输入：nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
输出：3
解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
- 将 nums2[0] 变为 6 。 nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2] 。
- 将 nums1[5] 变为 1 。 nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2] 。
- 将 nums1[2] 变为 2 。 nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2] 。
示例 2：

输入：nums1 = [1,1,1,1,1,1,1], nums2 = [6]
输出：-1
解释：没有办法减少 nums1 的和或者增加 nums2 的和使二者相等。
示例 3：

输入：nums1 = [6,6], nums2 = [1]
输出：3
解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
- 将 nums1[0] 变为 2 。 nums1 = [2,6], nums2 = [1] 。
- 将 nums1[1] 变为 2 。 nums1 = [2,2], nums2 = [1] 。
- 将 nums2[0] 变为 4 。 nums1 = [2,2], nums2 = [4] 。
?

提示：

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[i] <= 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/equal-sum-arrays-with-minimum-number-of-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
