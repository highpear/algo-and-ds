#include <stdio.h>

#define N 9  //  ソート対象の要素数

void print_array(int array[], int n);
void shaker_sort(int array[], int n);

void main(void) {

    // ソートする配列
    int a[] = {3, 5, 6, 9, 2, 7, 8, 10, 4};
    
    // 配列の表示
    printf("ソート前:\n");
    print_array(a, N);

    // シェーカーソートの実行
    shaker_sort(a, N);

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

// int型配列をシェーカーソートで昇順ソートする関数
void shaker_sort(int array[], int n) {

    int left, right;  // 走査範囲の左端・右端
    int shift;        // 最後に交換した場所のindex
    int tmp;

    left = 0;       // 走査範囲左端の初期値は[0]
    right = n - 1;  // 配列の最終要素のindex

    while(left < right) {

        // --> --> 左から走査 --> -->
        for(int i=left; i<right; i++) {

            if(array[i] > array[i+1]) {
                // 左 < 右 になるように交換する
                tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
                // 交換が発生したindexを記録
                shift = i;  // [i] と [i+1] で交換した
            }
        }

        // 走査範囲の右端を更新，右から走査の開始点とする
        right = shift;
        
        // <-- <-- 右から走査 <-- <--
        for(int i=right; i>left; i--) {

            if(array[i-1] > array[i]) {
                // 左 < 右 になるように交換する
                tmp = array[i];
                array[i] = array[i-1];
                array[i-1] = tmp;
                // 交換が発生したindexを記録
                shift = i;  // [i-1] と [i] で交換した
            }
        }

        // 走査範囲の左端を更新，左から走査の開始点とする
        left = shift;
    }
}