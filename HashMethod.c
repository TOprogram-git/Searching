#include <stdio.h>
#define N 18
#define m 27

int s[N] = {3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32}; //配列初期化
int htb[m];

int hash(int x) //ハッシュ値を求める
{
    x = x%m;
    return x;
}

void HashMethod(int s[]) //ハッシュ法でデータを配列:htb[]に蓄える
{
    int x,j;
    for(int i=0; i<m; i++) htb[i] = 0;
    for(int i=0; i<N; i++){
        x = s[i];
        j = hash(x);
        while(htb[j] != 0) j = (j+1)%m;
        htb[j] = x;
    }
}

int Search(int x) //探索
{
    int j;
    j = hash(x);
    while(htb[j] != 0 && htb[j] != x) j = j%m;
    if(x == htb[j]) return j;
    return -1;
}

int main(){
    int x,i;
    
    HashMethod(s);
    for(int j=0; j<m; j++) printf("%d ",htb[j]); //ハッシュ法でデータを格納した配列表示
    printf("\n");
    
    printf("探索する値：");
    scanf("%d",&x);
    i = Search(x);
    if(i == -1) printf("%2dはありませんでした\n",x);
    else printf("%2d番目に%2dを発見\n",i+1,x);
    return 0;
}
