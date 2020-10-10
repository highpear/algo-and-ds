#include <stdio.h>
#include <string.h>

char *encrypto(const char *, const char *);

void main(void) {

    // 暗号化テーブルを定義
    char table[] = {'Q','W','E','R','T','Y','U','I','O','P',
                    'A','S','D','F','G','H','J','K','L','Z',
                    'X','C','V','B','N','M','?'};
    
    char *p,*crypto = "KSOIDHEPZ";  // 暗号メッセージ
    
    int index;
    p = crypto;

    printf("\"%s\" -> \"", crypto);

    while (*p != '\0'){
        if ('A'<=*p && *p<='Z')
            index = *p-'A';
        else
            index = 26;  // A～Z以外は'?'
        
        putchar(table[index]);
        p++;
    }
    printf("\"\n");

}

