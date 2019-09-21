//p1308 ex

#include <cstdio>

int main () {

    char a[1001];
    int state, ans = 0;

    gets(a);

    if(a[0] == ' ') state = 0;//设置初始值
    else state = 1;

    for(int i = 1; a[i]; i ++ ) {//要从一开始遍历，因为零已经遍历过了
        if(a[i] == ' ') {//是空格
            if(state == 1) {//当前状态（前一个）是字母，说明找到一个单词了
                ans ++ ;//答案加一
                state = 0;//千万别忘了改状态
            }
        }
        else {//是字母
            if(state == 0) {//当前状态（前一个）是空格
                state = 1;//将状态改为1
            }
        }
    }

    if(state == 1)//最后还要判断一下千万不要忘记
        ans ++ ;
    printf("%d", ans);

    return 0;
}
