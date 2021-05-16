#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int value;
    struct node *left;
    struct node *right;
    struct node *parent;
} node;

typedef struct tree
{
    int num;
    struct node *head;
} tree;

// Для вывода нужен прямой обход, а значит нужен стек
typedef struct l_node
{
    node *value;
    struct l_node *next;
    struct l_node *prev;
} l_node;

typedef struct list
{
    struct l_node *head; 
    struct l_node *tail;
} list;

void init_list(list *l)
{
    l -> head = NULL;
    l -> tail = NULL;
}

void init(tree *t){
    t -> head = NULL;
    t -> num = 0;
}

int insert(tree *t, int value)
{
    if(t -> head == NULL)
    {
        t -> head = (node*)malloc(sizeof(node));
        t -> head -> parent = NULL;
        t -> head -> left = NULL;
        t -> head -> right = NULL;
        t -> head -> value = value;
        t -> num++;
        return 0;
    }

    node *tmp = t -> head;
    while(tmp -> value != value)
    {
        if(value > tmp -> value)
        {
            if(tmp -> right != NULL)
            {
                tmp = tmp -> right;
            }
            else
            {
                tmp -> right = (node*)malloc(sizeof(node));
                tmp -> right -> value = value;
                tmp -> right -> parent = tmp;
                tmp -> right -> right = NULL;
                tmp -> right -> left = NULL;
                t -> num++;
                return 0;
            }
        }
        else
        {
            if(tmp -> left != NULL)
            {
                tmp = tmp -> left;
            }
            else
            {
                tmp -> left = (node*)malloc(sizeof(node));
                tmp -> left -> value = value;
                tmp -> left -> parent = tmp;
                tmp -> left -> right = NULL;
                tmp -> left -> left = NULL;
                t -> num++;
                return 0;
            }
        }
    }
    return 1;
}

int push_front(list *l, node *value) 
{
    l_node *tmp = (l_node*)malloc(sizeof(l_node)); 
    tmp -> value = value;
    tmp -> next = l -> head;
    tmp -> prev = NULL;
    if (l -> head)
        l -> head -> prev = tmp;
    l -> head = tmp;
    if (l -> tail == NULL)
        l -> tail = tmp;
    return 0;
}

l_node* pop_first(list *l)
{
    l_node *tmp = l -> head;
    if (tmp == NULL)
        return NULL;
    if (tmp -> next != NULL)
        tmp -> next -> prev = NULL;
    l -> head = tmp -> next;
    return tmp;
}

void pre_order(tree *t)
{
    list *l = NULL = (list*)malloc(sizeof(list));
    init_list(l);
    node *tmp;
    push_front(l, t -> head);
    while(l -> head != NULL)
    {
        l_node* tmp_list = pop_first(l);
        tmp = tmp_list -> value;
        free(tmp_list);
        while(tmp != NULL)
        {
            printf("%d ", tmp -> value);
            if(tmp -> right)
                push_front(l, tmp -> right);
            tmp = tmp -> left;
        }
    }
}


int main()
{
    tree *t = NULL;
    t = (tree*)malloc(sizeof(tree));
    init(t);
    int a;
    for (int i = 0; i < 7; i++)
    {
        scanf("%d",&a);
        insert(t, a);
    }
    
    pre_order(t);
    return 0;
}

