#include <stdio.h>

#define ROW 11
#define COL 2

void printArray(int a[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        if (a[i][0] != -1)
        {
            printf("[%d][0]: %d ", i, a[i][0]);
            if (a[i][1] != -1)
            {
                printf("[%d][1]: %d", i, a[i][1]);
            }
            printf("\n");
        }
    }
}

void insertElement(int a[ROW][COL])
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    int mod = n % 11;
    int row = mod;

    while (a[row][0] != -1 && a[row][1] != -1)
    {
        row = (row + 1) % ROW;
        if (row == mod)
        {
            printf("Table is full!\n");
            return;
        }
    }

    if (a[row][0] == -1)
        a[row][0] = n;
    else
        a[row][1] = n;

    printf("Inserted %d at position [%d][%d]\n", n, row, (a[row][1] == -1) ? 0 : 1);
}

int main()
{
    int a[ROW][COL];

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            a[i][j] = -1;
        }
    }

    int choice;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Enter a number\n");
        printf("2. Print the hash table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertElement(a);
            break;
        case 2:
            printf("\nHash Table:\n");
            printArray(a);
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

 return 0;
}