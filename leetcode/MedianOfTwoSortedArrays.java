import java.util.Arrays;

public class MedianOfTwoSortedArrays {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] mergedArray = new int[nums1.length + nums2.length];
        int j = 0;

        for (int i = 0; i < nums1.length; i++, j++) {
            mergedArray[j] = nums1[i];
        }

        for (int i = 0; i < nums2.length; i++, j++) {
            mergedArray[j] = nums2[i];
        }

        Arrays.sort(mergedArray);

        if (mergedArray.length % 2 != 0) {
            int midValue = (mergedArray.length + 1) / 2;
            return (double)mergedArray[midValue - 1];
        } else {
            int value1 = mergedArray.length / 2;
            int value2 = (mergedArray.length / 2) + 1;
            double median = ((double)mergedArray[value1 - 1] + (double)mergedArray[value2 - 1]) / 2;

            return median;
        }
    }

    public static void main(String[] args) {
        int[] nums1 = { 1, 2 };
        int[] nums2 = { 3, 4 };

        System.out.println(findMedianSortedArrays(nums1, nums2));
    }
}
