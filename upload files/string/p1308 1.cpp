//p1308   1
#include <cstring>
#include <cctype>
#include <cstdio>

void strlower (char *a) {//��д����������д��ĸת����Сд��ĸ
    for(int i = 0; a[i]; i ++ ) {
        if(isupper(a[i])) a[i] = tolower(a[i]);//isupper���ж��Ƿ��Ǵ�д��ĸ��ϵͳ������tolower�ǽ���ת����Сд��ĸ�ĺ���
    }
}

int main () {

    char destination[1000001], *q, source[11], *p;//destintion��Ҫ�ҵ����£�source��Ҫ�ҵĵ��ʣ�p��q����ָ���࣬�ֱ����ǰ������ʲô�ط��˺����һ���ҵ����ʵ�ָ��
    bool flag = false;//�ж��Ƿ��ҵ���
    int ans = 0, ans1 = -1;//�������״γ��ֵ�λ�ã�ans1�ĳ�ֵ��-1����Ϊ��û�ҵ���ʱ���ֱ����������ˣ�ʡ��

    gets(source);
    gets(destination);//����

    strlower(destination);//ȫ��ת����Сд��ĸ
    strlower(source);

    int len = strlen(source);//���ȣ��ں����ֹԽ��ͼӿ��ٶ�

    p = destination;//�Ƚ�ָ����Ϊȫ��

    for(; q = strstr(p, source); ) {//ѭ����strstr����һ���ַ����������һ���ַ�����Ѱ����û������ַ��������У������״γ��ֵ�ָ����򷵻�NULL����ָ�룩
        if( q != NULL//�ҵ��� 
        && ( q == destination || *(q - 1) == ' ') //��һ�������Ƿ�ֹԽ�磬�ڶ������ж�ǰһ���ǲ��ǿո�
        && ( *(q + len) == '\0' || *(q + len) == ' ' ) ) {//�������Ҳ�ǿո�
            ans ++ ;//�𰸼�һ
            if(flag == false) {//������״��ҵ�
                flag = true;
                ans1 = q - destination;//��һ��λ��
            }
        }
        p = q + len;//ˢ��ָ��
    }

    if(flag == true)//�ҵ���
        printf("%d %d
		" , ans, ans1);//���
    else 
        printf("%d", ans1);//���-1

    return 0;
}
