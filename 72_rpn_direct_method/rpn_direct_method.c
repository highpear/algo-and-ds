#include <stdio.h>

#define MAX(a, b) ((a) > (b)? (a): (b))
#define MIN(a, b) ((a) < (b)? (a): (b))

double v[50];  // 計算用スタック
char ope[50];  // 演算子用スタック
int pri[256];  // 優先順位
int sp1, sp2;  // スタックポインタ

void calc(void);

void main(void) {

    char *expression = "(1>2|2<8|3<4)|(9<2)", *p = expression;  // 計算を行う中置記法の式

    // 優先順位の初期化
    pri['|'] = 1;             // 独自に定義した算術平均の演算子
    pri['<'] = pri['>'] = 2;  // MAX, MIN演算を行う演算子
    pri['('] = 3;
    pri[')'] = 0;
    
    // 番兵
    ope[0] = 0;
    pri[0] = -1;
    sp1 = sp2 = 0;

    while(*p != '\0') {
        if('0' <= *p && *p <= '9') {  // 数字の場合はその値をvに積む
            v[++sp2] = *p - '0';
        } else {  // 演算子の場合
            while(pri[*p] <= pri[ope[sp1]] && ope[sp1] != '(') {  // '('以外は演算を実行
                calc();
            }

            if(*p != ')') {
                ope[++sp1] = *p;
            } else {
                sp1--;  // '('を取り除く
            }
        }
        p++;
    }

    while(sp1 > 0) {  // 演算子スタックが空になるまで
        calc();
    }

    // 計算結果の出力
    printf("%s = %f\n", expression, v[1]);
}

// 演算子に応じて計算を行う関数
void calc(void) {

    switch(ope[sp1]) {
        case '|' : v[sp2-1] = (v[sp2-1] + v[sp2]) / 2; break;
        case '>' : v[sp2-1] = MAX(v[sp2-1], v[sp2]); break;
        case '<' : v[sp2-1] = MIN(v[sp2-1], v[sp2]); break;
    }

    sp2--;
    sp1--;
}
