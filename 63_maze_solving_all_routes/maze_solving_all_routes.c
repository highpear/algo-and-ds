#include <stdio.h>

// まわりを2(=通行不可)で埋めて壁をつくる
int maze[9][9] = {{2, 2, 2, 2, 2, 2, 2, 2,2},
                  {2, 0, 0, 0, 0, 0, 0, 0,2},
                  {2, 0, 2, 2, 0 ,2, 2, 0,2},
                  {2, 0, 2, 0, 0, 2, 0, 0,2},
                  {2, 0, 2, 0, 2, 0, 2, 0,2},
                  {2, 0, 0, 0, 0, 0, 2, 0,2},
                  {2, 2, 0, 2, 2 ,0, 2, 2,2},
                  {2, 0, 0, 0, 0, 0, 0, 0,2},
                  {2, 2, 2, 2, 2, 2, 2, 2,2}};

int Si, Sj, Ei, Ej, success;
// 通過位置を入れるスタック
int sp, ri[100], rj[100]; 

int visit(int, int);

void main(void) {

    sp = 0;       // スタックポインタを初期化
    success = 0;  // ゴールしたかを示すフラグ

    // スタートの座標を設定
    Si = 1;
    Sj = 1;
    // ゴールの座標を設定
    Ei = 7;
    Ej = 7;

    printf("\nall routes are ...\n");
    if((visit(Si, Sj)) == 0) {
        printf("cannot find GOAL\n");
    }

    printf("\n");

    // 解けた経路を格子状に表示
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(maze[i][j] == 1) {  // 通過ルート
                printf("■ ");
            } else if(maze[i][j] == 2) {  // 通行不可，壁
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

    static int path = 1;

    maze[i][j] = 1;  // 通過済みを1でマーク
    // 通過したマスをスタックに積む
    ri[sp] = i;
    rj[sp] = j;
    sp++;

    if((i == Ei) && (j == Ej)) {  // ゴールに到達

        printf("\npath %d:\n", path++);  // 通過点の表示
        for(int k=0; k<sp; k++) {
            printf("(%d, %d) -> ",ri[k], rj[k]);
        }
        printf("\n");
        success = 1;
    }

    // 各4方向の探索を行う
    if(maze[i][j+1] == 0) {
        visit(i, j+1);
    }
    if(maze[i+1][j] == 0) {
        visit(i+1, j);
    }
    if(maze[i][j-1] == 0) {
        visit(i, j-1);
    }
    if(maze[i-1][j] == 0) {
        visit(i-1, j);
    }

    sp--;         // スタックから捨てる
    maze[i][j] = 0;  // 別経路の探索のため0に戻す

    return success;
}
