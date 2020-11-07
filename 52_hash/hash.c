#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 1050 // ハッシュ値最大 0～1049 まで対応
#define MOD_SIZE   1000 // ハッシュ関数によるハッシュ値は 0～999

int hash(char *str);

struct DATA {  // 管理するデータのテーブル
    char name[20];
    char telnum[20];
    int  is_used;  // 使用済みは 1 を割り当てる
} data[TABLE_SIZE];

void main(void) {

    int n;
    char name[20], telnum[20];

    printf("name: phone number: >>\n");
    while(scanf("%s %s", name, telnum) != EOF) {

        n = hash(name);  // 式(1)により求めたハッシュ値

        // テーブルを確認
        while((data[n].is_used == 1) && (n < TABLE_SIZE)) {
            n++;  // 未使用値になるまでハッシュ値をインクリメント
        }
        
        // データの登録
        if(n < TABLE_SIZE) {
            strcpy(data[n].name, name);
            strcpy(data[n].telnum, telnum);
            data[n].is_used = 1;  // 使用済みに変更
        } else {
            printf("Data table is unavailable.\n");
        }
    }

    rewind(stdin);

    // データのサーチ
    printf("\nname? >>\n");
    while(scanf("%s", name) != EOF) {
        
        n = hash(name);
        
        while((strcmp(name, data[n].name)!=0) && n<TABLE_SIZE) {
            n++;  // 登録された名前と一致するまでハッシュ値をインクリメント
        }

        if(n<TABLE_SIZE) {  // 名前，電話番号を表示
            printf("[%d] %15s%15s\n", n, data[n].name, data[n].telnum);
        } else {
            printf("Not found.\n");
        }
    }
}

// 文字列を 0～999 までのハッシュ値に写像する関数
int hash(char *str) {

    int n = strlen(str);
    
    return (str[0]-'A'
              + (str[n/2-1] - 'A') * 26
              + (str[n-2] - 'A') * 26 * 26
            ) % MOD_SIZE;
}
