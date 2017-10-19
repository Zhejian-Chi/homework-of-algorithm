/*
	Hanoi递归实现：
	n=1时，a->b即可；
	n>1时，利用c为辅助，将n-1个较小的圆盘照规则a->c；（递归实现）
		  此时，将最大圆盘（即第n个圆盘）a->b；
		  最后，利用a为辅助，将将n-1个较小的圆盘照规则c->b；（递归实现）
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