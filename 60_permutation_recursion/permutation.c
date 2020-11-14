#include <stdio.h>

#define N 4  // 1,2,3,4からなる順列を全て求める
int p[N+1];  // 順列を生成する配列 (indexと項番号を合わせる為，(N+1)だけ確保)

void perm(int);
void perm_order(int i);

void main(void) {

    // ?,1,2,3,4で初期化
    for(int i=1; i<=N; i++) {
        p[i] = i;
    }

    // 順列の生成を実行
    perm(1);  // 第1項から交換を開始

    // 辞書順に生成
    printf("\ndictionary order:\n");
    perm_order(1);
}

// 再帰により順列を生成する関数
void perm(int i) {

    int tmp;

    if(i < N) {  // 交換の起点は第(n-1)項まで
        for(int j=i; j<=N; j++) {

            // p[i] と p[j] の交換
            // j は i から n までとる
            tmp = p[i];
            p[i] = p[j];
            p[j] = tmp;
            
            perm(i+1);  // 交換の起点を1つ進めて再帰呼び出し
                        // 交換を繰り返す
            
            // 元に戻す
            tmp = p[i];
            p[i] = p[j];
            p[j] = tmp;
        }
    } else {  // 生成した順列を表示
        for(int j=1; j<=N; j++) {
            printf("%d ", p[j]);
        }
        printf("\n");
    }
}

// 再帰により順列を"辞書順"に生成する関数
void perm_order(int i) {
    
    int tmp;

    if(i < N) {
        for(int j=i; j<=N; j++) {
            // p[i]～p[j]の右ローテート処理

            tmp = p[j];  // j は交換の起点 i から配列の最後までのNを取る
            
            for(int k=j; k>i; k--) {  // 右ローテートを実行

                // i: 交換の起点 j:ローテートの対象
                // [i] ... --[j]--> ... ... [N]
                //    <-- <-- k
                p[k] = p[k-1];
            }

            p[i] = tmp ;

            perm_order(i+1);

            for(int k=i; k<j; k++) {  // 配列の並びを再帰呼び出し前に戻す
                p[k] = p[k+1];
            }

            p[j] = tmp;
        }
    } else {
        for(int j=1; j<=N; j++) {
            printf("%d ", p[j]);
        }
        printf("\n");
    }
}