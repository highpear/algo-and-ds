#include <stdio.h>
#include <math.h>

char stack[50], polish[50];
double v[50];
int pri[256];  // 優先順位
int sp1,sp2;   // スタックポインタ

void infix_to_polish(char *);
void print_polish();
void calc_rpn(char *);

void main(void) {

    char *p = "(6+3)/(6-2)+3*2^3-1", *expression = p;  // 計算する中置記法の式

    infix_to_polish(expression);

    // 逆ポーランド記法の式を出力する
    printf("RPN: ");
    print_polish();

    // 計算を実行して結果を表示
    calc_rpn(expression);

}

// 中置記法の式を逆ポーランド記法に変換して配列polishに格納する関数
void infix_to_polish(char *expression) {

    char *p = expression;

    for(int i=0; i<=255; i++) {  // 優先順位の初期化
        pri[i] = 4;              // 全因子の優先順位を3で初期化 (数値も該当)
    }

    // 変換に対応している演算子の優先順位を設定
    pri['+'] = pri['-'] = 1;
    pri['*'] = pri['/'] = 2;
    pri['^'] = 3;  // 前章から新たにべき乗を導入
    pri['('] = 5;  // 最高に設定
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

// 逆ポーランド記法の式を計算し，答えをv[1]に格納する関数
void calc_rpn(char *expression) {

    sp1 = 0;
    for(int i=1; i<=sp2; i++) {

        if('0' <= polish[i] && polish[i] <= '9') {
            v[++sp1] = polish[i] - '0';  // 数値はvに積む
        } else {  // 演算子の場合はvに積まれた2値に対して演算を実行
            switch(polish[i]) {
                // 各演算子に応じた処理
                case '+': v[sp1-1] = v[sp1-1] + v[sp1]; break;
                case '-': v[sp1-1] = v[sp1-1] - v[sp1]; break;
                case '*': v[sp1-1] = v[sp1-1] * v[sp1]; break;
                case '/': v[sp1-1] = v[sp1-1] / v[sp1]; break;
                case '^': v[sp1-1] = pow(v[sp1-1], v[sp1]); break;
            }
            sp1--;
        }
    }

    printf("%s = %f\n", expression, v[1]);  // 計算結果を出力
}