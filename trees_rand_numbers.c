#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NODE
{
    int number;
    struct NODE *left;
    struct NODE *right;
};

struct NODE *newn(int data)
{
    struct NODE *newNode = malloc(sizeof(struct NODE));
    newNode->number = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(struct NODE *root, FILE *fp)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        fprintf(fp, "%d->", root->number);
        preorder(root->left, fp);
        preorder(root->right, fp);
    }
}

void inorder(struct NODE *root, FILE *fp)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left, fp);
        fprintf(fp, "%d->", root->number);
        inorder(root->right, fp);
    }
}

void postorder(struct NODE *root, FILE *fp)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->left, fp);
        postorder(root->right, fp);
        fprintf(fp, "%d->", root->number);
    }
}

int main()
{
    FILE *fp1 = fopen("random.txt", "w");
    int i;
    FILE *preFile = fopen("pre.txt", "w");
    FILE *inFile = fopen("in.txt", "w");
    FILE *postFile = fopen("post.txt", "w");
    struct NODE *root = NULL;
    int n;
    int num;

    printf("Enter the number of integers to generate: ");
    scanf("%d", &n);

    time_t t;
    srand((unsigned)time(&t));

    printf("The random numbers generated are:\n");
    for ( i = 0; i < n; i++)
    {
        num = rand() % 100; // Generate a fp1 number between 0 and 99
        fprintf(fp1, "%d\n", num);

        if (i == 0)
        {
            root = newn(num);
        }
        else
        {
            struct NODE *current = root;
            struct NODE *parent = NULL;

            while (current != NULL)
            {
                parent = current;
                if (num < current->number)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }

            if (num < parent->number)
            {
                parent->left = newn(num);
            }
            else
            {
                parent->right = newn(num);
            }
        }
    }



    preorder(root, preFile);
    inorder(root, inFile);
    postorder(root, postFile);

    fclose(preFile);
    fclose(inFile);
    fclose(postFile);
    fclose(fp1);

    return 0;
}
