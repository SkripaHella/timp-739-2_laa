#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int val;          // значение, которое хранит узел
    struct node *next;  // ссылка на следующий элемент списка
} node;

typedef struct list {
    struct node *head;  // начало списка
} list;

// инициализация пустого списка
void init(list *l)
{
    l->head = NULL;
    return;
}

// удалить все элементы из списка
void clean(list *l)
{
    struct node* Node1;
    struct node* Node2;
    Node1 = l->head;
    while (Node1->next != NULL)
    {
        Node2 = Node1;
        Node1 = Node1->next;
        free(Node2); // освобождение памяти
    }
    free(Node1);
    init(l);
    return;
}

// проверка на пустоту списка
int is_empty(list *l)
{
    if (l->head == NULL) return 1;
    else return 0;
}

// поиск элемента по значению. вернуть NULL если эжемент не найден
node *find(list *l, int value)
{
    node* Node = l -> head;
    if(l -> head == NULL)
        return NULL;

    while(Node -> val != value)
    {
        Node = Node -> next;
        if(Node == NULL)
            return NULL;
    }

    return Node;
}

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value)
{
    node* tmp2 = l -> head;
    if (tmp2 != NULL)
        while (tmp2 -> next != NULL) tmp2 = tmp2 -> next; // нахождение последнего элемента

    if (is_empty(l) == 0)
    {
        node* tmp = tmp2;
        node* Node = (node*)malloc(sizeof(node));
        tmp -> next = Node;
        Node -> val = value;
        Node -> next = NULL;
    }

    else
    {
        node* Node = (node*)malloc(sizeof(node));
        Node -> val = value;
        Node -> next = NULL;
        l -> head = Node;
    }

    return 0;
}

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value)
{
    node *Node = (node*)malloc(sizeof(node));
    Node -> val = value;
    Node -> next = l -> head;
    l -> head = Node;

    return 0;
}

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node *n, int value)
{
    if(n == NULL)
        return 1;

    node *Node = (node*)malloc(sizeof(node));
    Node -> val = value;
    Node -> next = n -> next;
    n -> next = Node;

    return 0;
}

// удалить первый элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_node(list *l, int value)
{
    node *tmp = l -> head;
    node *Node = NULL;

    if(tmp == NULL)
        return 1;

    while(tmp -> val != value)
    {
        if(tmp -> next == NULL)
            return 1;
        else
        {
            Node = tmp;
            tmp = tmp -> next;
        }
    }

    if(tmp == l -> head)
    {
        tmp = l -> head -> next;
    }
    else
    {
        Node -> next = tmp -> next;
    }
    free(tmp);

    return 0;
}

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list* l)
{
    if (is_empty(l) == 0)
    {
        node* inpt;
        inpt = l->head;
        while (inpt != NULL)
        {
            printf("%d ", inpt -> val);
            inpt = inpt -> next;
        }
    }
    printf("\n");

    return;
}

node *ind_f(list *l, int ind)
{
    if(l -> head == NULL)
        return NULL;

    node *Node = l -> head;
    int inc = 0;

    while(inc != ind)
    {
        Node = Node -> next;

        if(Node == NULL)
            return NULL;

        inc++;
    }

    return Node;
}

int main()
{
    int n, i, x, k1, k2, k3;
    list a; // можно было как указатель и тогда далее использовать вез оперсанда
    node* b;
    init(&a);

    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        scanf("%d", &x);
        push_back(&a, x);
    }
    print(&a);

    scanf("%d %d %d", &k1, &k2, &k3);
    b = find(&a, k1); // поиск
    if (b != NULL)
    {
        k1 = 1;
    }
    else
    {
        k1 = 0;
    }
    b = find(&a, k2);
    if (b != NULL)
    {
        k2 = 1;
    }
    else
    {
        k2 = 0;
    }
    b = find(&a, k3);
    if (b != NULL)
    {
        k3 = 1;
    }
    else
    {
        k3 = 0;
    }
    printf("%d %d %d\n", k1, k2, k3);

    scanf("%d", &x);
    push_back(&a, x);
    print(&a);

    scanf("%d", &x);
    push_front(&a, x);
    print(&a);

    scanf("%d %d", &n, &x);
    node *fn = ind_f(&a, n - 1);
    insert_after(fn, x);
    print(&a);

    scanf("%d", &x);
    remove_node(&a, x);
    print(&a);

    clean(&a);

    return 0;
}

