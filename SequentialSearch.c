#include <stdio.h>
#include <stdlib.h>

#define N 10
int s[N];

void InitArray() //配列ランダム生成
{
    for(int i=0; i<N ;i++){
        s[i] = rand()%100;  //100より小さい数
        printf("%d ",s[i]);
    }
    printf("\n");
}

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
    InitArray();
    printf("探索する値：");
    scanf("%d",&x);
    i = SequentialSearch(x);
    if(i == -1) printf("%2dはありませんでした\n",x);
    else printf("%2d番目に%2dを発見\n",i+1,x);
	return 0;
}
