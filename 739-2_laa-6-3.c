#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
} node;

typedef struct tree
{
    struct node* root;
    int count;
} tree;

void init(tree* t)
{
    struct tree* tr_new = malloc(sizeof tr_new);
    tr_new -> root = NULL;
    tr_new -> count = 0;
    t = tr_new;
}

int find(tree* t, int value, node* n)
{
    struct node* n2;
    n2 = t -> root;
    if (t -> root == NULL) return 1;
    while (1)
    {
        if (n2 == NULL) return 1;
        
        else if (n2 -> data == value)
        {
            n -> data = n2 -> data;
            n -> left = n2 -> left;
            n -> right = n2 -> right;
            n -> parent = n2 -> parent;
            return 0;
        }
        else if (value > n2 -> data) n2 = n2 -> right;
        else n2 = n2 -> left;
    }
}

int insert(tree* t, int value)
{
    struct node* n, ** nn, * last_n = NULL;
    struct node* e_n = malloc(sizeof* e_n);
    int err = find(t, value, e_n);
    if (err == 0) 
        return 1;
    nn = &t -> root;
    n = t -> root;
    
    while (1)
    {
        if (n == NULL)
        {
            n = *nn = malloc(sizeof *n);
            if (n != NULL)
            {
                n -> data = value;
                n -> left = NULL;
                n -> right = NULL;
                n -> parent = last_n;
                t -> count++;
                return 0;
            }
            else return 2;
        }
        
        last_n = n;
        if (value > n -> data)
        {
            nn = &n -> right;
            n = n -> right;
        }
        else
        {
            nn = &n -> left;
            n = n -> left;
        }
    }
}

void T_print(struct node* n, int flag)
{
    if (n -> left != NULL) 
        T_print(n -> left, flag + 1);
        
    if (n -> right != NULL) 
        T_print(n -> right, flag + 1);
        
    printf("%d", n -> data);
    if (flag > 0) 
        printf(" ");
}

int main()
{
    struct tree* t = malloc(sizeof t);
    init(t);
    int a;
    for (int i = 0; i < 12; i++)
    {
        scanf("%d", &a);
        insert(t, a);
    }
    T_print(t -> root, 0);
    printf("\n");
    return 0;
}

