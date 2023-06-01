class Solution {
    public void moveZeroes(int[] nums) {
        int n = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[n] = nums[i];
                n++;
            }
        }

        while (n < nums.length) {
            nums[n] = 0;
            n++;
        }
    }
}

public class Main {
    public static void main(String[] args) {

        Solution s = new Solution();
        int[] list = {0, 1, 0, 3, 12};
        s.moveZeroes(list);
        for (int i = 0; i < list.length; i++) {
            System.out.printf("结果：%d", list[i]);
        }
    }
}