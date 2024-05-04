public class ContainerWithMostWater {
    public static int maxArea(int[] height) {
        int maxArea = 0;
        int width = 0;

        int left = 0;
        int right = height.length - 1;

        // for (int i = 0; i < height.length; i++) {
        //     for (int j = i + 1; j < height.length; j++) {
        //         width = j - i;

        //         maxArea = Math.max(maxArea, Math.min(height[i], height[j]) * width);
        //     }
        // }

        while (left < right) {
            width = right - left;

            // Find the minimum height between left and the right bar and then multiply it with width to calculate the current area and then compare it with the value of maxArea. If the current area is greater then the previous maxArea, the current area gets assigned in the maxArea.
            maxArea = Math.max(maxArea, Math.min(height[left], height[right]) * width);

            if (height[left] >= height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return maxArea;
    }
    public static void main(String[] args) {
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        // int[] height = {1, 1};

        System.out.println(maxArea(height));
    }
}