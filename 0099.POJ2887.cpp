#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int nodeSize=2000;
struct Node{
    int nSize;
    Node * next;
    char buff[nodeSize];
    void init(){
        nSize = 0;
        next = NULL;
    }
    /**
    ��һ���ַ�����Ϊ��ʼ����ָ������ʼλ�ã���������
    ����ֹλ�ã������������������Լ����ã�ע�ⳤ�Ȳ�
    Ҫ����nodeSize-1�����Ը���ʵ�������������ѡ���
    ��nodeSize��һ��
    **/
    void init(char str[],int s,int e){
        nSize = e - s;
        next = NULL;
        for(int i=s; i<e; i++){
            buff[i-s] = str[i];
        }
    }
    //pos �ڴ洢���� 0��ͷ�ģ�����1
    void insertChar(int pos,char c){
        for(int i=nSize; i>pos; i--){
            buff[i] = buff[i-1];
        }
        buff[pos] = c;
        nSize++;
        if(nSize==nodeSize){ //���˾ͷָ�
            Node * a = new Node;
            a->init(buff,nSize/2,nSize);
            nSize = nSize/2; //�Ӱ�
            a->next = next;
            next = a;
        }
    }
};
struct Block_List{
    Node * head; //�����ͷ,����������
    void init(char str[]){
        head = new Node;
        head->init();
        Node * pre; //���һ���ڵ��ָ��
        pre = head;
        int mlen = strlen(str), e;
        for(int i=0; i<mlen; i=e){
            e = i + nodeSize/2;
            if(e>mlen) e = mlen;
            Node * nd = new Node;
            nd->init(str,i,e);
            pre->next = nd;
            pre = pre->next;
        }
    }
    void insertChar(int pos,char c){
        Node * p = head;
        //�ҵ�������ݵĽڵ�
        while(pos>p->nSize && p->next != NULL){
            pos-=p->nSize;
            p = p->next;
        }
        //��������ʱ�����Ҫ����λ��
        if(p->next == NULL && pos>p->nSize){
            pos = p->nSize + 1;
        }
        //�Ž�ȥ
        p->insertChar(pos-1, c);
    }
    char findChar(int pos){
        Node * p = head->next;
        //�ҵ����ݴ�ŵĽڵ�
        while(pos > p->nSize){
            pos -= p->nSize;
            p = p->next;
        }
        return p->buff[pos-1];
    }
}block_List;
char str[1000100];
int main(){
    scanf("%s",str);
    block_List.init(str);
    int n;
    scanf("%d",&n);
    char sc[3], c[3];
    int pos;
    while(n--){
        scanf("%s",sc);
        if(sc[0]=='Q'){
            scanf("%d",&pos);
            char f = block_List.findChar(pos);
            printf("%c\n",f);
        }else if(sc[0]=='I'){
            scanf("%s%d",c,&pos);
            block_List.insertChar(pos,c[0]);
        }
    }
    return 0;
}
