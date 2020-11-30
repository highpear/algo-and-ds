#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name_node {
    struct name_node *left;  // 左部分木へのポインタ
    char name[12];           // 名前
    struct name_node *right; // 右部分木へのポインタ
};

typedef struct name_node NAME_NODE;

NAME_NODE *search_min(NAME_NODE *root);
NAME_NODE *search_max(NAME_NODE *root);
NAME_NODE *talloc(void);

void main(void) {

    char tmp[12];  // 名前の入力を待ち受ける
    NAME_NODE *root, *p, *old;

    printf("name ? >>");

    // ルートの作成
    root = talloc();
    scanf("%s", root->name);  // 最初のデータをルートに入れる
    root->left = root->right = NULL;

    while(scanf("%s", tmp) != EOF) {
        p = root;

        // 新規ノードを接続する親を探索
        while(p != NULL) {
            old = p;
            if(strcmp(tmp, p->name) <= 0) {
                p = p->left;
            } else {
                p = p->right;
            }
        }

        p = talloc();  // 新規ノードの接続
        strcpy(p->name, tmp);
        p->left = p->right = NULL;

        if(strcmp(tmp, old->name) <= 0) {
            old->left = p;
        } else {
            old->right = p;
        }
    }

    // 最小要素・最大要素をそれぞれ出力
    search_min(root);
    search_max(root);

}

// 最小ノードを出力する関数 (左を辿る)
NAME_NODE *search_min(NAME_NODE *root) {

    NAME_NODE *p = root;

    while(p->left != NULL) {
        p = p->left;
    }
    printf("MIN: %s\n", p->name);
    return p;
}

// 最大ノードを出力する関数 (右を辿る)
NAME_NODE *search_max(NAME_NODE *root) {

    NAME_NODE *p = root;

    while(p->right != NULL) {
        p = p->right;
    }
    printf("MAX: %s\n", p->name);
    return p;
}

// NAME_NODEのメモリ確保
NAME_NODE *talloc(void) {

    return (NAME_NODE *)malloc(sizeof(NAME_NODE));
}
