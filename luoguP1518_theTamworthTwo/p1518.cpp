#include <cstdio>

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    char grid[10][10];
    int xJohn, yJohn, xCow, yCow;
    int direcJohn = 0, direcCow = 0;
    int timer = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", grid[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (grid[i][j] == 'F')
            {
                xJohn = i;
                yJohn = j;
            }
            if (grid[i][j] == 'C')
            {
                xCow = i;
                yCow = j;
            }
        }
    }

    while (1)
    {
        if (grid[xJohn + dx[direcJohn]][yJohn + dy[direcJohn]] == '*' 
            || xJohn + dx[direcJohn] > 9 || xJohn + dx[direcJohn] < 0 
            || yJohn + dy[direcJohn] > 9 || yJohn + dy[direcJohn] < 0)
        {
            direcJohn++;
            if (direcJohn > 3)
                direcJohn %= 4;
        }
        else
        {
            xJohn += dx[direcJohn];
            yJohn += dy[direcJohn];
        }
        if (grid[xCow + dx[direcCow]][yCow + dy[direcCow]] == '*' 
            || xCow + dx[direcCow] > 9 || xCow + dx[direcCow] < 0 
            || yCow + dy[direcCow] > 9 || yCow + dy[direcCow] < 0)
        {
            direcCow++;
            if (direcCow > 3)
                direcCow %= 4;
        }
        else
        {
            xCow += dx[direcCow];
            yCow += dy[direcCow];
        }
        timer++;
        if (xJohn == xCow && yJohn == yCow)
        {
            printf("%d",timer);
            break;
        }
        if (timer > 1919810)
        {
            printf("%d", 0);
            break;
        }
    }
    return 0;
}