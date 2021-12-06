/*
    斐波那契数列
*/

int fib(int n) {
    int f[31];                     // (1)
    f[0] = 0, f[1] = 1;            // (2)
    for(int i = 2; i <= n; ++i) {  // (3)
        f[i] = f[i-1] + f[i-2];    // (4)
    }
    return f[n];                   // (5)
}

//矩阵法
/*
    [1 1] [f(n)]    = [f[n] + f[n-1]]
    [1 0] [f(n-1)]    [     f[n]]
*/
struct Matrix {
    int mat[2][2];
};

struct Matrix matrixMultiply(struct Matrix* a, struct Matrix* b) {
    struct Matrix c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c.mat[i][j] = (*a).mat[i][0] * (*b).mat[0][j] + (*a).mat[i][1] * (*b).mat[1][j];
        }
    }
    return c;
}

struct Matrix matrixPow(struct Matrix a, int n) {
    struct Matrix ret;
    ret.mat[0][0] = ret.mat[1][1] = 1;
    ret.mat[0][1] = ret.mat[1][0] = 0;
    while (n > 0) {
        if (n & 1) {
            ret = matrixMultiply(&ret, &a);
        }
        n >>= 1;
        a = matrixMultiply(&a, &a);
    }
    return ret;
}

int fib(int n) {
    if (n < 2) {
        return n;
    }
    struct Matrix q;
    q.mat[0][0] = q.mat[0][1] = q.mat[1][0] = 1;
    q.mat[1][1] = 0;
    struct Matrix res = matrixPow(q, n - 1);
    return res.mat[0][0];
}