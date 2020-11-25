#include <stdio.h>

char stack[50], polish[50];
int pri[256];  // 優先順位
int sp1, sp2;  // スタックポインタ

void infix_to_reverse_polish(char *p);
void print_polish();

void main(void) {

    char *p = "(a+b)/c+(d+(e-f))";  // 変換対象の式

    // 中置記法を逆ポーランド記法に変更して配列polishに格納
    infix_to_reverse_polish(p);

    // 逆ポーランド記法に変換した数式を出力
    print_polish();

}

void infix_to_reverse_polish(char *p) {

    for(int i=0; i<=255; i++) {  // 優先順位の初期化
        pri[i] = 3;              // 全因子の優先順位を3で初期化 (数値も該当)
    }

    // 変換に対応している演算子の優先順位を設定
    pri['+'] = pri['-'] = 1;
    pri['*'] = pri['/'] = 2;
    pri['('] = 4;  // 最高に設定
    pri[')'] = 0;  // 最低に設定

    // 番兵の設定
    stack[0] = 0;
    pri[0] = -1;
    sp1 = sp2 = 0;
    
    while(*p != '\0') {  // 入力式の終わりまで
        while(pri[*p] <= pri[stack[sp1]] && stack[sp1]!='(') {
            polish[++sp2] = stack[sp1--];  // stackから取り出してpolishに積む
        }
        if(*p != ')') {  // 括弧の終わりでない限りstackに積む
            stack[++sp1] = *p;
        } else {
            sp1--;  // 括弧の始まりを捨てる
        }
        p++;
    }

    for(int i=sp1; i>0; i--) {  // スタックの残りを取り出す
        polish[++sp2] = stack[i];
    }
}

// 逆ポーランド記法の数式を出力する関数
void print_polish() {

    for(int i=1; i<=sp2; i++) {
        putchar(polish[i]);
    }
    printf("\n");
}
