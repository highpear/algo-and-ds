#include <stdio.h>
#include <math.h>

#define f(x) ((x)*(x)*(x)-(x)+1)  // 根を求める関数の定義
#define EPS 1e-8                  // 打ち切り誤差
#define LIMIT 50                  // 打ち切り回数

void main(void) {

    double low, high, x;
    int k;

    // 根を挟む値で初期化
    low = -2.0;
    high = 2.0;

    // 収束しない時の為，ループの打ち切り回数も決めておく
    for(k=1; k<=LIMIT; k++) {
        // xの範囲の中点を導出
        x = (low + high) / 2;

        if(f(low)*f(x) < 0) {  // 根が2分割した範囲の小さい方(左)にある時
            high = x;          // 現在の中点をhighに更新 (左側に狭める)
        } else {               // 根が2分割した範囲の大きい方(右)にある時
            low = x;           // 現在の中点をlowに更新 (右側に狭める)
        }
        // 終了条件の判定
        if(f(x)==0 || fabs(high-low) < fabs(low)*EPS) {
            printf("x = %f (k=%d)\n", x, k);
            printf("検算: x^(3)-x+1 = %f\n" , x*x*x-x+1);
            break;
        }
    }

    // 収束しない場合 (打ち切り回数を超過)
    if(k > LIMIT) {
        printf("収束しない\n");
    }
}
