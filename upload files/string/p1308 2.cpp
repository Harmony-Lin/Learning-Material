//p1308  2
#include <cstdio>
#include <cctype>
#include <cstring>

const int SPACE = 0;//����״̬�����ǿո�״̬
const int LETTER = -1;//��ĸ״̬�������ʾ����Ҫ���ҵĵ��ʵ���ĸ��״̬
const int WORD = 1;//������״̬��Ҫ���ҵĵ��ʵ�״̬
//��Ȼ�ˣ����״̬ʱ����1������˵����Ҫ���ҵĵ��ʵ��м䲿�ֵ�״̬�����Ľ�����

inline void strlower (char *a) {//�����ͣ�����Ĵ�������
    for(int i = 0; a[i]; i ++ ) {
        if(isupper(a[i])) a[i] = tolower(a[i]);
    }
}

int main () {

    char a[1000001], word[20];
    int ans = 0;
    int ans2 = -1;
    int state = 0;//��״̬�������ǿո���Ϊ�ո��������ж��ǲ�������״̬
    int i;

    gets(word);
    gets(a);
    strlower(a);
    strlower(word);
    int len = strlen( word );

    for(i = 0; a[i]; i ++ ) {//��������
        switch ( state ) {
            case SPACE : //�����ǰ״̬����һ�����ǿո�
                if(a[i] == word[0]) state = WORD;//��ɵ��ʵ�һ����ĸ״̬
                else if(a[i] == ' ') state = SPACE;//��ʵ��仰����ʡ�ԣ���Ϊ�������ǿո�״̬��������һ����
                else state = LETTER;//ʣ�µĿ϶���������ĸ״̬��
                break;
            case LETTER : //��������ĸ״̬
                if(a[i] == ' ') state = SPACE;//�ո�״̬
                break;
            default: //��Ҫ���ҵĵ���״̬
                if ( state < len  ) {//���������һ����ĸ
                    if(a[i] == ' ') state = SPACE;
                    else if(a[i] == word[state]) state ++ ;//�����һ����ĸ״̬
                    else state = LETTER;//������ĸ״̬
                }
                else if (state == len )//�����һ����ĸ
                {   
                    if(a[i] == ' ') {//�����һ���ǿո��ҵ��ˣ�
                        state = SPACE;//״̬��Ҫ���Ǹı�
                            if(ans2 == -1)//��һ���ҵ�����¼����λ��
                                ans2 = i - len;//��Ϊi�ǵ��ʵ�β������Ҫ������
                        ans ++ ;//������һ
                    }
                    else state = LETTER;//��ϧ��������������ĸ�����ǵ���
                }
        }

    }

    if(state == len) {
        ans ++ ;
        if(ans2 == -1)
            ans2 = i - 1 - len;
    }
    if(ans2 == -1) printf("-1");
    else printf("%d %d", ans, ans2);

    return 0;
}
