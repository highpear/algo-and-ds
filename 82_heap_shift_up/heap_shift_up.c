#include <stdio.h>

void main(void) {

    int heap[100];  // heap構造を実現する配列
    int n, s, p, tmp;

    n = 1;  // index (簡単の為，1始まりとする)
    while(scanf("%d", &heap[n]) != EOF) {  // ヒープの最後の要素として追加

        s = n;
        p = s / 2;  // 親の位置
        // 上方移動
        while(s >= 2 && heap[p] > heap[s]) {
            
            // 親子の交換処理
            tmp = heap[p];
            heap[p] = heap[s];
            heap[s] = tmp;
            
            // 位置を更新
            s = p;
            p = s / 2;
        }

        n++;  // インデックスをインクリメント
    }

    // ヒープデータの出力
    for(int i=1; i<n; i++) {
        printf("%d ", heap[i]);  // 1始まりに注意
    }
    printf("\n");
}
