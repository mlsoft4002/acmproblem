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
    以一个字符串作为初始话，指定好起始位置（包括），
    和终止位置（不包括），反正是自己调用，注意长度不
    要超过nodeSize-1，可以根据实际情况调整，我选择的
    是nodeSize的一半
    **/
    void init(char str[],int s,int e){
        nSize = e - s;
        next = NULL;
        for(int i=s; i<e; i++){
            buff[i-s] = str[i];
        }
    }
    //pos 在存储中是 0开头的，不是1
    void insertChar(int pos,char c){
        for(int i=nSize; i>pos; i--){
            buff[i] = buff[i-1];
        }
        buff[pos] = c;
        nSize++;
        if(nSize==nodeSize){ //满了就分割
            Node * a = new Node;
            a->init(buff,nSize/2,nSize);
            nSize = nSize/2; //加半
            a->next = next;
            next = a;
        }
    }
};
struct Block_List{
    Node * head; //链表的头,不放入数据
    void init(char str[]){
        head = new Node;
        head->init();
        Node * pre; //最后一个节点的指针
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
        //找到存放数据的节点
        while(pos>p->nSize && p->next != NULL){
            pos-=p->nSize;
            p = p->next;
        }
        //放在最后的时候可能要调整位置
        if(p->next == NULL && pos>p->nSize){
            pos = p->nSize + 1;
        }
        //放进去
        p->insertChar(pos-1, c);
    }
    char findChar(int pos){
        Node * p = head->next;
        //找到数据存放的节点
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
