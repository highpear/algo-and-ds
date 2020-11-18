#include <stdio.h>

int queue_in(int);
int queue_out(int *);
void disp(void);

#define MAX_SIZE 100  // キューのサイズ
int queue[MAX_SIZE];  // キューを実現する配列
int head = 0;         // 先頭データへのポインタ
int tail = 0;         // 終端データへのポインタ

void main(void) {

    int c, n;

    while(printf("]"), (c = getchar()) != EOF) {
        rewind(stdin);

        switch(c) {

            // キューへの追加
            case 'i':
            case 'I':
                    printf("input data >> ");
                    scanf("%d", &n);
                    rewind(stdin);
                    if(queue_in(n) == -1) {
                        printf("error: queue is filled\n");
                    }
                    break;
            
            // キューからの取り出し
            case 'o':
            case 'O':
                    if(queue_out(&n) == -1) {
                        printf("error: queue is empty\n");
                    } else {
                        printf("data = %d\n", n);
                    }
                    break;
            
            // キューの内容を表示
            case 'l':
            case 'L':
                    disp();
                    break;
        }
    }
}

// キューへのデータの追加を行う関数
int queue_in(int n) {

    if((tail+1) % MAX_SIZE != head) {  // キューに空きがあればデータを追加する
        queue[tail] = n;  // tail に新規データを追加
        tail++;           // tail を更新
        tail = tail % MAX_SIZE;  // リング構造を考慮
        return 0;
    } else {
        return -1;  // キューの空きがない
    }
}

// キューからデータを取り出す関数
int queue_out(int *n) {

    if(tail != head) {  // キューが空でなければ取り出しを行う
        *n = queue[head];  // head を取り出す
        head++;            // head を更新
        head = head % MAX_SIZE;  // リング構造を考慮
        return 0;
    } else {
        return -1;  // キューが空
    }
}

// キューの内容を表示する関数
void disp(void) {

    int i = head;
    while(i != tail) {  // head から順に表示
        printf("%d\n", queue[i]);
        i++;
        i = i % MAX_SIZE;
    }
}
