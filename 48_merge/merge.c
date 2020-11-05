#include <stdio.h>

#define NUM_A 10  // 昇順ソート済み配列aの要素数
#define NUM_B 5   // 昇順ソート済み配列bの要素数

void print_array(int array[], int n);
void merge_array(int a[], int an, int b[], int bn, int c[]);

void main(void) {

    int a[] = {2,  4,  5,  7,  8, 10, 15, 20, 30, 40},  // 要素数10
        b[] = {6, 11, 25, 33, 35},                      // 要素数5
        c[NUM_A+NUM_B];  // マージ後の配列

    // a[]の表示
    printf("a[] = ");
    print_array(a, NUM_A);
    // b[]の表示
    printf("b[] = ");
    print_array(b, NUM_B);

    // a[], b[]をc[]へマージ
    merge_array(a, NUM_A, b, NUM_B, c);

    // マージ後のc[]の表示
    printf("(merged) c[] =");
    print_array(c, NUM_A+NUM_B);

}

// 配列の全要素を表示する関数 
void print_array(int array[], int n) {

    for(int i=0; i<n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// int型a[], b[]をc[]へマージする関数
void merge_array(int a[], int an, int b[], int bn, int c[]) {  // an: a[]の要素数，bn: b[]の要素数

    int i, j, p;  // 順に配列 a, b, c のindex

    i = j = p = 0;  // index の初期化
    
    // 小さい方の要素を順次c[]へコピーする処理．コピー後は各indexを進める
    while((i < an) && (j < bn)) {  // a[], b[]どちらかが終端に達するまで
        // 小さい方の要素をc[]へコピー
        if(a[i] <= b[j]) {  // a[i]が小さい
            c[p] = a[i];
            p++;
            i++;
        } else {            // b[j]が小さい
            c[p] = b[j];
            p++;
            j++;
        }
    }

    // 以下，残りの要素をすべてc[]へコピーする処理

    // a[]の要素が残っている場合
    while(i < an) {
        c[p] = a[i];
        p++;
        i++;
    }
    
    // b[]の要素が残っている場合
    while(j < bn) {
        c[p] = b[j];
        p++;
        j++;
    }
}
