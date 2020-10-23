#include <stdio.h>
#include <math.h>

#define f(x) ((x)*(x)*(x)-(x)+1)  // 根を求める関数の定義
#define g(x) (3*(x)*(x)-1)        // f(x)の1階微分，接線の導出で使用
#define EPS 1e-8                  // 打ち切り誤差
#define LIMIT 50                  // 打ち切り回数

void main(void) {

    double x = -2.0;  // 根近傍の適当な初期値を設定
    double dx;
    int k;

    for(k=1; k<=LIMIT; k++) {
        dx = x;               // 1つ前のxを保存
        x = x - f(x) / g(x);  // 式(2)の計算により次のxを導出
        // 終了条件の判定
        if(fabs(x-dx) < fabs(dx)*EPS) {
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
