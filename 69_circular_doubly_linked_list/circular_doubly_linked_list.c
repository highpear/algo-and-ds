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

TEL_FIELD *talloc(void);
void disp_forward(TEL_FIELD *head);
void disp_reverese(TEL_FIELD *head);

void main(void) {

    TEL_FIELD *head, *p;

    head = talloc();  // ダミーノードの作成
    head->prev = head->next = head;  // 初期状態はダミーノード自体を指す

    // ノードを逐次作成
    while( p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
        // 以下の順番に注意
        p->next = head;        // 新規ノードの次ノードをheadとする (循環の為)
        p->prev = head->prev;  // 新規オードの前ノードをheadの前とする (headの前は，1つ前に追加済みのデータ)
        head->prev->next = p;  // headの前ノードの次ノードを新規ノードとする (1つ前に追加済みのデータが新規ノードを指すようにする)
        head->prev = p;        // headの前ノードを新規ノードとする (循環の為)
    }

    // リストを順方向に表示
    printf("\nforward direction\n");
    disp_forward(head);

    // リストを逆方向に表示
    printf("\nreverse direction\n");
    disp_reverese(head);

}

// headから順方向にリストを表示する関数
void disp_forward(TEL_FIELD *head) {

    TEL_FIELD *p = head->next;

    while(p != head) {
        printf("%15s%15s\n", p->name, p->tel);
        p = p->next;
    }
}

// headの前から逆方向にリストを表示する関数
void disp_reverese(TEL_FIELD *head) {

    TEL_FIELD *p = head->prev;

    while(p != head) {
        printf("%15s%15s\n", p->name, p->tel);
        p = p->prev;
    }
}

// TEL_FIELDのメモリを確保し，そのポインタを返す関数
TEL_FIELD *talloc(void) {

    return (TEL_FIELD *)malloc(sizeof(TEL_FIELD));
}