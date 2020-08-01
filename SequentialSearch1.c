#include <stdio.h>
#include <stdlib.h>

#define N 18
int s[N] = {3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32}; //配列初期化：今後探索ではこの配列を用いる

int SequentialSearch(int x) //遂次探索
{
    int i = 0;
    do{
        if(x == s[i]) return i; //配列の先頭から順番に探索する
        else i = i + 1;
    }while(i < N);
    return -1;
}

int main(){
    int x,i;
    printf("探索する値：");
    scanf("%d",&x);
    i = SequentialSearch(x);
    if(i == -1) printf("%2dはありませんでした\n",x);
    else printf("%2d番目に%2dを発見\n",i+1,x);
    return 0;
}
