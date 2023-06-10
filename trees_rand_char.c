#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Creation of the NODE
struct NODE
{
    char number;
    struct NODE *left;
    struct NODE *right;
};

// Function to create a new node
struct NODE *newn(char data)
{
    struct NODE *newNode = malloc(sizeof(struct NODE));
    newNode->number = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for preorder traversal
void preorder(struct NODE *root, FILE *fp)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        fprintf(fp, "%c->", root->number);
        preorder(root->left, fp);
        preorder(root->right, fp);
    }
}

// Function for inorder traversal
void inorder(struct NODE *root, FILE *fp)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left, fp);
        fprintf(fp, "%c->", root->number);
        inorder(root->right, fp);
    }
}

// Function for postorder traversal
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
        fprintf(fp, "%c->", root->number);
    }
}

int main()
{
    FILE *random = fopen("randomn.txt", "w");
    int i;
    struct NODE *root = NULL; // Initialize root to NULL
    int n;
    char a;

    printf("Enter the number of characters to generate: ");
    scanf("%d", &n);

    // Code for random character generation
    time_t t;
    srand((unsigned)time(&t));

    printf("The random characters generated are:\n");
    for ( i = 0; i < n; i++)
    {
        a = 'a' + rand() % 26; // Generate a random lowercase character
        fprintf(random, "%c\n", a);

        if (i == 0)
        {
            root = newn(a); // Create the root node
        }
        else
        {
            struct NODE *current = root;
            struct NODE *parent = NULL;

            while (current != NULL)
            {
                parent = current;
                if (a < current->number)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }

            if (a < parent->number)
            {
                parent->left = newn(a);
            }
            else
            {
                parent->right = newn(a);
            }
        }
    }

    // Open files for writing traversal results
    FILE *preFile = fopen("v1.txt", "w");
    FILE *inFile = fopen("v2.txt", "w");
    FILE *postFile = fopen("v3.txt", "w");

    preorder(root, preFile);
    inorder(root, inFile);
    postorder(root, postFile);

    // Close files
    fclose(preFile);
    fclose(inFile);
    fclose(postFile);
    fclose(random);

    return 0;
}
