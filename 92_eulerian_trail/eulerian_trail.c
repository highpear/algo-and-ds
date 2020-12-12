#include <stdio.h>

#define NODE 4   // 節点の数
#define ROOT 6   // 辺の数
#define START 1  // 開始接点

int a[NODE+1][NODE+1] = {{0, 0, 0, 0, 0},  // 隣接行列
                         {0, 0, 1, 0, 1},  // 各要素は接続している辺の数を表す
                         {0, 1, 0, 1, 2},
                         {0, 0, 1, 0 ,1},
                         {0, 1, 2, 1, 0}};

int success;    // 経路を発見するごとにインクリメント
int v[ROOT+1];  // 経路を入れるスタック
int n;          // 未通過の辺の数

void visit(int);

void main(void) {

    success = 0;
    n = ROOT;

    // 開始点から探索を開始
    visit(START);

    if(success == 0) {  // 1つも経路が発見できない場合
        printf("解なし\n");
    }
}

// 接点iから順に探索を行う
void visit(int i) {

    v[n] = i;  // 訪問済み (接点を記憶)

    if(n==0 && i==START) {  // 存在する全ての辺を通過し，かつ元の節点に戻った時
                            // 始点に戻らなくても良い一筆書きでは， n==0 のみの条件で良い
        // 経路の出力
        printf("route %d:", ++success);

        for(i=0; i<=ROOT; i++) {
            printf("%d", v[i]);
        }
        printf("\n");
    
    } else {  // 一筆書きの経路を発見していない場合

        for (int j=1; j<=NODE; j++) {  // 他の連結している(辺が存在する)接点について接点1から順番に調べる
            if(a[i][j] != 0) {
                // 接点iと接点j間の辺を消去 (通過済みとする)
                a[i][j]--;
                a[j][i]--;
                n--;  // 残りの辺の数を更新
                // 節点jを始点として再度経路を探索
                visit(j);
                // 消去した節点iと節点j間の辺を修復する (行き場が無くなった場合の戻る処理)
                a[i][j]++;
                a[j][i]++;
                n++;
            }
        }
    }
}
