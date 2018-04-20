#include <stdio.h>
/*顺序查找
 * a[0]为哨兵
 */

int array_search(int *a,int n,int key)
{
    int i = n;
    while(a[i]!=key)
        i--;
    return i;
}

int main(void)
{
    int i,n;
    int key;
    int a[20];
    printf("输入数组大小n:");
    scanf("%d",&n);

    printf("请输入%d个数:\n",n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("请输入要查找的值Key:");
    scanf("%d",&key);
    a[0] = key;
    int pos = array_search(a,n,key);
    printf("位于%d\n",pos);
    return 0;

}
