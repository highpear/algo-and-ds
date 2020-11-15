#include <stdio.h>

// まわりを2(=通行不可)で埋めて壁をつくる
int maze[7][7] = {{2, 2, 2, 2, 2, 2, 2},
                  {2, 0, 0, 0, 0, 0, 2},
                  {2, 0, 2, 0 ,2, 0, 2},
                  {2, 0, 0, 2, 0, 2, 2},
                  {2, 2, 0, 2, 0, 2, 2},
                  {2, 0, 0, 0, 0, 0, 2},
                  {2, 2, 2, 2, 2, 2, 2}};

int Si, Sj, Ei, Ej, success;

// 通過経路を記録するスタック
int sp;
int ri[100], rj[100];

int visit(int, int);

void main(void) {

    sp = 0;       // スタックポインタを初期化 
    success = 0;  // ゴールしたかを示すフラグ
    
    // スタートの座標を設定
    Si = 1;
    Sj = 1;
    // ゴールの座標を設定
    Ei = 5;
    Ej = 5;

    if((visit(Si, Sj)) == 0) {  // 解けない場合
        printf("cannot find GOAL\n");
    }

    printf("\n");

    // 解けた経路を格子状に表示
    for(int i=0; i<7; i++) {
        for(int j=0; j<7; j++) {
            if(maze[i][j] == 1) {  // 通過ルート
                printf("■ ");
            } else if(maze[i][j] == 2) { // 通行不可，壁
                printf("× ");
            } else {
                printf("□ ");
            }
        }
        printf("\n");
    }
}

// 迷路の探索を再帰的に行う関数 (ゴールに到達したら1を返す)
int visit(int i, int j) {
    
    maze[i][j] = 1;  // 通過済みを1でマーク
    // 通過したマスをスタックに積む
    ri[sp] = i;
    rj[sp] = j;
    sp++;

    if((i == Ei) && (j == Ej)) {  // ゴールに到達

        printf("\nroute is ...\n");
        // 通過経路の表示
        for(int k=0; k<sp; k++) {
            printf("(%d, %d) -> ", ri[k], rj[k]);
        }
        printf("GOAL\n");

        success = 1;
    }
     
    // 各4方向の探索を行う
    if((success != 1) && (maze[i][j+1] == 0)) {
        visit(i, j+1);
    }
    if((success != 1) && (maze[i+1][j] == 0)) {
        visit(i+1, j);
    }
    if((success != 1) && (maze[i][j-1] == 0)) {
        visit(i, j-1);
    }
    if((success != 1) && (maze[i-1][j] == 0)) {
        visit(i-1, j);
    }

    sp--;  // スタックから捨てる
    return success;
}
