/*
 * Given a number of stairs and a frog, the frog wants to climb from the 0th
 * stair to the (N-1)th stair. At a time the frog can climb either one or two
 * steps. A height[N] array is also given. Whenever the frog jumps from a stair
 * i to stair j, the energy consumed in the jump is abs(height[i]- height[j]),
 * where abs() means the absolute difference. We need to return the minimum
 * energy that can be used by the frog to jump from stair 0 to stair N-1.
 */

public class FrogJump {
    public static void main(String[] args) {
        int[] height = { 30, 10, 60, 10, 60, 50 };

        int prev = 0;
        int prev2 = 0;

        for (int i = 1; i < height.length; i++) {
            int jumpTwo = Integer.MAX_VALUE;
            int jumpOne = prev + Math.abs(height[i] - height[i - 1]);

            if (i > 1) {
                jumpTwo = prev2 + Math.abs(height[i] - height[i - 2]);
            }

            int currI = Math.min(jumpOne, jumpTwo);

            prev2 = prev;
            prev = currI;
        }

        System.out.println(prev);
    }
}