#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createcll(int a[], int n)
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = a[0];
    head->left = NULL;
    struct Node *prev = head;
    for (int i = 1; i < n; i++)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = a[i];
        prev->right = temp;
        temp->left = prev;
        temp->right = NULL;
        prev = temp;
    }
    return head;
}
void printcll(struct Node *head)
{
    struct Node *ptr = head;
    printf("Elements:");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->right;
    }
    printf("\n");
}
struct Node *deleteduplicate(struct Node *head, int n)
{
    struct Node *ptr = head;
    int arr[n];
    arr[0] = head->data;
  
    int k=1;
    while (ptr != NULL)
    {
          int flag=1;
        struct Node *prev=ptr->left;
         struct Node *next=ptr->right;
        for (int i = 0; i <k; i++)
        {
            if (ptr->data == arr[i])
            {
                struct Node *temp=ptr;
                prev->right=next;
                next->left=prev;
                free(temp);
                flag=0;
                break;
            }
        }
        if(flag==1){
   arr[k++]=ptr->data;
        }
        ptr=ptr->right;

    }
    return head;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    struct Node *head = createcll(a, n);
    printcll(head);
    deleteduplicate(head,n);
    printcll(head);
}