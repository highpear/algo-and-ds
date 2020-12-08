#include <stdio.h>
#include <stdlib.h>

#define Leaf -1  // 葉の判定 (データ保存時に使用)
#define YES 1
#define NO 0

FILE *fp;  // 保存データ入出力用

struct node {
    struct node *left;   // 左の子へのポインタ
    char data[30];       // 質問 or 質問の答え
    struct node *right;  // 右の子へのポインタ
};

typedef struct node NODE;
 
NODE *talloc(void);
NODE *read_tree(NODE *);
void write_tree(NODE *);

// getchar()でストリームに残留する改行文字を読むエラーを回避
int get_yesorno() {

    int c;

    while((c = getchar()) == '\n');  // 改行文字の場合は新たに読み込む

    if(c == 'y' || c == 'Y') {
        return YES;
    } else if (c == 'n' || c == 'N') {
        return NO;
    } else {  // y or n 以外の場合はエラーとして終了
        printf("error >> %d", c);
        exit(1);
    }
}

void main(void) {

    NODE *root = NULL;
    NODE *p, *old_ans, *new_ans;
    int c;

    // 決定木の初期化 (保存データの読み込み)
    if((fp = fopen("dbase.dat", "r")) == NULL) {

        // 決定木データが存在しなければ新たに作成
        root = talloc();
        printf("initial node ? (input answer) >>");
        scanf("%s", root->data);
        root->left = NULL;
        root->right = NULL;

    } else {
        
        // 既存データの読み込み
        root = read_tree(root);
        fclose(fp);
    }


    do {
        // 木の走査
        p = root;

        while(p->left != NULL) {

            printf("\n%s ? y/n >>", p->data);  // 質問を表示
            c = get_yesorno();

            if(c == YES) {
                // yes は左の子を出力
                p = p->left;
            } else {
                // no は右の子を出力
                p = p->right;
            }
        }

        // 答え合わせ
        printf("\nAnswer is [ %s ] . right ? y/n >>", p->data);
        c = get_yesorno();

        // no ならば学習を実行
        if(c == NO) {
            // ノードの移動
            old_ans = talloc();  // 現在の解答を保存
            *old_ans = *p;

            new_ans = talloc();

            printf("\nright answer ? >>");
            scanf("%s", new_ans->data);  // 新規解答を登録

            new_ans->left = NULL;
            new_ans->right = NULL;

            // 旧解答と新規解答を識別する質問の登録
            printf("question that distinguish %s and %s by yes or no ? >>", old_ans->data, new_ans->data);
            scanf("%s", p->data);

            printf("[yes] answer is %s . right ? y/n >>", old_ans->data);
            c = get_yesorno();

            // yes ならばそのまま接続処理
            if(c == YES) {
                p->left = old_ans;
                p->right = new_ans;
            } else {
                // no ならば逆に
                p->left = new_ans;
                p->right = old_ans;
            }
        }

    } while(printf("\ncontinue ? y/n "), c = get_yesorno(), c == YES);

    printf("\n");

    // 決定木データを保存して終了
    if((fp = fopen("dbase.dat", "w")) != NULL) {
        write_tree(root);
        fclose(fp);
    }
}

// 保存データから決定木情報を読み込む 
NODE *read_tree(NODE *p) {

    int flag; // 葉の判定フラグ

    p = talloc();
    fscanf(fp, "%30s%4d", p->data, &flag);
    
    if(flag == Leaf) {
        p->left = NULL;
        p->right = NULL;
    } else {
        p->left = read_tree(p->left);
        p->right = read_tree(p->right);
    }

    return p;
}

// 決定木情報をファイルに保存
void write_tree(NODE *p) {

    if(p != NULL) {

        if(p->left == NULL) {  // 葉の場合
            fprintf(fp, "%30s%4d\n", p->data, Leaf);
        } else {
            // 左の子があれば葉ではない
            fprintf(fp, "%30s%4d\n", p->data, !Leaf);
        }
        
        write_tree(p->left);
        write_tree(p->right);
    }
}

// メモリの確保
NODE *talloc(void) {

    return (NODE *)malloc(sizeof(NODE));
}
