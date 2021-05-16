#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list
{
    struct node *head;
    struct node *tail;
} list ;

typedef struct node
{
    int val;
    struct node *next;
    struct node *prev;
} node;

void init(struct list* l)
{
    l -> head = NULL;
    l -> tail = NULL;
}

void clean(list* l)
{
    node* inter1 = l -> head;
    node* inter2;
    if (inter1 == NULL) return;
    
    while (inter1 -> next != NULL)
    {
        inter2 = inter1;
        inter1 = inter1 -> next;
        free(inter2);
    }
    free(inter1);
    init(l); // помечаем, что первый и последний элементы - нулевые (для справки)
}

bool is_empty(list *l)
{
    return (l->head == NULL);
}

node *find(list *l, int value) 
{
    node *Node = l -> head;
    while (Node != NULL && Node->val != value)
    {
        Node = Node -> next;
    }
    
    return Node;
}

int push_back(list *l, int value)
{
    node *Node = l -> tail;
    l -> tail = malloc(sizeof(node));
    if (Node == NULL)
    {
        l -> head = l -> tail;
        l -> tail -> next = NULL;
        l -> tail -> prev = NULL;
    }
    else
    {
        Node -> next = l -> tail;
        l -> tail -> prev = Node;
    }
    l -> tail -> val = value;
    
    return 0;
}

int push_front(list *l, int value)
{
    node *Node = l -> head;
    l -> head = malloc(sizeof(node));
    if (Node == NULL)
    {
        l -> tail = l -> head;
        l -> head -> prev = NULL;
        l -> head -> next = NULL;
    }
    else
    {
        Node -> prev = l -> head;
        l -> head -> next = Node;
    }
    l -> head -> val = value;
    
    return 0;
}

int insert_after(list *l, node *n, int value)
{
    node *Node = malloc(sizeof(node));
    Node -> val = value;
    Node -> next = n -> next;
    Node -> prev = n;
    n -> next = Node;
    if (Node -> next == NULL)
    {
        l -> tail = Node;
    } 
    else
    {
        Node -> next -> prev = Node;
    }
    
    return 0;
}

int insert_before(list *l, node *n, int value)
{
    node *Node = malloc(sizeof(node));
    Node -> val = value;
    Node -> prev = n -> prev;
    Node -> next = n;
    n -> prev = Node;
    if (Node -> prev == NULL)
    {
        l -> head = Node;
    } 
    else
    {
        Node -> prev -> next = Node;
    }
    
    return 0;
}

int remove_first(list *l, int value)
{
    if (l -> head == NULL)
        return 1;
        
    node *Node = find(l, value);
    if (Node == NULL)
        return 1;
        
    if (l -> head == Node)
    {
        l -> head = l -> head -> next;
        l -> head -> prev = NULL;
    } 
    else if (l -> tail == Node)
    {
        l -> tail = l -> tail -> prev;
        l -> tail -> next = NULL;
    } 
    else
    {
        node *tmp = Node -> prev;
        tmp -> next = Node -> next;
        Node -> next -> prev = tmp;
    }
    
    free(Node);
    
    return 0;
}

int remove_last(list *l, int value)
{
    if (l -> tail == NULL)
        return 1;
        
    node *Node = find(l, value); //
    if (Node == NULL)
        return 1;
        
    if (l -> tail == Node)
    {
        l -> tail = l -> tail -> prev;
        l -> tail -> next = NULL;
    } 
    else if (l -> head == Node)
    {
        l -> head = l -> head -> next;
        l -> head -> prev = NULL;
    } 
    else
    {
        node *tmp = Node -> next;
        tmp -> prev = Node -> prev;
        Node -> prev -> next = tmp;
    }
    
    free(Node);
    
    return 0;
}

void print(list *l)
{
    node *Node = l -> head;
    while (Node != NULL)
    {
        printf("%d ", Node -> val);
        Node = Node -> next;
    }
    printf("\n");
}

void print_invers(list *l)
{
    node *Node = l -> tail;
    while (Node != NULL)
    {
        printf("%d ", Node -> val);
        Node = Node -> prev;
    }
    printf("\n");
}

int main() 
{
    int n; 
    scanf("%d", &n);
    list *l = NULL; 
    l = malloc(sizeof(list));
    init(l);
    
    int i, a;
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a);
        push_back(l, a);
    }
    print(l);
    
    int k1, k2, k3, b;
    scanf("%d %d %d", &k1, &k2, &k3);
    b = find(l, k1);
    if (b != NULL) k1 = 1; else k1 = 0;
    b = find(l, k2);
    if (b != NULL) k2 = 1; else k2 = 0;
    b = find(l, k3);
    if (b != NULL) k3 = 1; else k3 = 0;
    printf("%d %d %d\n", k1, k2, k3);
    
    int m; 
    scanf("%d", &m);
    push_back(l, m);
    print_invers(l);
    
    int t;
    scanf("%d", &t);
    push_front(l, t);
    print(l);
    
    int j, x; 
    scanf("%d %d", &j, &x);
    node *Node = l -> head;
    for (i = 1; i < j; i++) Node = Node -> next;
    insert_after(l, Node, x);
    print_invers(l);
    
    int u, y;
    scanf("%d %d", &u, &y);
    Node = l->head;
    for (i = 1; i < u; i++) Node = Node -> next;
    insert_before(l, Node, y);
    print(l);
    
    int z; 
    scanf("%d", &z);
    remove_first(l, z);
    print_invers(l);
    
    int r;
    scanf("%d", &r);
    remove_last(l, r);
    print(l);
    
    clean(l);
    
    return 0;
}
