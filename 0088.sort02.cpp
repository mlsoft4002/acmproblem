/*用qsort（）和bsearch（）对字符串进行排序和查找*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
int comp(const void *s1, const void *s2);
int main(void){
    char *data[MAX], buf[80], *ptr, *key, **key1;
    int count;
    //输入单词或短语
    printf("Enter %d words or phrases,pressing Enter after each.\n",MAX);
    for(count = 0; count < MAX; count++){
        printf("Word %d: ", count + 1);
        gets(buf);
        data[count] = malloc(strlen(buf)+1);
        strcpy(data[count], buf);
    } 
    //排列字符串（实际上是排列指针）
    qsort(data, MAX, sizeof(data[0]), comp);
    //显示已排列的字符串
    for(count = 0; count < MAX; count++){
        printf("\n%d: %s", count + 1, data[count]);
    }
    //提示用户输入待查找的单词
    printf("\n\nEnter a search key: ");
    gets(buf);
    // Perform the search. First, make key1 a pointer
    // to the pointer to the search key.
    key = buf;
    key1 = &key;
    ptr = bsearch(key1, data, MAX, sizeof(data[0]), comp);
    
    if(ptr != NULL){
        printf("%s found.\n", buf);
    } else {
        printf("%s not found.\n", buf);
    }
    return (0);
}
int comp(const void *s1, const void *s2){
    return (strcmp(*(char **)s1, *(char **)s2));
}
