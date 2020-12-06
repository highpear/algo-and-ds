#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *left;   // 左部分木へのポインタ
    char ope;            // 項目
    struct node *right;  // 右部分木へのポインタ
};

typedef struct node NODE;

NODE *talloc(void);
NODE *add_tree(NODE *, char *);

void prefix(NODE *);
void infix(NODE *);
void postfix(NODE *);

void main(void) {

    NODE *root;
    char expression[] = "ab*cd+e/-";  // 入力する式

    root = NULL;
    root = add_tree(root, expression);  // 式の木を生成

    // 式の木の表示
    printf("\nprefix  = ");
    prefix(root);  // 行きがけ順
    
    printf("\ninfix   = ");
    infix(root);  // 通りがけ順 

    printf("\npostfix = ");
    postfix(root);  // 帰りがけ順
    
    printf("\n");
}

// 式の木の作成
NODE *add_tree(NODE *root, char *w) {

    NODE *p = root;
    int n;

    n = strlen(w);  // 因子の数
    p = talloc();   // 新規ノード

    p->ope = w[n-1];  // 文字列の終端をノードにする
    w[n-1] = '\0';    // 終端を除く
    
    if(!(p->ope == '-' || p->ope == '+' || p->ope == '*' || p->ope == '/')) {  // 定数ならば
        p->left = NULL;
        p->right = NULL;
    } else {
        // 演算子ならば
        p->right = add_tree(p->right, w);
        p->left = add_tree(p->left, w);
    }

    return p;
}

// 接頭形
void prefix(NODE *p) {

    if(p != NULL) {
        putchar(p->ope);  // 出力
        prefix(p->left);
        prefix(p->right);
    }
}

// 挿入形
void infix(NODE *p) {

    if(p != NULL) {
        infix(p->left);
        putchar(p->ope);  // 出力
        infix(p->right);
    }
}

// 接尾形 = 逆ポーランド記法
void postfix(NODE *p) {
    
    if(p != NULL) {
        postfix(p->left);
        postfix(p->right);
        putchar(p->ope);  // 出力
    }
}

// メモリの確保
NODE *talloc(void) {

    return (NODE *)malloc(sizeof(NODE));
}
