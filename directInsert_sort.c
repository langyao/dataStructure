#include <stdio.h>


void directInsert_sort(int *a,int n)
{
    if(a == NULL || n< 0)
        return;

    int i,j;

    for(i = 1 ; i < n; i++)
    {
        for(j = i - 1; j >= 0; j--)
        {//从i的位置前一个开始，依次把前一个和后一个进行比较j和j+1，若j > j+1,需要交换，否则即有序
            if(a[j] > a[j+1])
            {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
            else
                break;
        }
    }
}

int main(void)
{
    int i,n;
    int key;
    int a[20];
    printf("输入数组大小n:");
    scanf("%d",&n);

    printf("请输入%d个数:\n",n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
   directInsert_sort(a,n);

    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");

    return 0;

}
