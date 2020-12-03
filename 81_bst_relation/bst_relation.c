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

    // 親との関係性の出力
    treewalk(root);
}

// 2分木をレベル別に走査する
void treewalk(NAME_NODE *root) {

    struct connect {      // 接続関係を示す構造体
        NAME_NODE *node;  // 子ノード
        char *parent;     // 親の名前
        char direct;      // 左の子or右の子を表す
    } q[128], w[128];     // 配列を用意

    NAME_NODE *p = root;
    int child, n, level;

    // rootの状態で初期化
    child = 1;
    level = 0;
    q[0].node = p;     // root
    q[0].parent = "root";
    q[0].direct =' ';  // rootは右でも左でもない

    do {
        n = 0;
        printf("level %d :\n", level);

        for(int i=0; i<child; i++) {
            // ノードの表示
            printf("%12s->%c:%12s\n", q[i].parent, q[i].direct, q[i].node->name);
            // 1つ下のレベルの子へのポインタをメンバにもつ構造体をスタックに積む
            if(q[i].node->left != NULL) {

                w[n].parent = q[i].node->name;  // 親情報を歩保存
                w[n].direct = 'l';              // 左右どちらの子か保存
                w[n].node = q[i].node->left;    // ポインタを保存
                n++;                            // スタックポインタを更新
            }
            if(q[i].node->right != NULL) {      // 以下，右の場合も同様

                w[n].parent = q[i].node->name;
                w[n].direct = 'r';
                w[n].node = q[i].node->right;
                n++;
            }
        }

        child = n;  // 1つ下のレベルの子の数
        
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
