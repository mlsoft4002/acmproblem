#include<stdio.h>
#include<string.h>

#define MAX 1000    // ���������λ�� 

 
/*
  �����ӷ� 
  ������ 
  num1Ϊ��һ�����������ַ����鱣��
  num2Ϊ�ڶ�������
  sum���鱣����ӵĽ��  ����num1+num2=sum
  ����ֵ����������sum����Ч���ȣ�����������λ�� 
 */
int Addition(char num1[], char num2[], int sum[])
{
    int i, j, len;
    int n2[MAX] = {0};
    int len1 = strlen (num1); // ��������num1�ĳ��ȣ���������λ�� 
    int len2 = strlen (num2); // ��������num2�ĳ��ȣ���������λ�� 

    len = len1>len2 ? len1 : len2; // ��ȡ�ϴ��λ��
    //��num1�ַ�����������ַ�ת��Ϊ�������֣������򱣴�����������sum�У�����λ��ǰ����λ�ں�
    for (i = len1-1, j = 0; i >= 0; i--, j++) 
        sum[j] = num1[i] - '0';
    // ת���ڶ����� 
    for (i = len2-1, j = 0; i >= 0; i--, j++)
        n2[j] = num2[i] - '0';
    // ������������� 
    for (i = 0; i <= len; i++)
    {
        sum[i] += n2[i];  // �������ӵ�λ��ʼ��� 
        if (sum[i] > 9)   // �ж��Ƿ��н�λ 
        {   // ��λ 
            sum[i] -= 10;
            sum[i+1]++;
        }
    }
    if(sum[len] != 0)  // �ж����λ�Ƿ��н�λ 
        len++;
    return len;   // ���غ͵�λ�� 
}
/*
  �������� 
  ������ 
  num1Ϊ�����������ַ����鱣��
  num2Ϊ���� 
  sum���鱣������Ľ��   ����num1-num2=sum
  ����ֵ����������sum����Ч���ȣ�����������λ�� 
 */
int Subtraction(char num1[], char num2[], int sum[])
{
    int i, j, len, blag;
    char *temp;
    int n2[MAX] = {0};
    int len1 = strlen(num1); // ��������num1�ĳ��ȣ���������λ�� 
    int len2 = strlen(num2); // ��������num2�ĳ��ȣ���������λ��
    
    // �ڽ��м���֮ǰҪ����һЩԤ���� 
    blag = 0; // Ϊ0��ʾ�������������Ϊ1��ʾ����Ǹ����� 
    if(len1 < len2) // ���������λ��С�ڼ���
    {
        blag = 1; // ��ǽ��Ϊ����
        // ���������������ڼ��� 
        temp = num1;
        num1 = num2;
        num2 = temp;
        len = len1;
        len1 = len2;
        len2 = len;
    }
    else if(len1 ==len2) // �����������λ�����ڼ�����λ��
    {  
        // �ж��ĸ����� 
        for(i = 0; i < len1; i++)
        {
            if(num1[i] == num2[i])
                continue;
            if(num1[i] > num2[i])
            {
                blag = 0; // ��ǽ��Ϊ���� 
                break;
            } 
            else
            {
                blag = 1; // ��ǽ��Ϊ���� 
                // ���������������ڼ��� 
                temp = num1;
                num1 = num2;
                num2 = temp;
                break;
            } 
        } 
    }
    len = len1>len2 ? len1 : len2; // ��ȡ�ϴ��λ��
    //��num1�ַ����������ת��Ϊ�����������򱣴�����������sum�У�����λ��ǰ����λ�ں�
    for (i = len1-1, j = 0; i >= 0; i--, j++) 
        sum[j] = num1[i] - '0';
    // ת���ڶ����� 
    for (i = len2-1, j = 0; i >= 0; i--, j++)
        n2[j] = num2[i] - '0';
    // ������������� 
    for (i = 0; i <= len; i++)
    {
        sum[i] = sum[i] - n2[i]; // �������ӵ�λ��ʼ��� 
        if (sum[i] < 0)   // �ж��Ƿ��н�λ 
        {    // ��λ 
            sum[i] += 10;
            sum[i+1]--;
        }
    }
    // ���������� 
    for (i = len1-1; i>=0 && sum[i] == 0; i--)
        ;
    len = i+1;
    if(blag==1)
    {
        sum[len] = -1;  // �ڸ�λ���һ��-1��ʾ���� 
        len++;
    }
    return len;   // ���ؽ����λ�� 
}
/*
  �����˷� 
  ������ 
  num1Ϊ��һ�����������ַ����鱣��
  num2Ϊ�ڶ�������
  sum���鱣����˵Ľ��  ����num1*num2=sum
  ����ֵ����������sum����Ч���ȣ�����������λ�� 
 */
int Multiplication(char num1[],char num2[], int sum[])
{
    int i, j, len, len1, len2;
    int a[MAX+10] = {0};
    int b[MAX+10] = {0};
    int c[MAX*2+10] = {0};
    
    len1 = strlen(num1);
    for(j = 0, i = len1-1; i >= 0; i--) //�������ַ�ת��Ϊ������ 
        a[j++] = num1[i]-'0';
    len2 = strlen(num2);
    for(j = 0, i = len2-1; i >= 0; i--)
        b[j++] = num2[i]-'0';
    
    for(i = 0; i < len2; i++)//�õڶ��������Ե�һ����,ÿ��һλ 
    {
        for(j = 0; j < len1; j++)
        {
            c[i+j] += b[i] * a[j]; //�ȳ�����,����ͳһ��λ
        }
    }
    
    for(i=0; i<MAX*2; i++) //ѭ��ͳһ�����λ����
    {
        if(c[i]>=10)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    }

    for(i = MAX*2; c[i]==0 && i>=0; i--); //������λ��0
    len = i+1; // ��¼����ĳ��� 
    for(; i>=0; i--)
        sum[i]=c[i];
    return len; 
}
/*
  ����SubStract���ܣ�
  �ó���Ϊlen1�Ĵ�����p1��ȥ����Ϊlen2�Ĵ�����p2
  �������p1�У�����ֵ�������ĳ���
  ������������-1 �� ���ù�������0
*/ 
int SubStract(int *p1, int len1, int *p2, int len2)
{
    int i;
    if(len1 < len2)
        return -1;
    if(len1 == len2 )
    {                        // �ж�p1 > p2
        for(i = len1-1; i >= 0; i--)
        {
            if(p1[i] > p2[i])   // ������������������������
                break;
            else if(p1[i] < p2[i]) // ���򷵻�-1
                return -1;
        }
    }
    for(i = 0; i <= len1-1; i++)  // �ӵ�λ��ʼ������
    {
        p1[i] -= p2[i];         // ��� 
        if(p1[i] < 0)           // ���Ƿ���Ҫ��λ
        {   // ��λ 
            p1[i] += 10;
            p1[i+1]--;
        }
    }
    for(i = len1-1; i >= 0; i--)  // ���ҽ�������λ
    {
        if( p1[i] )             //���λ��һ����Ϊ0
            return (i+1);       //�õ�λ��������
    } 
    return 0;                   //������ȵ�ʱ�򷵻�0
}


/*
  ��������---���������С���� 
  num1 ������
  num2 ���� 
  sum  �̣���ż���Ľ��������num1/num2=sum
  ��������sum����Ч���ȣ����̵�λ�� 
*/ 
int Division(char num1[], char num2[], char sum[])
{
    int k, i, j;
    int len1, len2, len=0;     //����λ��
    int dValue;                //���������λ��
    int nTemp;                 //Subtract��������ֵ
    int num_a[MAX] = {0};      //������
    int num_b[MAX] = {0};      //����
    int num_c[MAX] = {0};      //�� 

    len1 = strlen(num1);       //��ô�����λ��
    len2 = strlen(num2);
    
    //�������ַ�ת�������������ҷ�ת���������������� 
    for( j = 0, i = len1-1; i >= 0; j++, i-- )
        num_a[j] = num1[i] - '0';
    for( j = 0, i = len2-1; i >= 0; j++, i-- )
        num_b[j] = num2[i] - '0';

    if( len1 < len2 )          //���������С�ڳ�����ֱ�ӷ���-1����ʾ���Ϊ0
    {
        return -1;
    }
    dValue = len1 - len2;      //���λ��
    for (i = len1-1; i >= 0; i--)    //����������ʹ�ó����ͱ�����λ�����
    {
        if (i >= dValue)
            num_b[i] = num_b[i-dValue];
        else                         //��λ��0
            num_b[i] = 0;
    }
    len2 = len1;
    for(j = 0; j <= dValue; j++ )    //�ظ����ã�ͬʱ��¼���ɹ��Ĵ�������Ϊ��
    {
        while((nTemp = SubStract(num_a, len1, num_b+j, len2-j)) >= 0)
        {
            len1 = nTemp;            //�������
            num_c[dValue-j]++;       //ÿ�ɹ���һ�Σ����̵���Ӧλ��1
        }
    }
    // �����̵�λ���������̷���sum�ַ������� 
    for(i = MAX-1; num_c[i] == 0 && i >= 0; i-- );  //������λ0����ȡ�̵�λ�� 
    if(i >= 0)
        len = i + 1; // ����λ�� 
    for(j = 0; i >= 0; i--, j++)     // ��������Ƶ�sum������ 
        sum[j] = num_c[i] + '0';
    sum[j] = '\0';   // sum�ַ������β��0 
    return len;      // �����̵�λ�� 
} 
int main()
{
    int i, len;
    int sum[MAX] = {0}; // ��ż���Ľ������λ��ǰ����λ�ں󣬼�sum[0]�ǵ�λ 
    char num1[] = "1234567891234567891234"; // ��һ������ 
    char num2[] = "2345678912345678913345"; // �ڶ������� 
    len = Addition(num1, num2, sum);    // ������� 
    printf("%s\n  +\n%s\n  =\n", num1, num2);
    // ���������ͽ��
    for (i = len-1; i >= 0; i--)
        printf("%d", sum[i]);
    printf("\n"); 

	char num1[] = "987654321987654321"; // ��һ������ 
    char num2[] = "123456789123456789"; // �ڶ������� 
    len = Subtraction(num1, num2, sum);    // ������� 
    // ������
    printf("%s\n  -\n%s\n  =\n", num1, num2);
    if(sum[i=len-1] < 0) // ���ݸ�λ�Ƿ���-1�ж��Ƿ��Ǹ���
    {
        printf("-"); // �������
        i--;
    }
    for (; i >= 0; i--)
        printf("%d", sum[i]);
    printf("\n"); 

	char num1[] = "123456789123456789"; // ��һ������ 
    char num2[] = "123456789123456789"; // �ڶ������� 
    len = Multiplication(num1, num2, sum);
    // ������
    printf("%s\n  *\n%s\n  =\n", num1, num2);
    for(i = len-1; i>=0; i--)
        printf("%d", sum[i]); 
    printf("\n"); 

	char num1[MAX] = "1234567899876543210";   // ��һ������
    char num2[MAX] = "20160415123025";              // �ڶ�������
    char sum[MAX] = {0};    // ������ 

    //scanf("%s", num1);      //���ַ�����ʽ�������
    //scanf("%s", num2);
    
    len = Division(num1, num2, sum); 
    
    //������
    printf("%s\n  ��\n%s\n  =\n", num1, num2);
    if( len>=0 )
    {
        for(i = 0; i < len; i++ )
            printf("%c", sum[i]);
    }
    else
    {
        printf("0");
    }
    printf("\n");
    return 0;
}