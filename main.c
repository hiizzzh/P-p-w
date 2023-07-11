#include <stdio.h>
#include <math.h>

int minimum_steps(unsigned long x, unsigned long y);

int main()
{
    unsigned long x, y; // ���������� ������

    printf("Enter the value of x: "); // ϳ������ ��� �����������, �� ����� ������ �������� �
    scanf("%lu", &x); // ���������� � ���������
    while (x < 0 || x > pow(2, 31)) // ��������, �� ���������� �������� � ����� ������
    {
        printf("!!!! Invalid value for x !!!!\n*Value must be greater or equal 0 and less than 2^31*\n");
        printf("Enter the value of x: ");
        scanf("%lu", &x);
    }


    printf("Enter the value of y: "); // ϳ������ ��� �����������, �� ����� ������ �������� Y
    scanf("%lu", &y); // ���������� � ���������
    while (y < 0 || y > pow(2, 31)) // ��������, �� ���������� �������� Y ����� ������
    {
        printf("!!!! Invalid value for y !!!!\n*Value must be greater or equal 0 and less than 2^31*\n");
        printf("Enter the value of y: ");
        scanf("%lu", &y);
    }

    if (y < x) // ���� �������� � ����� �� �������� Y, �� �������� ��������� ������
    {
        printf("Value Y must be greater than value X");
        return -1;
    }

    int steps = minimum_steps(x, y); // ��������� �����, � ��� ���� �������� �������� �������� �������� ����� �� � �� Y

    printf("Minimum steps: %d\n", steps); // ��������� ��������� �� �����

    return 0;
}

int minimum_steps(unsigned long x, unsigned long y) // ��������� �������
{
    // �������� �������, ���� x � y ����������
    if (x == y) {
        return 0;
    }

    // ����������� ��������� �����
    int steps = 0;

    // ���������� ������ �� x � y
    int diff = abs(y - x);

    // ����������� �������� ������� �����
    while (diff > 0) {
        if (diff % 2 == 0) {
            // ���� ������ �����, �������� 2-����
            diff /= 2;
        } else if (diff % 2 == 1 && diff != 1) {
            // ���� ������ ������� (��� 1), �������� 2-����
            diff = (diff + 1) / 2;
        } else {
            // ���� ������ 1, �������� 1-����
            diff--;
        }

        // ��������� ��������� �����
        steps++;
    }

    return steps;
}
