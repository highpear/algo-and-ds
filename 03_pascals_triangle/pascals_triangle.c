#include <stdio.h>
#define N 12  // nCrでn=Nまで描画する

long combination(int, int);

void main(void) {

    for (int n=0; n<=N; n++) {  // n行目
        // 空白
        for (int t=0; t<(N-n)*3; t++) {  // n行目は(N-n)個分の空白が必要 (数値の3桁分を考慮して3を乗じている)
            printf(" ");
        }
        // nCrの値を出力
        for (int r=0; r<=n; r++) {
            printf("%3ld   ", combination(n, r));
        }
        
        printf("\n");
    }
}

long combination(int n, int r) {

    long ans = 1;

    for (int i=1; i<=r; i++) {
        ans = ans * (n-i+1)/i;
    }
  
    return ans;
}