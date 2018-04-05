/*用qsort（）和bsearch（）对数值数值进行排序和查找*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int intcmp(const void *v1, const void *v2);
int main(void){
    int arr[MAX], count, key, *ptr;
    //提示用户输入一些整数 
    printf("Enter %d integer values;press Enter each.\n",MAX);
    for(count = 0; count < MAX; count++){
        scanf("%d", &arr[count]);
    }
    puts("Press Enter to sort the values.");
    getc(stdin);
    //将数组中的元素按升序排列
    qsort(arr, MAX, sizeof(arr[0]), intcmp);
    //显示已排列的数组元素
    for(count = 0; count < MAX; count++){
        printf("\narr[%d] = %d.", count, arr[count]);
    }
    puts("\nPress Enter to continue.");
    getc(stdin);
    //输入要查找的值
    printf("Enter a value to search for: ");
    scanf("%d", &key);
    //执行查找
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

