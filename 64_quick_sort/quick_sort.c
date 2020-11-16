#include <stdio.h>

void print_array(int array[], int n);
void quick_sort(int a[], int left, int right);
void quick_sort_mid_pivot(int a[], int left, int right);

#define N 10  // ソート対象の配列の要素数

void main(void) {

    // ソートする配列
    static int a[] = {41, 24, 76, 11, 45, 64, 21, 69, 19, 36};

    // 配列の表示
    printf("ソート前:\n");
    print_array(a, N);
    
    // クイックソートの実行
    // quick_sort(a, 0, N-1);
    quick_sort_mid_pivot(a, 0, N-1);

    // 配列の表示
    printf("ソート済:\n");
    print_array(a, N);

}

// 配列の全要素を表示する関数
void print_array(int array[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// int型配列をクイックソートで昇順ソートする関数
void quick_sort(int a[], int left, int right) {

    int s, tmp, i, j;

    // [i] --> --> --> 
    // <-- <-- <-- [j]

    if(left < right) {

        s = a[left];     // 左端の項を軸にする
        i = left;
        j = right + 1 ;
        
        while(1) {

            while(a[++i] < s);  // 軸より小さい要素のindexを探す
            while(a[--j] > s);  // 軸より大きい要素のindexを探す
            
            if(i >= j) {  // 左右からの走査が終了
                break;
            }

            // i, j要素の交換
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }

        a[left] = a[j];
        a[j] = s;  // 軸を正しい位置に入れる

        quick_sort(a, left, j-1);   // 左部分列に対する再帰呼び出し
        quick_sort(a, j+1, right);  // 右部分列に対する再帰呼び出し
    }
}

// 軸として配列の中央を用いたクイックソート
void quick_sort_mid_pivot(int a[], int left, int right) {

    int s, tmp, i, j;

    if(left < right) {

        s = a[(left + right) / 2];  // ※ 中央の値を軸にする
        i = left - 1;               // ※ 左端要素を含んで比較を行う
        j = right + 1;

        // --  --  以下，quick_sort() と同じ  --  --

        while(1) {

            while(a[++i] < s);
            while(a[--j] > s);

            if(i >= j) {
                break;
            }

            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }

        // --  --  ここまで同じ  --  --

        // quick_sort() と違い，軸を動かす必要がない

        quick_sort_mid_pivot(a, left, i-1);
        quick_sort_mid_pivot(a, j+1, right);
    }
}
