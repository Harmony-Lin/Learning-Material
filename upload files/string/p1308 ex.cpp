//p1308 ex

#include <cstdio>

int main () {

    char a[1001];
    int state, ans = 0;

    gets(a);

    if(a[0] == ' ') state = 0;//���ó�ʼֵ
    else state = 1;

    for(int i = 1; a[i]; i ++ ) {//Ҫ��һ��ʼ��������Ϊ���Ѿ���������
        if(a[i] == ' ') {//�ǿո�
            if(state == 1) {//��ǰ״̬��ǰһ��������ĸ��˵���ҵ�һ��������
                ans ++ ;//�𰸼�һ
                state = 0;//ǧ������˸�״̬
            }
        }
        else {//����ĸ
            if(state == 0) {//��ǰ״̬��ǰһ�����ǿո�
                state = 1;//��״̬��Ϊ1
            }
        }
    }

    if(state == 1)//���Ҫ�ж�һ��ǧ��Ҫ����
        ans ++ ;
    printf("%d", ans);

    return 0;
}
