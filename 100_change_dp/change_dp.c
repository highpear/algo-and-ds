#include <stdio.h>

#define LIMIT 42  // この金額を最小枚数で構成する
#define N 3       // コインの種類 (1¢, 10¢, 25¢)

void main(void) {

    int size[] = {1, 10, 25};  // コインの金額をナップサックのサイズとする
    int value[LIMIT+1],  // コインの枚数 (コインによって構成する金額と添字が対応)
        item[LIMIT+1],   // コインの番号 (その金額において最後に追加したコインの番号を保存)
        s, p, newvalue;

    // 各金額を構成するコインの枚数を，それぞれの金額自体で初期化
    for(s=0; s<=LIMIT; s++) {
        value[s] = s;  // 最小化問題を解くため，初期値は大きな値で設定する
    }

    // DPを実行
    for(int i=0; i<N; i++) {  // 各3つのコインについて以下を実行
        for(s=size[i]; s<=LIMIT; s++) {  // ナップサックサイズ(コインの金額)を増やしながら最適解の候補を算出
            p = s - size[i];             // 空きサイズ(金額)を算出
            newvalue = value[p] + 1;     // 現在までの最適解と，自身の枚数1の和を新たな最適解の候補とする
            // 最適解の候補の判定
            if(newvalue <= value[s]) {  // より小さい方を最適解として更新
                value[s] = newvalue;
                item[s] = i;  // 最適解の更新
            }
        }
    }

    // 結果の出力
    printf("コインの枚数 = %2d枚 : ", value[LIMIT]);  // 42円(=LIMIT)を構成するコインの枚数の最小値
    for(s=LIMIT; s>0; s=s-size[item[s]]) {
        printf("(%2d)¢, ", size[item[s]]);  // 出力した分を除いた分の金額の最適解を順に出力していく
    }
    printf("\n");
}
