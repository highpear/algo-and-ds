#include <stdio.h>

long combination(int, int);

int main() {

    int n = 10;  // 10C5を求める
    int r = 5;

    printf("%dC%d=%ld\n", n, r, combination(n, r));
    return 0;
}

long combination(int n, int r) {
    
    long ans = 1;

    for(int i=1; i<=r; i++) {
        ans = ans*(n-i+1)/i;  // 漸化式より組み合わせを求める(rが小さい方から計算)
    }

    return ans;
}
