#include <stdio.h>

#define MAX_SIZE 100  // スタックのサイズ

int stack[MAX_SIZE];  // スタック
int sp = 0;           // スタックポインタ

int push(int);
int pop(int*);

void main(void) {

    int c, n;

    // スタックへの操作を逐次受付
    while(printf("]"), (c = getchar()) != EOF) {
        rewind(stdin);
        
        // スタックへのデータの追加
        if((c == 'i') || (c == 'I')) {

            printf("input data >> ");
            scanf("%d", &n);
            rewind(stdin);
            
            if(push(n) == -1) {
                printf("error: stack is filled\n");
            }
        }

        // スタックからデータを取り出す
        if((c == 'o') || (c == 'O')) {

            if(pop(&n) == -1) {
                printf("error: stack is empty\n");
            } else {
                printf("data = %d\n", n);
            }
        }
    }
}

// スタックにデータを追加
int push(int n) {

    if(sp < MAX_SIZE) {  // データが追加可能
        stack[sp] = n;
        sp++;
        return 0;
    } else {
        return -1;  // スタックがサイズを超えるとき
    }
}

// スタックからデータを取り出す
int pop(int *n) {

    if(sp > 0) {  // 取り出すデータが存在するとき
        sp--;
        *n = stack[sp];
        return 0;
    } else {
        return -1;  // スタックが空のとき
    }
}
