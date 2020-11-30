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
NAME_NODE *search_by_name(NAME_NODE *, char *);

void main(void) {

    char tmp[12], key[12];
    NAME_NODE *root, *p;

    root = NULL;
    while(scanf("%s", tmp) != EOF) {
        root = add_tree(root, tmp);  // 入力されたデータにより新規ノードを作成
    }
    p = root;

    rewind(stdin);

    // nameから探索
    while(printf("search: name ? >>"), scanf("%s", key) != EOF) {
        if((p = search_by_name(root, key)) != NULL) {
            printf("%s exists\n", p->name);
        } else {
            printf("not found [%s]\n", key);
        }
    }
}

// ノードを新規作成して2分探索木に接続する関数
NAME_NODE *add_tree(NAME_NODE *parent, char *data) {

    NAME_NODE *p = parent;

    if(p == NULL) {  // 親が存在しない (ルートの作成)
        
        p = talloc();
        strcpy(p->name, data);
        p->left = p->right = NULL;

    } else if (strcmp(data, p->name) < 0) {  // 新規データの方が親より小さい = 左部分木へ
        
        p->left = add_tree(p->left, data);
    } else {  // 新規データの方が親より大きい = 右部分木へ
        
        p->right = add_tree(p->right, data);
    }

    return p;
}

// keyと名前が一致するノードを探索する関数
NAME_NODE *search_by_name(NAME_NODE *root, char *key) {

    NAME_NODE *p = root;

    if((p == NULL) || (strcmp(key, p->name) == 0)) {  // 一致なしor発見した場合
        return p;
    }

    if(strcmp(key, p->name) < 0) {  // keyが左部分木に存在するであろう場合
        return search_by_name(p->left, key);
    } else {                        // keyが右部分木に存在するであろう場合
        return search_by_name(p->right, key);
    }
}

// メモリの確保
NAME_NODE *talloc(void) {

    return (NAME_NODE *)malloc(sizeof(NAME_NODE));
}
