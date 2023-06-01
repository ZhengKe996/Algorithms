class Solution {
    public int removeDuplicates(int[] nums) {
        int n = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[n] = nums[i];
                n++;
            }
        }
        return n;
    }
}

public class Main {
    public static void main(String[] args) {

        Solution s = new Solution();
        int[] nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}; // 输入数组

        int k = s.removeDuplicates(nums); // 调用


        System.out.printf("结果：%d", k);
    }
}