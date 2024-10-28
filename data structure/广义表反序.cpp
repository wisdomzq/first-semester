#include "stdio.h"  
#include "string.h"  
#include "stdlib.h"  
  
typedef enum { ATOM, LIST } ListTag;  
  
typedef struct node {  
    ListTag  tag;  
    union {  
        char  data;  
        struct node *hp;  
    } ptr;  
    struct node *tp;  
} GLNode;  
//hp 指向当前节点的子表的头节点。
//用法: 当当前节点表示一个列表（tag 为 LIST）时，hp 用于指向这个列表中的第一个元素。可以理解为“头部”或“起始”元素。

//tp 指向当前节点的下一个兄弟节点。
//用法: 当当前节点表示一个列表或原子（tag 为 ATOM）时，tp 用于连接同一层级的其他节点。可以理解为“尾部”或“下一个”元素。
GLNode * reverse( GLNode * );  
  
int count;  
  
void Substring( char *sub, char *s, int pos, int len )  
{  
    s = s + pos;  
    while ( len > 0 )  
    {   *sub = *s;  
        sub++;  
        s++;  
        len--;  
    }  
    *sub = '\0';  
}  
  
void sever( char *str, char *hstr )  
{   int n, i, k;  
    char ch[50];  
    n = strlen(str);  
    i = k = 0;  
    do  
    {   Substring( ch, str, i++, 1 );  
        if ( *ch=='(' )  
            k ++;  
        else if ( *ch==')' )  
            k --;  
    } while ( i<n && ( *ch!=',' || k!=0 ) );  
  
    if ( i<n )  
    {   Substring( hstr, str, 0, i-1 );  
        Substring( str, str, i, n-i );  
    }  
    else  
    {   strcpy( hstr, str );  
        str[0] = '\0';  
    }  
}  /* sever */  
  
int PrintGList( GLNode * T )  
{  
    GLNode *p=T, *q;  
  
    if ( p==NULL )  
        printf( ")" );  
    else  
    {   if ( p->tag==ATOM )  
        {   if ( count > 0 )  
                printf( "," );  
            printf( "%c", p->ptr.data );  
            count ++;  
        }  
        else  
        {   q = p->ptr.hp;  
            if ( q == NULL )  
            {   if ( count > 0 )  
                    printf(",");  
                printf("(");  
            }  
            else if ( q->tag == LIST )  
            {   if ( count > 0 )  
                    printf( "," );  
                printf( "(" );  
                count = 0;  
            }  
            PrintGList( q );  
            PrintGList( p->tp );  
        }  
    }  
    return 1;  
}  
  
void print( GLNode * L )  
{  
    if ( L == NULL )  
        printf( "()" );  
    else  
    {  
        if ( L->tag == LIST )  
            printf( "(" );  
        if ( L->ptr.hp != NULL )  
            PrintGList( L );  
        else  
        {  
            printf( "()" );  
            if ( L->tp == NULL )  
                printf( ")" );  
        }  
    }  
    printf( "\n" );  
}  
  
int CreateGList( GLNode **L,  char *s )  
{  
    GLNode *p, *q;  
    char sub[100],  hsub[100];  
  
    p = *L;  
    if ( strcmp(s, "()" )==0 )  
        *L = NULL;    /* 创建空表 */  
    else  
    {  
        *L = ( GLNode * ) malloc( sizeof( GLNode ) );  
        if ( strlen(s)==1 )  //创建原子节点，data置为对应的字符
        {   (*L)->tag = ATOM;  
            (*L)->ptr.data = s[0];  
        }  
        else  
        {   (*L)->tag = LIST;  //创建表节点，递归创建list
            p = *L;  
            Substring( sub, s, 1, strlen(s)-2 );  // 提取去掉外层括号的子字符串
            do  
            {   sever( sub, hsub );  // 分割子字符串
                CreateGList( &p->ptr.hp, hsub );  // 递归创建子链表
                q = p;  
                if ( strlen(sub) > 0 )  
                {   p = (GLNode *) malloc( sizeof(GLNode) );  
                    p->tag = LIST;  
                    q->tp = p;  // 将当前节点的 tp 指向新节点
                }  
            } while ( strlen(sub)>0 );  
            q->tp = NULL;  
        }   /* else */  
    }  /* else */  
    return 1;  
}  
  
/********** 
这是你要实现的函数。 
***********/  

GLNode *reverse(GLNode *p)
{
     GLNode *FL = p; // 保存原始链表头以便于后续处理
    if (p != NULL && p->tag == LIST) // 确保当前节点非空且为列表类型
    {
        // 递归反转后续节点
        for (p->tp = reverse(p->tp); p->tp != NULL; p = p->tp)
            ;
        
        // 创建一个新的节点用于存储当前列表的头
        p->tp = (GLNode *)malloc(sizeof(GLNode));
        GLNode *q = p->tp; // q指向新创建的节点
        q->tp = NULL; // 新节点的后继指针初始化为NULL
        q->tag = FL->tag; // 设置新节点的类型与原节点一致
        q->ptr.hp = reverse(FL->ptr.hp); // 递归反转当前节点的子列表
        p->tp = q; // 将新节点连接到反转后的链表中
        FL = FL->tp; // 移动到下一个原节点
    }
    // 如果是ATOM就直接返回该值
    else return FL;

    return FL; // 返回反转后的链表头
}



/*******************/  
  
int main( )  
{  
    char list[100];  
    GLNode *L, *G;  
    int d;  
  
    count = 0;  
    scanf("%s", list);  
    CreateGList( &L, list );  
  
/*  print( L );   */  
    G = reverse( L );  
    count = 0;  
    print( G );  
    return 0;  
}  
