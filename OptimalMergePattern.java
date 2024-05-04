import java.util.PriorityQueue;

public class OptimalMergePattern {
    public static void optimalMerge(int files[]) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();

        for (int i = 0; i < files.length; i++) {
            pq.add(files[i]);
        }

        int total = 0;

        while (pq.size() > 1) {
            int tempTotal = pq.poll() + pq.poll();

            total += tempTotal;

            pq.add(tempTotal);
        }

        System.out.println("Minimum computations: " + total);
    }

    public static void main(String[] args) {
        // int[] files = { 2, 9, 5, 1, 6, 4 };
        int[] files = { 2, 3, 4, 5, 6, 7 };

        optimalMerge(files);
    }
}
