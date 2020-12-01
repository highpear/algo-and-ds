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
NAME_NODE *add_tree(NAME_NODE*, char *);
void treewalk(NAME_NODE *);
void treewalk_reverse(NAME_NODE *root);

void main(void) {

    char tmp[12];
    NAME_NODE *root;

    root = NULL;
    while(scanf("%s", tmp) != EOF) {  // 標準入力からノードを追加
        root = add_tree(root, tmp);
    }

    printf("\n");

    // 昇順に出力
    printf("昇順\n");
    treewalk(root);

    printf("\n");

    // 降順に出力
    printf("降順\n");
    treewalk_reverse(root);

}

// 2分木を走査して昇順表示する関数
void treewalk(NAME_NODE *root) {

    NAME_NODE *p = root;

    if(p != NULL) {
        treewalk(p->left);     // 左側を走査
        printf("%s\n", p->name);        
        treewalk(p->right);    // 右側を走査
    }
}

// 2分木を走査して降順表示する関数
void treewalk_reverse(NAME_NODE *root) {

    NAME_NODE *p = root;

    if(p != NULL) {
        treewalk_reverse(p->right);  // 右側を走査
        printf("%s\n", p->name);        
        treewalk_reverse(p->left);   // 左側を走査
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
