# Dynamic Programming (DP)
 - Essence: To avoid repeated calculation.
 - Example:
    Recursive version
```
    int fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
```
    DP version:
```
    const int MAXN = 100;
    bool found[MAXN];
    int memo[MAXN];
    int f(int n) {
        if (found[n]) return memo[n];
        if (n == 0) return 0;
        if (n == 1) return 1;

        found[n] = true;
        return memo[n] = f(n - 1) + f(n - 2);
    }
```
 - Problems:
 - P: 1285B, 1774C


