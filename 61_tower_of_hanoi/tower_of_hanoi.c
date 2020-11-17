#include <stdio.h>

void init_hanoi();
void hanoi(int, char, char, char);
void move(int, int, int);

int pie[20][3];  // 円盤の最大枚数20，棒の数3
int sp[3], N;     // 各棒の円盤を管理するスタックポインタ，円盤の枚数

void main(void) {

    N = 3;  // 円盤の枚数
    init_hanoi();             // ハノイの塔を初期化
    hanoi(N, 0, 1, 2);  // 操作手順を出力
}

// ハノイの塔シミュレーションの初期化
void init_hanoi() {

    for(int i=0; i<N; i++) {  // 棒ａに円盤を積む
        pie[i][0] = N-i;
    }

    // スタックポインタの初期設定
    sp[0] = N;
    sp[1] = 0;
    sp[2] = 0;
}

// 再帰を用いてハノイの塔の手順を求める関数
void hanoi(int n, char a, char b, char c) {

    if(n > 0) {
        hanoi(n-1, a, c, b);  // 円盤(n-1)を a -> c ( b は作業用)
        // 手順を文字列で出力
        // printf("[ Disc No.%d ] moved to |%c| from |%c|\n", n, b, a);  //  円盤 n を a -> b
        
        // 操作手順のシミュレーションを実行
        move(n, a, b);

        hanoi(n-1, c, b, a);  // 円盤(n-1)を c -> b ( a は作業用)
    }
}

// 円盤nをsからdへ移すシミュレーションを実行
void move(int n, int s, int d) {

    // [棒のスタックポインタ][棒を表す番号]で指定
    pie[sp[d]][d] = pie[sp[s]-1][s];  // 円盤を s から ｄ へ移動
    
    // スタックポインタの更新
    sp[d]++;  // 棒dは増えた
    sp[s]--;  // 棒sは減った

    printf("\nmove No. %d to %c from %c\n\n", n, 'a'+s, 'a'+d);

    // 操作完了後のスタックを出力
    for(int i=N-1; i>=0; i--) {
        for(int j=0; j<3; j++) {
            if(i < sp[j]) {
                printf("%8d", pie[i][j]);
            } else {
                printf("        ");
            }
        }
        printf("\n");
    }

    printf("\n       a       b       c\n");

    // シミュレーションを1つずつ出力する場合    
    // rewind(stdin);
    // getchar();
}
