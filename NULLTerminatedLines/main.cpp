#include <iostream>
#include <Windows.h>
using namespace std;


int Stringlength(char str[]);
void to_upper(char str[]);// ��������� ������ � ������� �������
void to_lower(char str[]); // ��������� ������ � ������ �������
void capitalize(char str[]); // ������ ����� ������� ����� � ����������� ������ ���������

//#define STRING_DECLARATION

int main()
{
	setlocale(LC_ALL, "ru");
#ifdef STRING_DECLARATION
	// ASCII - ������ � ����� '\0'
	'H'; // ���������� ��������� ���� char
	//"hello" - ��� �������� ���������
	//char str[] = { 'H','e','l','l','o','\0' };
	/*for (int i = 0; i < sizeof(str); i++) {

		cout << str[i];
	}*/
	char str[] = "Hello";
	//str[1] = 'E';
	cout << str << endl;
	cout << sizeof("hello") << endl;
	cout << sizeof(double) << endl;

#endif // 
	cout << 'a' - 'A' << endl;
	const int n = 20;
	char str[n] = {};
	cout << "������� ������: ";
	SetConsoleCP(1251);
	cin.getline(str, n);//CP1251
	SetConsoleCP(866);
	cout << str << endl;//CP866
	cout << Stringlength(str) << endl;
	to_upper(str);
	capitalize(str);
	cout << str << endl;
	return 0;
}


int Stringlength(char str[]) {
	int i = 0;
	while (str[i])
	{
		str[i++];
	}
	return i;
}
void to_upper(char str[]) {

	for (int i = 0; str[i]; i++) {

		if (str[i] >= 'a' && str[i] <= 'z' ||
			str[i] >= '�' && str[i] <= '�')
			str[i] -= ' ';
	}
}

void to_lower(char str[]) {

	for (int i = 0; str[i]; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z' ||
			str[i] >= '�' && str[i] <= '�') {
			str[i] += 32;
		}
	}
}
void capitalize(char str[])
{
	to_lower(str);
	if (str[0] >= 'a' && str[0] <= 'z' ||
		str[0] >= '�' && str[0] <= '�') {
		str[0] -= 32;
	}
	for (int i = 1; str[i]; i++) {
		if (str[i - 1] == ' ') {
			if (str[i] >= 'a' && str[i] <= 'z' ||
				str[i] >= '�' && str[i] <= '�') {
				str[i] -= 32;
			}
		}
	}
}
