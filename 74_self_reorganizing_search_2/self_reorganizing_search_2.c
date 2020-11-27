#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tel_field {
    char name[20];           // 名前
    char tel[20];            // 電話番号
    struct tel_field *next;  // 次ノードへのポインタ
};

typedef struct tel_field TEL_FIELD;

void disp_list(TEL_FIELD *head);
TEL_FIELD *talloc(void);

void main(void) {

    char key[20];  // 探索に用いるキー
    TEL_FIELD *head, *p, *old1, *old2, *tmp;

    // リストの作成
    head = NULL;

    while(p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
        p->next = head;
        head = p;
    }

    rewind(stdin);

    // リストを表示
    printf("list:\n");
    disp_list(head);

    // ダミーノードを作成してheadとする
    p = talloc();
    p->next = head;
    head = p;

    // 探索
    while(printf("Name ? >>"), scanf("%s", key) != EOF) {
        p = head->next;
        old1 = old2 = head;

        // 逐次探索を実行
        while(p != NULL) {

            if(strcmp(key, p->name) == 0) {  // 探索終了

                printf("%15s%15s\n", p->name, p->tel);
                
                if(p != head->next){       // 先頭でないとき
                    tmp = old1->next;      // 1つ前を保持
                    old1->next = p;        // 自身を1つ戻す
                    old2->next = p->next;  // 次ノードと繋げる
                    p->next = tmp;         // 1つ前だったものを次ノードに更新
                }

                break;
            }

            old1 = old2;
            old2 = p;
            p = p->next;
        }
    }

    // 探索後のリストを表示
    printf("\nlist:\n");
    disp_list(head);
}

// リストを表示する関数
void disp_list(TEL_FIELD *head) {

    TEL_FIELD *p = head;

    while(p != NULL) {
        printf("%15s%15s\n", p->name, p->tel);
        p = p->next;
    }
}

// TEL_FIELDのメモリを確保し，そのポインタを返す関数
TEL_FIELD *talloc(void) {

    return (TEL_FIELD *)malloc(sizeof(TEL_FIELD));
}
