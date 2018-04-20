#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *left;
    struct BiTNode *right;
}BiTNode;


void InOrdering(BiTNode *T)
{
    if(T == NULL)
    {
        return;
    }
    InOrdering(T->left);
    printf("%d ",T->data);
    InOrdering(T->right);
}

//递归查找二叉排序树T中是否有key
//指针f指向T的双亲，初始为NULL
//若查找成功，则指针p指向该数据元素结点，返回1
//否则p指向查找路径上访问的最后一个结点，并返回0
int SearchBST(BiTNode *T,int key,BiTNode *f,BiTNode **p)
{
    if(T == NULL)
    {
        *p = f;
        return 0;
    }

    if(key == T->data)
    {//查找成功，p指向该结点
        *p = T;
        return 1;
    }
    else if(key < T->data)
    {
        return SearchBST(T->left,key,T,p);
    }
    else
        return SearchBST(T->right,key,T,p);

}
void InsertBST(BiTNode **root,int key)
{
    assert(root);
    BiTNode * node;
    BiTNode *p;
    BiTNode *f;
    if(*root == NULL)
    {
        *root = malloc(sizeof(BiTNode));
        (*root)->data = key;
        (*root)->left = (*root)->right = NULL;
    }
    else
    {
        if(!SearchBST(*root,key,NULL,&p))
        {
            node = malloc(sizeof(BiTNode));
            node->data = key;
            node->left = node->right = NULL;

            if(key > p->data)
                p->right = node;
            else if(key < p->data)
                p->left = node;
        }
        else
            return;
    }
}

void DeleteBST(BiTNode *root,int key)
{
    if(root == NULL)
        return;
    BiTNode *p,*s,*q;
    if(SearchBST(root,key,NULL,&p))
    {
        if(p->left == NULL && p->right == NULL)
            free(p);

        else if(p->right == NULL)
        {
            q = p->left;
            p->data = q->data;
            p->left = q->left;
            p->right = q->right;
            free(q);
        }
        else if(p->left == NULL)
        {
            q = p->right;
            p->data = q->data;
            p->right =q->left;
            p->left = q->right;
            free(q);
        }
        else
        {
            q = p; //q指向双亲
            s = p->left;

            while(s->right)
            {
                q = s;
                s = s->right;
            }
            p->data = s->data;
            if(q == p)
            {//p的左孩子没有右孩子
                p->left = s->left;
            }
            else
            {
                q->right = s->left;
            }
            free(s);
        }
    }
}

int main(void)
{
    printf("请输入二叉排序树的结点,以-1结束\n");
    int c;
    int key;
    BiTNode *root = NULL; //再一次忘了初始化!!!!
    scanf("%d",&c);
    while(c != -1)
    {
        InsertBST(&root,c);
        scanf("%d",&c);
    }

    InOrdering(root);

    printf("请输入查找元素:");
    scanf("%d",&key);

    BiTNode *p;
    if(SearchBST(root,key,NULL,&p))
    {
        printf("find it!\n");
    }
    else
        printf("didnot find it\n");

    //二叉排序树的删除
    printf("请输入删除元素:");
    scanf("%d",&key);
    DeleteBST(root,key);

    InOrdering(root);

    return 0;
}
