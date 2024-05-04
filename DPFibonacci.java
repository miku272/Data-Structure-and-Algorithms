public class DPFibonacci {
    public static long fibonacci(int n) {
        if (n <= 1) {
            return n;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    // public static long dpFibonacci(int n) {
    // long[] fib = new long[n + 1];
    // fib[0] = 0;
    // fib[1] = 1;

    // for (int i = 2; i <= n; i++) {
    // fib[i] = fib[i - 1] + fib[i - 2];
    // }

    // return fib[n];

    // }

    public static long dpFibonacci(int n, long[] fib) {
        if (n <= 1) {
            return n;
        }
        if (fib[n] != 0) {
            return fib[n];
        }
        fib[n] = dpFibonacci(n - 1, fib) + dpFibonacci(n - 2, fib);
        return fib[n];
    }

    public static long spaceOptimizedDpFibonacci(int n) {
        long prevOfPrev = 0, prev = 1, current;
        if (n == 0) {
            return prevOfPrev;
        }
        for (int i = 2; i <= n; i++) {
            current = prevOfPrev + prev;
            prevOfPrev = prev;
            prev = current;
        }
        return prev;
    }

    public static void main(String[] args) {
        int n = 40;
        long[] fib = new long[n + 1];
        fib[0] = 0;
        fib[1] = 1;

        long startTime = System.nanoTime();

        // System.out.println(fibonacci(n));
        // System.out.println(dpFibonacci(n, fib));
        // System.out.println(spaceOptimizedDpFibonacci(n));

        long endTime = System.nanoTime();

        long executionTime = (endTime - startTime) / 1000000;

        System.out.println("Execution time: " + executionTime + "ms");
    }
}
