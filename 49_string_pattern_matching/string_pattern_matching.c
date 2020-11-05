#include <stdio.h>
#include <string.h>

char *search_str(char *text, char *key);

void main(void) {

    static char text[] = "This is a pen. That is a pencil.";  // 照合対象の文字列
    char *p, *key = "pen";  // "pen"が存在するか調べる

    // 文字列の表示
    printf("text: %s\n", text);
    printf("key: %s\n", key);
    
    printf("\nresult:\n");

    p = search_str(text, key);  // 文字列の照合を実行

    if(p == NULL) {  // 一致無しの場合
        printf("unmatched: %s\n", key);
        return;
    }
    
    while(p != NULL) {
        // 見つかった場合，一致箇所以降を表示
        printf("%s\n", p);
        // 一致箇所以降を再照合
        p = search_str(p + strlen(key), key);
    }
}

// 文字列textの中から文字列keyが存在する場所を返す関数
char *search_str(char *text, char *key) {

    int text_len, key_len;  // それぞれの文字列の長さ
    char *p;

    // 文字列の長さを取得
    text_len = strlen(text);
    key_len = strlen(key);

    for(p=text; p<=text+text_len-key_len; p++) {
        // 一致したらその場所へのポインタを返す
        if(strncmp(p, key, key_len) == 0) {
            return p;
        }
    }

    // 見つからない場合，NULLを返す
    return NULL;
}
