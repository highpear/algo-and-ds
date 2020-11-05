#include <stdio.h>
#include <string.h>

char *search_str_bm(char *text, char *key);
void table(char *key);

int skip[256];  // スキップテーブル用の配列 (charの各値に対応)

void main(void) {

    static char text[] = "This is a pen. That is a pencil.";  // 照合対象の文字列
    char *p, *key = "pen";  // "pen"が存在するか調べる

    // 文字列の表示
    printf("text: %s\n", text);
    printf("key: %s\n", key);

    table(key);  // keyからスキップテーブルを作成
    printf("\nresult:\n");

    p = search_str_bm(text, key);  // 文字列の照合を実行
    
    if(p == NULL) {  // 一致無しの場合
        printf("unmatched: %s\n", key);
        return;
    }
    
    while(p != NULL) {
        // 見つかった場合，一致箇所以降を表示
        printf("%s\n", p);
        // 一致箇所以降を再照合
        p = search_str_bm(p + strlen(key), key);
    }
}

// スキップテーブルを作成する関数
void table(char *key) {

    int len = strlen(key);
    
    // 全ての要素をkeyの文字数で初期化．照合対象の文字がkeyに含まれない文字か，keyの右端文字ならばこの値だけずらす
    for(int k=0; k<=255; k++) {
        skip[k] = len;
    }

    // keyに含まれる文字について，進める値を格納する
    for(int k=0; k<len-1; k++) {
        skip[key[k]] = len - 1 - k;
    }
}

// Boyer-Moore法により文字列照合を行う関数
char *search_str_bm(char *text, char *key) {

    int text_len, key_len;  // それぞれの文字列の長さ
    char *p;

    // 文字列の長さを取得
    text_len = strlen(text);
    key_len = strlen(key);

    p = text + key_len - 1;  // 最初はtextとkeyで先頭を合わせて，keyの右端文字を基準に比較

    while(p < text + text_len) {
        if(*p == key[key_len-1]) {  // 右端の文字だけ比較
            if(strncmp(p-key_len+1, key, key_len) == 0) {  // 右端文字が一致したのでキー全体を比較
                return p - key_len + 1;                    // マッチした場所を返す
            }
        }
        p = p + skip[*p];  // サーチ位置を進める (進める値はchar型の値をindexにもつ要素)
    }
    return NULL;
}
