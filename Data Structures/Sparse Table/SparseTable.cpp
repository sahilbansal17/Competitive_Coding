int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// function to be used in sparse table computation
int apply(int a, int b) {
    return gcd(a, b);
}

/*
 * SPARSE TABLE CODE BEGINS ------------------------------------------------------------------------------
 * REFERENCE 1: http://adilet.org/blog/sparse-table/
 * REFERENCE 2: https://www.youtube.com/watch?v=uUatD9AudXo
 */

// GLOBAL VARIABLES START--------------------------------------------------
const int MAXN = 105000;
const int MAXLOG = 20;
int n;
int a[MAXN];
int table[MAXLOG][MAXN]; // table[i][j] means the answer for subarray of length 2^i starting from j
int logs[MAXN]; // logs[i] means such maximum p that 2^p <= i
// GLOBAL VARIABLES END..--------------------------------------------------

void computeLogs() {
    logs[1] = 0;
    for (int i = 2; i <= n; ++i) {
        logs[i] = logs[i/2] + 1;
    }
}

void buildSparseTable() {
    for (int i = 0; i <= logs[n]; ++i) {
        int cur_len = 1 << i; // 2^i
        for (int j = 0; j + cur_len <= n; ++j) {
            if (cur_len == 1) {
                table[i][j] = a[j];
            } else {
                table[i][j] = apply(table[i - 1][j], table[i - 1][j + (cur_len)/2]);
            }
        }
    }
}

int query(int l, int r) {
    int p = logs[r - l + 1];
    int p_len = (1 << p); // 2^p
    return apply(table[p][l], table[p][r - p_len + 1]);
}
/*
 * SPARSE TABLE CODE END..S ------------------------------------------------------------------------------
 */