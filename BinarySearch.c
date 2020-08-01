#include <stdio.h>
#define N 18

int s[N] = {3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32}; //配列初期化

int BinarySearch(int x) //2分探索
{
    if(x < s[0] || s[N-1] < x) return -1;
    
    int left=0, right=N-1; //探索区間の設定
    int mid;
    do{
        mid = (left+right)/2; //探索区間の中央
        if(x < s[mid]) right = mid-1;
        else left = mid+1;
    }while(left <= right);
    if(x == s[right]) return right;
    return -1;
}

int main(){
    int x,i;
    printf("探索する値：");
    scanf("%d",&x);
    i = BinarySearch(x);
    if(i == -1) printf("%2dはありませんでした\n",x);
    else printf("%2d番目に%2dを発見\n",i+1,x);
    return 0;
}
