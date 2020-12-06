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
void postfix(NODE *);

void main(void) {

    NODE *root;
    char expression[] = "53*64+2/-";  // 計算する式

    root = NULL;
    root = add_tree(root, expression);  // 式の木を生成

    postfix(root);  // 式の計算
    printf("value = %d\n", root->ope);  // 走査終了後のrootが解
}

// 式の木の作成
NODE *add_tree(NODE *p, char *w) {
    
    int n;

    n = strlen(w);  // 因子の数
    p = talloc();   // 新規ノード
    
    if('0' <= w[n-1] && w[n-1] <= '9') {  // 定数のとき
        p->ope = w[n-1] - '0';            // 数値に変換
    } else {
        p->ope = w[n-1];
    }

    w[n-1] = '\0';  // 終端を除く

    if(!(p->ope == '-' || p->ope == '+' || p->ope == '*' || p->ope == '/')){  // 定数ならば
        p->left = NULL;
        p->right = NULL;
    } else {
        // 演算子ならば
        p->right = add_tree(p->right, w);
        p->left = add_tree(p->left, w);
    }

    return p;
}

// 式の木を帰りがけ順で走査しながら計算する
void postfix(NODE *p) {

    if(p != NULL) {
        postfix(p->left);
        postfix(p->right);
        switch(p->ope) {
            // 各演算子の計算を左右の子に対して実行
            case '+': p->ope = (p->left->ope) + (p->right->ope); break;
            case '-': p->ope = (p->left->ope) - (p->right->ope); break;
            case '*': p->ope = (p->left->ope) * (p->right->ope); break;
            case '/': p->ope = (p->left->ope) / (p->right->ope); break;
        }
    }
}

// メモリの確保
NODE *talloc(void) {

    return (NODE *)malloc(sizeof(NODE));
}
