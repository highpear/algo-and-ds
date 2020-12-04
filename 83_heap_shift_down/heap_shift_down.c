#include <stdio.h>

void swap_int(int *, int *);

void main(void) {

    int heap[100];  // heapを実現する配列
    int n, p, s, m;

    n = 1;  // indexを1始まりとする
    while(scanf("%d", &heap[n]) != EOF) {  // データを木に割り当てる
        n++;
    }

    m = n - 1;  // データ数

    for(int i=m/2; i>=1; i--) {  // 子を持つ最後の親からrootまで
        p = i;      // 親の位置
        s = 2 * p;  // 左の子の位置
        
        while(s <= m) {  // 子<=親 を満たす間

            if(s < m && heap[s+1] < heap[s]) {  // 左と右の子の小さい方
                s++;
            }

            if(heap[p] <= heap[s]) {  // 親<=子 で抜ける
                break;
            }

            // 親子の交換
            swap_int(&heap[p], &heap[s]);
            
            // 親子の位置の更新
            p = s;
            s = 2 * p;
        }
    }

    // ヒープデータの出力
    for(int i=1; i<=m; i++) {
        printf("%d ", heap[i]);  // 1始まりに注意
    }
    printf("\n");
}

// int型変数の値の交換を行う関数
void swap_int(int *a, int *b) {
    
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
