#include <stdio.h>

#define N 6  // ソート対象の要素数

void print_array(int array[], int n);
void selection_sort(int array[], int n);

void main(void) {

    // ソートする配列
    int a[] = {80, 41, 35, 90, 40, 20};
    
    // 配列の表示
    printf("ソート前:\n");
    print_array(a, N);

    // 選択ソートの実行
    selection_sort(a, N);

    // 配列の表示
    printf("ソート済:\n");
    print_array(a, N);

}

// 配列の全要素を表示する関数 
void print_array(int array[], int n) {

    for(int i=0; i<N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// int型配列を選択ソートで昇順ソートする関数
void selection_sort(int array[], int n) {

    int min, s, tmp;

    for(int i=0; i<n-1; i++) {
        
        min = array[i];             // 最小値を自身で初期化
        s = i;

        for(int j=i+1; j<n; j++) {  // 自身以降の全要素について

            if(array[j] < min) {    // 最小値を求める
                min = array[j];
                s = j;              // 最小値のインデックスを記録
            }
        }

        // i番目とs番目を入れ替え
        tmp = array[i];
        array[i] = array[s];
        array[s] = tmp;
    }
}