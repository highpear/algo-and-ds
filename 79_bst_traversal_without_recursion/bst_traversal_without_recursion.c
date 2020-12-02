#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name_node {
    struct name_node *left;   // 左部分木へのポインタ
    char name[12];            // 名前
    struct name_node *right;  // 右部分木へのポインタ
};

typedef struct name_node NAME_NODE;

NAME_NODE *talloc(void);
NAME_NODE *add_tree(NAME_NODE *, char *);
void treewalk(NAME_NODE *);

void main(void) {

    char tmp[12];
    NAME_NODE *root;

    root = NULL;
    while(scanf("%s", tmp) != EOF) {
        root = add_tree(root, tmp);  // データを入力して木を生成
    }

    // 通りがけ順で出力
    printf("\n昇順\n");
    treewalk(root);
}

// 2分木を通りがけ順で走査
void treewalk(NAME_NODE *root) {

    NAME_NODE *p, *q, *w[128];
    int sp = 0;  // スタックポインタ

    p = root;
    q = p;  // rootから開始
    while(!(sp == 0 && q == NULL)) {  // 走査の継続条件
        // 可能な限り左側を走査
        while(q != NULL) {
            w[sp++] = q;  // 位置をスタックに積む
            q = q->left;  // 左へ
        }

        sp--;  // 親の位置を取得するためのデクリメント
        printf("%s\n", w[sp]->name);  // 親を表示
        q = w[sp]->right;  // 右へ進み同様の処理を繰り返す
    }
}

// ノードを新規作成して追加する関数
NAME_NODE *add_tree(NAME_NODE *parent, char *data) {

    NAME_NODE *p = parent;

    if(p == NULL) {
        p = talloc();
        strcpy(p->name, data);
        p->left = p->right = NULL;
    } else if(strcmp(data, p->name) < 0) {
        p->left = add_tree(p->left, data);
    } else {
        p->right = add_tree(p->right, data);
    }

    return p;
}

// メモリの確保
NAME_NODE *talloc(void) {

    return (NAME_NODE *)malloc(sizeof(NAME_NODE));
}
