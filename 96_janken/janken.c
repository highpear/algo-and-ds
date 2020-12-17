#include <stdio.h>

void main(void) {

    int human, computer, M, judge;
    int table[3][3] = {{0, 0, 0},  // 戦略テーブル (人間の手を保存)
                       {0, 0, 0},
                       {0, 0, 0}},

        hist[3] = {0, 0, 0};  // 勝敗の度数
    char *hand[3] = {"グー", "チョキ", "パー"};

    M = 0;
    while(1) {
        if(table[M][0] > table[M][1] && table[M][0] > table[M][2]) {
            // チョキよりグーを出しやすく，かつパーよりグーを出しやすい
            computer = 2;  // グーに勝つのはパー
        } else if(table[M][1] > table[M][2]) {
            // パーよりチョキを出しやすい
            computer = 0;  // チョキに勝つのはグー
        } else {
            computer = 1;  // その他はチョキ
        }

        printf("0:グー 1:チョキ 2:パー\n");
        printf("あなたの手 >>");
        scanf("%d", &human);

        printf("コンピュータの手: %s\n", hand[computer]);

        judge = (computer - human + 3) % 3;  // 勝敗の判定
        switch(judge) {
            case 0: printf("引き分け\n"); break;
            case 1: printf("あなたの勝ち\n"); break;
            case 2: printf("コンピュータの勝ち\n"); break;
        }

        hist[judge]++;      // 勝敗を更新
        table[M][human]++;  // 学習
        M = human;          // 1つ前の手を更新
        printf("--- (computer) %d勝%d敗%d分 ---\n\n", hist[1], hist[2], hist[0]);
    }
}
