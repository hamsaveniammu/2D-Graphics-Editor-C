#include <stdio.h>

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

int main()
{
    initializeCanvas();

    drawRectangle(5, 3, 10, 5);
    drawLine(2, 15, 20);
    drawTriangle(30, 5, 5);
    drawCircle(40, 10, 4);

    displayCanvas();

    return 0;
}
