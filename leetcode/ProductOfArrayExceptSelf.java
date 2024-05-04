public class ProductOfArrayExceptSelf {
    public static int[] productExceptSelf(int[] nums) {
        int[] result = new int[nums.length];
        int pre = 1, post = 1;

        for (int i = 0; i < nums.length; i++) {
            if (i > 0) pre *= nums[i - 1];

            result[i] = pre;
        }

        for (int i = nums.length - 1; i >= 0; i--) {
            if (i < nums.length - 1) post *= nums[i + 1];

            result[i] *= post;
        }

        return result;
    }

    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4 };

        int[] res = productExceptSelf(nums);

        for (int i = 0; i < res.length; i++) {
            System.out.print(res[i] + " ");
        }
    }
}
