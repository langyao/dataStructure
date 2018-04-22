#include <stdio.h>


void bubble_sort(int *a,int n)
{
    if(a == NULL || n <=0 )
        return;
    int i,j;
    for(i = n-1;i >= 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            if(a[j] > a[i])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
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
   bubble_sort(a,n);

    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");

    return 0;

}
