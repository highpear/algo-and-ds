#include <stdio.h>
#include <stdlib.h>

#define N 20  // 1～Nの乱数による順列を生成

int randn(int);

void main(void) {
    
    int flag;            // 重複確認用フラグ (flag==1で重複)
    int perm[N+1];       // ランダムな順列を格納

    perm[1] = randn(N);  // 1番目の要素を決定

    for (int i=2; i<=N; i++) {
        do {
            perm[i] = randn(N);
            flag = 0;
            for (int j=1; j<i; j++)  // 確定済みの順列の要素全てに対して重複をチェック
                if (perm[i] == perm[j]) {
                    flag = 1;        // 重複ありでflagを1にする
                    break;           // breakして乱数の生成からやり直す
                }
        } while(flag==1);  // 重複がある限り繰り返す
    }

    // 生成した順列の表示 (indexは1から)
    for (int i=1; i<=N; i++)
        printf("%d ",perm[i]);
    printf("\n");
}

// 整数1～nの乱数を生成する関数
int randn(int n) {
    return (int)(rand()/(RAND_MAX+0.1)*n+1);
}
