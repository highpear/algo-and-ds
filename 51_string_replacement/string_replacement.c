#include <stdio.h>
#include <string.h>

#define STR_LEN 128  // 各行の文字数，及び退避用配列のサイズ

void replace_str(char *text, char *key, char *rep);
void print_str(char char_2d_array[][STR_LEN]);
char *search_str(char *text, char *key);

void main(void) {

    int k;  // 行番号
    static char text[][STR_LEN] = {"     --- サルビアの花 ---",
                                   "いつもいつも思ってた",
                                   "サルビアの花をあなたの部屋の中に",
                                   "投げ入れたくて",
                                   "そして君のベッドに",
                                   "サルビアの紅い花しきつめて",
                                   "僕は君を死ぬまで抱きしめていようと",
                                   ""};  // 配列の終端を表す

    // 原文の表示
    printf("original:\n");
    print_str(text);

    // 以下，置換処理
    printf("\nreplaced:\n");
    k = 0;
    // 各行ごと逐次置換してから表示
    while(text[k][0] != '\0') {
        replace_str(text[k], "サルビア", "か す み 草");
        replace_str(text[k], "紅", "白");
        printf("%s\n", text[k]);
        k++;
    }
}

// text 中の key を rep に置換する関数
void replace_str(char *text, char *key, char *rep) {

    char *p, buf[STR_LEN];

    p = search_str(text,key);

    while(p != NULL) {
        
        *p = '\0';  // null文字で初期化
        strcpy(buf, p+strlen(key));  // key "より"後ろから text 最後までを buf にコピー
        strcat(text, rep);           // 置換分 rep を text に連結
        strcat(text, buf);           // 退避した buf を text に連結 (連結された rep の終端文字以降から)
        p = search_str(p+strlen(rep), key);
    }
}

// 2次元文字配列を表示する関数
void print_str(char char_2d_array[][STR_LEN]) {

    int k = 0;  // 2次元配列の行番号

    while(char_2d_array[k][0] != '\0') {
        printf("%s\n", char_2d_array[k]);
        k++;
    }
}

// 49_string_pattern_matching における文字列サーチ
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
