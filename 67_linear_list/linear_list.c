#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tel_field{

    char name[20];           // 名前
    char tel[20];            // 電話番号
    struct tel_field *next;  // 次のデータへのポインタ

};

typedef struct tel_field TEL_FIELD;
TEL_FIELD *head;  // リストの先頭を示すポインタ

TEL_FIELD *talloc(void);
void free_list(TEL_FIELD *p);
void link(char *key);
void del(char *key);
void disp_list(void);

void main(void) {

    TEL_FIELD *p,     // 一時処理用ポインタ
              *old;   // 1つ前に追加したデータを示すポインタ

    head = talloc();  // ダミーノードの作成
    old = head;       // 初期状態の old は head


    // 標準入力から初期リストを作成 (リストに Alice を含める)
    // データの逐次入力を受付
    while(p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
        old->next = p;  // old (1つ前のノード) が新規データを指すようにする
        old = p;           // 新規データ追加後，自身を old として更新
    }
    rewind(stdin);

    old->next = NULL;  // 終端ノードが指す先はNULL


    p = head->next;    // p が先頭ノードを指すように更新

    // リストの要素を先頭から順に出力
    disp_list();

    // Alice の次に誰かを追加
    link("Alice");

    // 挿入後のリストを追加
    disp_list();

    // Alice を削除
    del("Alice");

    // 削除後のノードを表示
    disp_list();

    // リストのメモリ開放
    free_list(head);
}

// TEL_FIELDのメモリを確保し，そのポインタを返す関数
TEL_FIELD *talloc(void) {

    return (TEL_FIELD *)malloc(sizeof(TEL_FIELD));
}

// TEL_FIELDのリストのメモリ領域を開放する関数
void free_list(TEL_FIELD *p) {

    TEL_FIELD *tmp;

    // p から先のノードを全て開放
    while(p != NULL) {
        tmp = p;
        p = p->next;  // p を次ノードに更新してから
        free(tmp);    // q を開放 
    }
}

// 該当するkeyの後にノードを追加する関数
void link(char *key) {

    TEL_FIELD *p, *new_node;

    new_node = talloc();  // 新規ノードを取得
    
    printf("new data ?\n>> ");
    scanf("%s %s", new_node->name, new_node->tel);

    p = head;  // リストの先頭を取得

    while(p != NULL) {  // リストの要素を走査
        if(strcmp(key, p->name) == 0) {  // key が一致
            new_node->next = p->next;    // 新規ノードが"一致したノードの次ノード"を指すように更新
            p->next = new_node;          // 一致したノードが新規ノードを指すように更新

            return;
        }
        p = p->next;
    }

    printf("key: [%s] not found\n", key);
}

// 一致するkeyのノードを削除する関数
void del(char *key) {

    TEL_FIELD *p, *tmp;

    p = tmp = head;  // リストの先頭を取得
    
    while(p != NULL) {
        if(strcmp(key, p->name) == 0) {
            if(p == head) {  // 先頭ノードの削除は，先頭を示すポインタを変更するだけ
                head = p->next;
            } else {         // 先頭ノード以外の削除
                tmp->next = p->next;  // 「1つ前のノードの次ノード」を，「削除するノードの次ノード」に変更
            }
            printf("[%s] deleted", key);
            
            return;
        }

        tmp = p;      // 1つ前のノードを保持
        p = p->next;  // 探索を次ノードに更新
    }

    printf("key: [%s] not found\n", key);
}

// リストの全要素を表示する
void disp_list(void) {
    
    TEL_FIELD *p;

    p = head;
    while(p != NULL) {
        printf("%15s%15s\n", p->name, p->tel);
        p = p->next;
    }
}
