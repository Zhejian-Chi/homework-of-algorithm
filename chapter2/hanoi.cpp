/*
	Hanoi�ݹ�ʵ�֣�
	n=1ʱ��a->b���ɣ�
	n>1ʱ������cΪ��������n-1����С��Բ���չ���a->c�����ݹ�ʵ�֣�
		  ��ʱ�������Բ�̣�����n��Բ�̣�a->b��
		  �������aΪ����������n-1����С��Բ���չ���c->b�����ݹ�ʵ�֣�
*/

#include <iostream>

using namespace std;

unsigned long countTimes = 0;  //count times of moving

void moveTower(int n, char a, char b)
{
	cout << ++countTimes << ". ";
	cout << "Disc_No." << n << ": " << a << "->" << b << endl; //disc number is from top to the bottum by 1 to n;

}

//this function use 'c' tower as a backup to move 'n' discs, which overlap with lagest size in the bottum and smallest size in the top,
// from 'a' tower to 'b' tower
void hanoi_reverse(int n, char a, char b, char c)
{
	if (n == 1)
		moveTower(1, a, b);
	else
	{
		hanoi_reverse(n - 1, a, c, b);
		moveTower(n, a, b);
		hanoi_reverse(n - 1, c, b, a);
	}
}



int main()
{
	int n;
	char a = 'a';
	char b = 'b';
	char c = 'c';
	cin >> n;
	hanoi_reverse(n, a, b, c);

	system("pause");

	return 0;
}