// ���� ����
#include <conio.h>
#include <stdio.h> 
int main(void)
{
    int num[3];
    int i, j, c = 1;
    printf("3���� ���ڸ� �Է��ϼ���\n���� : 10 3 9 \nENTER : ");
    scanf("%d %d %d", &num[0], &num[1], &num[2]);
    printf("�迭���� �Է� :%3d %3d %3d\n", num[0], num[1], num[2]);
    
    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            if (num[j] < num[i])
            {
                int temp;
                temp = num[j];
                num[j] = num[i];
                num[i] = temp;
            }
        }
    }
    
    printf("�������� ���� :");
    for (i = 0; i < 3; i++)
        printf("%3d ", num[i]);
    printf("\n");
    
    printf("�������� ���� :");
    for (i = 3; i > 0; i--)
        printf("%3d ", num[i - 1]);
}