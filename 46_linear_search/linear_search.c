#include <stdio.h>
#include <string.h>

#define N 10  // 探索対象のデータの要素数

void main(void) {

    struct girl {
        char name[20];  // 名前
        int age;        // 年齢
    } a[N+1] = {"Ann",    18, "Rolla",    19,  // 番兵の分 (+1) を確保
                "Nancy",  16, "Eluza",    17,
                "Juliet", 18, "Machilda", 20,
                "Emy",    15, "Candy",    16,
                "Ema",    17, "Mari",     18};
    
    char key[20];  // 以下で name の値をkeyとする
    int idx=0;

    // 探索する key を入力する
    printf("Name? >>");
    scanf("%s", key);

    strcpy(a[N].name, key);  // key を番兵としてコピー

    // データの先頭から走査し，見つかればループを抜ける
    while(strcmp(key, a[idx].name) != 0) {
        idx++;
    }

    if(idx < N) {  // idxが一致したデータのindexとなっている
        printf("Name: %s Age: %d\n", a[idx].name, a[idx].age);
    } else {  // 見つからずに探索のループを終了した場合，idx = Nとなる
        printf("Not found %d\n", idx);
    }
}
