#include <stdio.h>

void hanoi(int, char, char, char);

void main(void) {

    int n;

    n = 3;  // 円盤の枚数
    hanoi(n, 'a', 'b', 'c');
}

// 再帰を用いてハノイの塔の手順を求める関数
void hanoi(int n, char a, char b, char c) {

    if(n > 0) {
        hanoi(n-1, a, c, b);  // 円盤(n-1)を a -> c ( b は作業用)
        printf("[ Disc No.%d ] moved to |%c| from |%c|\n", n, b, a);  //  円盤 n を a -> b
        hanoi(n-1, c, b, a);  // 円盤(n-1)を c -> b ( a は作業用)
    }
}
