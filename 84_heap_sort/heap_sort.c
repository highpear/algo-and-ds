#include <stdio.h>

void swap_int(int *, int *);
void shiftdown(int, int, int []);
void shiftdown_reverse(int, int, int []);

void main(void) {

    int heap[100];
    int n, m;

    n = 1;
    while(scanf("%d", &heap[n]) != EOF) {  // データを木に割り当てる
        n++;
    }

    m = n - 1;  // ヒープのデータ数
    
    // 初期ヒープの生成
    for(int i=m/2; i>=1; i--) {
        
        shiftdown(i, m, heap);  // 子を持つ最後の親から下方移動
        
        // shiftdown_reverse(i, m, heap);  // 昇順ソートの場合
    }

    // 最小値の切り離し
    while(m > 1) {
        swap_int(&heap[1], &heap[m]);  // root(最小値)とヒープの末尾を交換
        m--;                           // 木の終端(最小値)を切り離す
        
        shiftdown(1, m, heap);         // ヒープを再構成 (新たに交換された要素[1]を起点とする)
        
        // shiftdown_reverse(1, m, heap);  //昇順ソートの場合
    }

    // 降順ソートされた配列を出力
    for(int i=1; i<n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// ヒープにおいて下方移動を行う関数 (p=親の位置，n=ヒープのサイズ)
void shiftdown(int p, int n, int heap[]) {

    int s = 2 * p;  // 子の位置

    while(s <= n) {
        if(s<n && heap[s+1] < heap[s]) {  // 左と右の子の小さい方を選択
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

// 親子の大小関係が逆になるように下方移動を行う関数
void shiftdown_reverse(int p, int n, int heap[]) {

    int s = 2 * p;  // 子の位置

    while(s <= n) {
        if(s<n && heap[s+1] > heap[s]) {  // 左と右の子の"大きい方"を選択
            s++;
        }

        if(heap[p] >= heap[s]) {  // 親>=子 で抜ける
            break;
        }

        // 親子の交換
        swap_int(&heap[p], &heap[s]);

        // 親子の位置の更新
        p = s;
        s = 2 * p;
    }
}

// int型変数の値の交換を行う関数
void swap_int(int *a, int *b) {
    
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
