/*��qsort������bsearch��������ֵ��ֵ��������Ͳ���*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int intcmp(const void *v1, const void *v2);
int main(void){
    int arr[MAX], count, key, *ptr;
    //��ʾ�û�����һЩ���� 
    printf("Enter %d integer values;press Enter each.\n",MAX);
    for(count = 0; count < MAX; count++){
        scanf("%d", &arr[count]);
    }
    puts("Press Enter to sort the values.");
    getc(stdin);
    //�������е�Ԫ�ذ���������
    qsort(arr, MAX, sizeof(arr[0]), intcmp);
    //��ʾ�����е�����Ԫ��
    for(count = 0; count < MAX; count++){
        printf("\narr[%d] = %d.", count, arr[count]);
    }
    puts("\nPress Enter to continue.");
    getc(stdin);
    //����Ҫ���ҵ�ֵ
    printf("Enter a value to search for: ");
    scanf("%d", &key);
    //ִ�в���
    ptr = (int *)bsearch(&key, arr, MAX, sizeof(arr[0]), intcmp);
    if(ptr != NULL){
        printf("%d found at arr[%d].", key, (ptr - arr));
    } else {
        printf("%d not found.", key);
    }
    return 0;
}
int intcmp(const void *v1, const void *v2){
    return (*(int *)v1 - *(int *)v2);
}

