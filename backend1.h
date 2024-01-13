
#include <iostream>
#include <ctime>
using namespace std;

int random_shape()
{
    return rand() % 5 + 0;
}

void board_generate(int array[][8])
{
    srand(time(NULL));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            array[i][j] = random_shape();
        }
    }
}

void display_backend(int array[][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

bool vertical_three(int array[][8])
{
    bool flag = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i < 6)
            {
                if (array[i][j] == array[i + 1][j] && array[i][j] == array[i + 2][j])
                {
                    int row = i + 2;
                    while (row >= 3)
                    {
                        array[row][j] = array[row - 3][j];
                        row--;
                    }
                    row = 2;
                    while (row >= 0)
                    {
                        array[row--][j] = random_shape();
                    }
                    return true;
                }
            }
        }
    }
    return flag;
}

bool vertical_four(int array[][8], int& score)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i < 5)
            {
                if (array[i][j] == array[i + 1][j] && array[i][j] == array[i + 2][j] && array[i][j] == array[i + 3][j])
                {
                    cout << "Generating random shape: V4!!\n";
                    array[i + 3][j] += 10;
                    while (vertical_three(array))
                    {
                        score += 30;
                    }
                    return true;
                }
            }
        }
    }
    return 0;
}

bool vertical_five(int array[][8])
{
    bool flag = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i < 4)
            {
                if (array[i][j] == array[i + 1][j] && array[i][j] == array[i + 2][j] && array[i][j] == array[i + 3][j] && array[i][j] == array[i + 4][j])
                {
                    // TODO
                    cout << "Generating random shape: V5!!\n";
                    array[i + 4][j] += 20;
                    int row = i + 3;
                    while (row >= 4)
                    {
                        array[row][j] = array[row - 4][j];
                        row--;
                    }
                    row = 3;
                    while (row >= 0)
                    {
                        array[row--][j] = random_shape();
                    }
                    return true;
                }
            }
        }
    }
    return flag;
}

bool horizontal_three(int array[][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j < 6)
            {
                if (array[i][j] == array[i][j + 1] && array[i][j] == array[i][j + 2])
                {
                    int col = j;
                    for (; col <= j + 2; col++)
                    {
                        int row = i;
                        while (row >= 1)
                        {
                            array[row][col] = array[row - 1][col];
                            row--;
                        }
                        while (row >= 0)
                        {
                            array[row][col] = random_shape();
                            row--;
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

bool horizontal_four(int array[][8], int& score)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j < 5)
            {
                if (array[i][j] == array[i][j + 1] && array[i][j] == array[i][j + 2] && array[i][j] == array[i][j + 3])
                {
                    array[i][j] += 10;
                    while (horizontal_three(array))
                        score += 30;
                    return true;
                }
            }
        }
    }
    return false;
}

bool horizontal_five(int array[][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j < 4)
            {
                if (array[i][j] == array[i][j + 1] && array[i][j] == array[i][j + 2] && array[i][j] == array[i][j + 3] && array[i][j] == array[i][j + 4])
                {
                    array[i][j] += 20;
                    int col = j + 1;
                    for (; col <= j + 4; col++)
                    {
                        int row = i;
                        while (row >= 1)
                        {
                            array[row][col] = array[row - 1][col];
                            row--;
                        }
                        while (row >= 0)
                        {
                            array[row][col] = random_shape();
                            row--;
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

void radius_clear_helper(int array[][8], int i, int j)
{
    cout << "Clear radius!" << endl;
    if (i == 0 && j == 0)
    {
        array[i][j] = random_shape();
        array[i][j + 1] = random_shape();
        array[i + 1][j] = random_shape();
        array[i + 1][j + 1] = random_shape();
    }
    else if (i == 7 && j == 0)
    {
        int row = 7;
        while (row >= 2)
        {
            array[row][j] = array[row - 2][j];
            array[row][j + 1] = array[row - 2][j + 1];
            row--;
        }
        while (row >= 0)
        {
            array[row][j] = random_shape();
            array[row][j + 1] = random_shape();
            row--;
        }
    }
    else if (i > 0 && i < 7 && j == 0)
    {
        int row = i + 1;
        while (row >= 3)
        {
            array[row][j] = array[row - 3][j];
            array[row][j + 1] = array[row - 3][j + 1];
            row--;
        }
        while (row >= 0)
        {
            array[row][j] = random_shape();
            array[row][j + 1] = random_shape();
            row--;
        }
    }
    else if (i == 0 && j == 7)
    {
        array[i][j] = random_shape();
        array[i][j - 1] = random_shape();
        array[i + 1][j] = random_shape();
        array[i + 1][j - 1] = random_shape();
    }
    else if (i == 7 && j == 7)
    {
        int row = 7;
        while (row >= 2)
        {
            array[row][j] = array[row - 2][j];
            array[row][j - 1] = array[row - 2][j - 1];
            row--;
        }
        while (row >= 0)
        {
            array[row][j] = random_shape();
            array[row][j - 1] = random_shape();
            row--;
        }
    }
    else if (i > 0 && i < 7 && j == 7)
    {
        int row = i + 1;
        while (row >= 3)
        {
            array[row][j] = array[row - 3][j];
            array[row][j - 1] = array[row - 3][j - 1];
            row--;
        }
        while (row >= 0)
        {
            array[row][j] = random_shape();
            array[row][j - 1] = random_shape();
            row--;
        }
    }
    else if (i == 0 && j > 0 && j < 7)
    {
        array[i][j] = random_shape();
        array[i][j + 1] = random_shape();
        array[i][j - 1] = random_shape();
        array[i + 1][j] = random_shape();
        array[i + 1][j + 1] = random_shape();
        array[i + 1][j - 1] = random_shape();
    }
    else if (i == 7 && j > 0 && j < 7)
    {
        int col = j - 1;
        for (; col <= j + 1; col++)
        {
            int row = 7;
            while (row >= 2)
            {
                array[row][col] = array[row - 2][col];
                row--;
            }
            while (row >= 0)
            {
                array[row][col] = random_shape();
                row--;
            }
        }
    }
    else if (i > 0 && i < 7 && j > 0 && j < 7)
    {
        int col = j - 1;
        for (; col <= j + 1; col++)
        {
            int row = i + 1;
            while (row >= 3)
            {
                array[row][col] = array[row - 3][col];
                row--;
            }
            while (row >= 0)
            {
                array[row][col] = random_shape();
                row--;
            }
        }
    }
}

bool radius_check_vertical(int array[][8], int i, int j)
{
    int value = array[i][j];
    value -= 10;
    if (i < 6)
    {
        if (value == array[i + 1][j] && value == array[i + 2][j])
        {
            return true;
        }
    }
    if (i > 0 && i < 7)
    {
        if (value == array[i + 1][j] && value == array[i - 1][j])
        {
            return true;
        }
    }
    if (i >= 2)
    {
        if (value == array[i - 1][j] && value == array[i - 2][j])
        {
            return true;
        }
    }
    return false;
}

bool radius_check_horizontal(int array[][8], int i, int j)
{
    int value = array[i][j];
    value -= 10;

    if (j < 6)
    {
        if (value == array[i][j + 1] && value == array[i][j + 2])
        {
            return true;
        }
    }
    if (j > 0 && j < 7)
    {
        if (value == array[i][j + 1] && value == array[i][j - 1])
        {
            return true;
        }
    }
    if (j >= 2)
    {
        if (value == array[i][j - 1] && value == array[i][j - 2])
            return true;
    }
    return false;
}
//! PRACTICAL
bool radius_clear_check(int array[][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (array[i][j] == 10 || array[i][j] == 11 || array[i][j] == 12 || array[i][j] == 13 || array[i][j] == 14)
            {
                if (radius_check_vertical(array, i, j))
                {
                    radius_clear_helper(array, i, j);
                    return true;
                }
                if (radius_check_horizontal(array, i, j))
                {
                    radius_clear_helper(array, i, j);
                    return true;
                }
            }
        }
    }
    return false;
}

void cross_clear_helper(int array[][8], int i, int j)
{
    cout << "CLEAR 5!\n";
    int row = i;
    int col = j;
    //! CLEAR WHOLE COLUMN
    row = 7;
    while (row >= 0)
    {
        array[row][j] = random_shape();
        row--;
    }
    //! CLEAR ROW
    {
        for (col = 0; col < 7; col++)
        {
            row = i;
            while (row >= 1)
            {
                array[row][col] = array[row - 1][col];
                row--;
            }
            while (row >= 0)
            {
                array[row][col] = random_shape();
                row--;
            }
        }
    }
}

bool cross_check_vertical(int array[][8], int i, int j)
{
    int value = array[i][j];
    value -= 20;
    if (i < 6)
    {
        if (value == array[i + 1][j] && value == array[i + 2][j])
        {
            return true;
        }
    }
    if (i > 0 && i < 7)
    {
        if (value == array[i + 1][j] && value == array[i - 1][j])
        {
            return true;
        }
    }
    if (i >= 2)
    {
        if (value == array[i - 1][j] && value == array[i - 2][j])
        {
            return true;
        }
    }
    return false;
}

bool cross_check_horizontal(int array[][8], int i, int j)
{
    int value = array[i][j];
    value -= 20;
    if (j < 6)
    {
        if (value == array[i][j + 1] && value == array[i][j + 2])
        {
            return true;
        }
    }
    if (j > 0 && j < 7)
    {
        if (value == array[i][j + 1] && value == array[i][j - 1])
        {
            return true;
        }
    }
    if (j >= 2)
    {
        if (value == array[i][j - 1] && value == array[i][j - 2])
            return true;
    }
    return false;
}
//! PRACTICAL
bool cross_clear(int array[][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (array[i][j] == 20 || array[i][j] == 21 || array[i][j] == 22 || array[i][j] == 23 || array[i][j] == 24)
            {
                if (cross_check_vertical(array, i, j))
                {
                    cross_clear_helper(array, i, j);
                    return true;
                }
                if (cross_check_horizontal(array, i, j))
                {
                    cross_clear_helper(array, i, j);
                    return true;
                }
            }
        }
    }
    return false;
}

