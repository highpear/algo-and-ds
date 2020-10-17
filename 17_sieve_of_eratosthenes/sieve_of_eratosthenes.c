#include <stdio.h>
#include <math.h>

#define NUM 1000

void main(void) {

    int prime[NUM+1];  // 配列の要素にふるいから落とされたかどうかを記録
    int end;

    // 全要素を1で初期化 (ふるいから何も落とされていない初期状態)
    for (int i=2; i<=NUM; i++) {
        prime[i] = 1;
    }

    end = (int)sqrt((double)NUM);  // 素数と仮定する数はこの値まで行えば良い (ふるいから落とすかどうかの対象は全範囲)

    for(int i=2; i<=end; i++) {
        if(prime[i] == 1) {        // ふるいから落とされていない場合のみ計算する
            for (int j=2*i; j<=NUM; j++) {
                if(j%i == 0) {     // 割り切れたものはふるいから落とす
                    prime[j] = 0;  // 削除済みを0で表現
                }
            }
        }
    }

    // 求めた全ての素数を表示
    printf("\nprime numbers are...\n");
    for (int i=2; i<=NUM; i++) {
        if (prime[i] == 1) {  // ふるいに残っている数のみ表示
            printf("%5d", i);
        }
    }
    printf("\n");
}
