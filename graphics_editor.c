#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle(int x, int y, int width, int height)
{
    for(int i = y; i < y + height; i++)
    {
        for(int j = x; j < x + width; j++)
        {
            if(i == y || i == y + height - 1 ||
               j == x || j == x + width - 1)
            {
                canvas[i][j] = '*';
            }
        }
    }
}
void drawLine(int x, int y, int length)
{
    for(int i = 0; i < length; i++)
    {
        canvas[y][x + i] = '*';
    }
}
void drawTriangle(int x, int y, int size)
{
    for(int i = 0; i < size; i++)
    {
        canvas[y + i][x - i] = '*';
        canvas[y + i][x + i] = '*';
    }

    for(int j = x - size + 1; j <= x + size - 1; j++)
    {
        canvas[y + size - 1][j] = '*';
    }
}
void drawCircle(int xc, int yc, int r)
{
    for(int y = 0; y < ROWS; y++)
    {
        for(int x = 0; x < COLS; x++)
        {
            int d = (x - xc)*(x - xc) + (y - yc)*(y - yc);

            if(abs(d - r*r) < r)
            {
                canvas[y][x] = '*';
            }
        }
    }
}
void eraseArea(int x, int y, int width, int height)
{
    for(int i = y; i < y + height; i++)
    {
        for(int j = x; j < x + width; j++)
        {
            canvas[i][j] = '_';
        }
    }
}
void modifyRectangle()
{
    eraseArea(5, 3, 10, 5);
    drawRectangle(20, 8, 10, 5);
}

int main()
{
    int choice;

    initializeCanvas();

    printf("1. Rectangle\n");
    printf("2. Line\n");
    printf("3. Triangle\n");
    printf("4. Circle\n");
    printf("5. Delete Rectangle\n");
    printf("6. Modify Rectangle\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            drawRectangle(5, 3, 10, 5);
            break;

        case 2:
            drawLine(2, 15, 20);
            break;

        case 3:
            drawTriangle(30, 5, 5);
            break;

        case 4:
            drawCircle(40, 10, 4);
            break;

        case 5:
            drawRectangle(5, 3, 10, 5);
            eraseArea(5, 3, 10, 5);
            break;

        case 6:
            drawRectangle(5, 3, 10, 5);
            modifyRectangle();
            break;
        case 7:
            printf("7. Exit\n");
           return 0;
        

        default:
            printf("Invalid Choice\n");
    }

    displayCanvas();

    return 0;
}
