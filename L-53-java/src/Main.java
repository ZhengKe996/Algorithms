class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int[] s = new int[n + 1];
        int[] preMin = new int[n + 1];

        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }

        preMin[0] = 0;
        for (int i = 1; i <= n; i++) {
            preMin[i] = Math.min(preMin[i - 1], s[i]);
        }

        int ans = -100000;
        for (int i = 1; i <= n; i++) {
            ans = Math.max(ans, s[i] - preMin[i - 1]);
        }
        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();

        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println(s.maxSubArray(nums));

    }
}