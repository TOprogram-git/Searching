#include <stdio.h>
#include <math.h>

#define N 18
#define m 5

int s[N] = {3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32}; //配列初期化

int min(int j,int n) //ブロックの末尾の値
{
    if(j < n) return j;
    else return n;
}

int mBlockSearch(int x) //m-ブロック法
{
    int j = 0;
    int k = ceil(N/m);
    while(j <= m-2){
        if(x <= s[ (j+1)*k - 1]) break; //xを含むブロックの探索
        else j++;;
    }
    int i = j*k;
    int t = min((j+1)*k-1,N-1);
    while(i<t){
        if(s[i] >= x) break; //ｘがあるか探索
        else i++;
    }
    if(x == s[i]) return i;
    return -1;
}

int main(){
    int x,i;
    printf("探索する値：");
    scanf("%d",&x);
    i = mBlockSearch(x);
    if(i == -1) printf("%2dはありませんでした\n",x);
    else printf("%2d番目に%2dを発見\n",i+1,x);
    return 0;
}
