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
        root = add_tree(root, tmp);  // 入力データから木を作成
    }

    // レベル別の表示
    treewalk(root);
}

// 2分木をレベル別に走査する
void treewalk(NAME_NODE *root) {
    
    NAME_NODE *p = root;
    NAME_NODE *q[128],  // ポインタテーブル
              *w[128];  // 作業用
    int child, n, level;

    // 初期化
    child = 1;  // rootは1つ
    q[0] = p;   // root
    level = 0;  // rootのレベルは0
    
    do {
        n = 0;  // スタックポインタを初期化
        printf("level %d :", level);
        
        for(int i=0; i<child; i++) {  // 全ての子を表示し，それぞれの子へのポインタをスタックに積む
            
            printf("%12s", q[i]->name);  // ノードの表示
            
            // 1つ下のレベルの子へのポインタをスタックに積む
            if(q[i]->left != NULL) {
                w[n++] = q[i]->left;
            }
            if(q[i]->right != NULL) {
                w[n++] = q[i]->right;
            }
        }
        printf("\n");
        child = n;  // １つ下のレベルの子の数

        for(int i=0; i<child; i++) {
            q[i] = w[i];  // 次の表示に使用する為コピー
        }

        level++;
    } while(child != 0);  // 子の数が0で終了
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
