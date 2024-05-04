public class MaximumProductSubarray {
    public static int maxProduct(int[] nums) {
        int product = 1;

        for (int i = 0; i < nums.length; i++) {
            int temp = 1;

            for (int j = i + 1; j < nums.length; j++) {
                temp *= nums[i] * nums[j];

                if (temp == 0) {
                    product = 0;
                } else {
                    product = Math.max(product, temp);
                }
            }
        }

        return product;
    }

    public static void main(String[] args) {
        // int[] nums = {2, 3, -2, 4};
        // int[] nums = { -2, 0, -1 };
        int[] nums = {1, 2, 3, 4};

        System.out.println(maxProduct(nums));
    }
}
