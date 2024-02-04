#include <stdio.h>
#include <stdlib.h>
typedef int EleType;
typedef struct Node
{
    int index;
    EleType data;
    struct Node *next;
} Node;
typedef struct Node *List;
List init_list();                  // 初始化链表,返回表头
List Creat_list_rear(int n);       // 尾插法建立整表,该表的表头下标为0
List Creat_list_front(int n);      // 头插法建立整表
void Check_List(List head, int n); // 遍历链表的下标小于等于n的元素
int main()
{
    int creat_count_rear = 5, creat_count_front = 10;
    int check_rear = 4, check_front = 6;
    List head_rear = Creat_list_rear(creat_count_rear);
    List head_front = Creat_list_front(creat_count_front);
    if (check_front > creat_count_front)
    {
        printf("Error,check_front must be smaller than creat_count_front");
        return 0;
    }
    Check_List(head_rear, check_rear);
    Check_List(head_front, check_front);
    return 0;
}
List init_list()
{
    List head = (List)malloc(sizeof(Node));
    if (head == NULL)
        return NULL;
    return head;
}
List Creat_list_rear(int n)
{
    List head = (List)malloc(sizeof(Node));
    List tail = (List)malloc(sizeof(Node));
    head = tail;
    head->index = 0;
    for (int i = 1; i <= n; i++)
    {
        List p = (List)malloc(sizeof(Node));
        p->index = i;
        tail->next = p;
        tail = p;
    }
    return head;
}
List Creat_list_front(int n)
{
    List head = (List)malloc(sizeof(Node));
    head->next = NULL;
    head->index = 0;
    for (int i = n; i >= 1; i--)
    {
        List p = (List)malloc(sizeof(Node));
        p->index = i;
        p->next = head->next;
        head->next = p;
    }
    return head;
}
void Check_List(List head, int n)
{
    List p = head;
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("This node's index is %d.\n", p->index);
        p = p->next;
    }
}