#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000
#define MOD_SIZE   1000
#define ADD_HEAD   1  // ADD_TAILは0

int hash(char *);

struct tel_field {
    char name[20];
    char tel[20];
    struct tel_field *next;
};

typedef struct tel_field TEL_FIELD;
TEL_FIELD *data[TABLE_SIZE];

TEL_FIELD *search_by_name(TEL_FIELD *p, char *name);
void disp_list(TEL_FIELD *head);
struct tel_field *talloc(void);

void main(void) {

    int n;
    char key[20];
    TEL_FIELD *p, *q;

    // ポインタテーブルの初期化
    for(n=0; n<TABLE_SIZE; n++) {
        data[n] = NULL;  // 登録データが無い時はNULLを指す
    }

    printf("name tel\n");
    while(p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
        n = hash(p->name);

        if(ADD_HEAD) {  // 新規ノードを各リストの先頭に追加
            
            p->next = data[n];  // 先頭に追加
            data[n] = p;
        
        } else {  // 終端に追加

            if(data[n] == NULL) {  // リストが空
    
                data[n] = p;  // 新規ノードをリストに追加
                p->next = NULL;
    
            } else {  // リストに既にデータが存在 = 衝突した場合
    
                q = data[n];  // 既存データ
                while(q->next != NULL) {
                    q = q->next;  // qが終端になるまで更新
                }

                q->next = p;  // qの次 = 終端に追加
                p->next = NULL;
            }            
        }
    }

    rewind(stdin);

    // 探索を実行
    printf("\nname ? >>");
    while(scanf("%s", key) != EOF) {
        n = hash(key);
        p = data[n];

        search_by_name(p, key);

        // リストの表示
        printf("list:\n");
        disp_list(data[n]);
    }
}

// 名前をkeyとしてリストを探索する関数
TEL_FIELD *search_by_name(TEL_FIELD *p, char *name) {
    
    while(p != NULL) {
        if(strcmp(name, p->name) == 0) {  // 発見
            printf("%15s%15s\n", p->name, p->tel);
            break;  // 衝突データも全表示する際はbreakしない
        }
        p = p->next;
    }
}

// 各リストのheadを与えて以降を表示する関数
void disp_list(TEL_FIELD *head) {

    TEL_FIELD *p = head;

    printf("HEAD -> ");
    while(p!= NULL) {
        printf("%s (%s) ", p->name, p->tel);
        p = p->next;
    }
    printf("\n");
}

// ハッシュ関数
int hash(char *s) {
    int n;

    n = strlen(s);
    return (s[0]-'A' + (s[n/2-1]-'A') * 26 + (s[n-2]-'A') * 26 * 26) % MOD_SIZE;
}

// TEL_FIELDのメモリを確保し，そのポインタを返す関数
TEL_FIELD *talloc(void) {

    return (TEL_FIELD *)malloc(sizeof(TEL_FIELD));
}
