public class SearchInRotatedSortedArray {
    public static int search(int[] nums, int target) {
        int start = 0, end = nums.length - 1;

        while (start <= end) {
            int mid = end + (start - end) / 2;

            if (nums[mid] == target) return mid;

            if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target >= nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] nums = { 4, 5, 6, 7, 0, 1, 2 };
        // int[] nums = { 1 };

        System.out.println(search(nums, 1));
    }
}
