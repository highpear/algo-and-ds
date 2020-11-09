#include <stdio.h>

long combination(int n, int r);

void main(void) {

    int n = 10;
    int r = 5;

    printf("%dC%d=%ld\n", n, r, combination(n, r));

}

// 再帰を用いてコンビネーションの計算を行う関数
long combination(int n, int r) {

    if(r==0 || r==n) {
        return 1L;
    } else {
        return combination(n-1, r) + combination(n-1, r-1);
    }
}
