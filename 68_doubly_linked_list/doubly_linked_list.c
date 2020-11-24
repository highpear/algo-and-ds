#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tel_field {
    struct tel_field *prev;  // 逆ポインタ
    char name[20];           // 名前
    char tel[20];            // 電話番号
    struct tel_field *next;  // 順ポインタ
};

typedef struct tel_field TEL_FIELD;

void disp_forward(TEL_FIELD *head);
void disp_reverese(TEL_FIELD *tail);
TEL_FIELD *talloc(void);

void main(void) {

    TEL_FIELD *head, *tail, *p;

    tail = NULL;  // 逆リストの作成
    
    // リストに値を逐次追加
    while(p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
        p->prev = tail;  // 新規ノードの prev を tail に設定
        tail = p;        // tail を新規ノードとして更新
    }

    // 順リストの作成
    p = tail;
    head = NULL;
    // 順ポインタの設定 (tail から遡りながら next を設定)
    while(p != NULL) {
        p->next = head;  // 現在のノードの次ノードを head に設定
        head = p;        // head を現在のノードで更新
        p = p->prev;     // ノードを1つ遡る
    }

    // リストを順方向に表示
    printf("\nforward direction\n");
    disp_forward(head);

    // リストを逆方向に表示
    printf("\nreverse direction\n");
    disp_reverese(tail);

}


// headから順方向にリストを表示する関数
void disp_forward(TEL_FIELD *head) {

    TEL_FIELD *p = head;

    while(p != NULL) {
        printf("%15s%15s\n", p->name, p->tel);
        p = p->next;
    }
}

// tailから逆方向にリストを表示する関数
void disp_reverese(TEL_FIELD *tail) {

    TEL_FIELD *p = tail;

    while(p != NULL) {
        printf("%15s%15s\n", p->name, p->tel);
        p = p->prev;
    }
}

// TEL_FIELDのメモリを確保し，そのポインタを返す関数
TEL_FIELD *talloc(void) {

    return (TEL_FIELD *)malloc(sizeof(TEL_FIELD));
}
