#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

void reverse(char str[]);
void shrink(char str[]); // удаляет лишние пробелы
bool is_palindrome(char str[]); // Определяет, является ли строка палиндромом  
bool is_int_number(char str[]); //Определяет, является ли строка целым числом
bool is_bin_number(char str[]); //Проверяет, является ли строка двоичным числом      
bool is_hex_number(char str[]); //Проверяет, является ли функция шестнадцатеричным числом
int  bin_to_dec(char str[]);  //Если строка - двоичное число, функция вернет его десятичное значение.   
int dec_to_bin(int decimal); //Функция принимает десятичное число, и возвращает его двоичное значение.
int  to_int_number(char str[]); //Если строка - целое число, функция вернет его числовое значение. 
int  hex_to_dec(char str[]);	//Если строка - Шестнадцатеричное число, функция вернет его десятичное значение
string dec_to_hex(int decimal);  //Функция принимает десятичное число, и возвращает его Шестнадцатеричное значение.
bool is_mac_address(char str[]);//Проверяет, является ли строка MAC-адресом
bool is_ip_address(char str[]);	//Проверяет, является ли строка IP-адресом


int main()
{
	setlocale(LC_ALL, "ru");
	const int s = 50;
	char str[s];
	SetConsoleCP(1251);
	cin.getline(str, s);
	shrink(str);
	SetConsoleCP(866);
	if (is_palindrome(str)) {
		cout << "Введеное слово является полиндромным." << endl;
	}
	else
		cout << "Введеное слово не является полиндромным." << endl;
	if (is_int_number(str) && is_bin_number(str) && is_hex_number(str)) {
		cout << "Эта строка может восприниматься как целое так и бинарное так и шеснадцатеричное число!" << endl;
		cout << "Работать с этой строкой как с целым числом(1)." << endl;
		cout << "Работать с этой строкой как с бинарным числом(2)." << endl;
		cout << "Работать с этой строкой как с шеснадцатеричным числом(3)." << endl;
		int choice; cin >> choice;
		int num, hex;
		switch (choice)
		{
		case 1:
			cout << "int = " << to_int_number(str) << endl;
			break;
		case 2:
			num = bin_to_dec(str);
			cout << "Десятичное значение данного числа - " << num << endl;
			num = dec_to_bin(num);
			cout << "Бинарное значение данного числа - " << num << endl;
			break;
		case 3:
			hex = hex_to_dec(str);
			cout << "Десятичное значение данного числа - " << hex << endl;
			cout << hex << " в шеснадцатеричной системе - " << dec_to_hex(hex) << endl;
		}

	}

	if (is_int_number(str) && !is_bin_number(str)) {
		cout << "Строка является целым числом." << endl;
		cout << "int = " << to_int_number(str) << endl;
	}

	if (is_hex_number(str)) {
		cout << "Введеная строка является шеснадцатеричным числом." << endl;
		int hex = hex_to_dec(str);
		cout << "Десятичное значение данного числа - " << hex << endl;
		cout << hex << " в шеснадцатеричной системе - " << dec_to_hex(hex) << endl;
	}

	if (is_ip_address(str)) {
		cout << "Введеная строка является ip-адресом" << endl;
	}
	else
		cout << "Введеная строка не является ip-адресом" << endl;

	if (is_mac_address(str)) {
		cout << "Введеная строка является MAC-адресом" << endl;
	}
	else
		cout << "Введеная строка не является MAC-адресом" << endl;

	return 0;
}


void reverse(char str[])
{
	int s = strlen(str);
	int temp;
	for (int i = 0, j = s - 1; i < j; i++, j--) {

		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++) {

		if (str[i] == ' ' && str[i] == str[i + 1] || str[0] == ' ') {

			for (int j = i; str[j]; j++) {
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}
bool is_palindrome(char str[])
{
	int k = 0;
	for (int i = 0, j = strlen(str) - 1; str[i]; i++, j--) {

		if (str[i] == str[j]) {
			k++;
		}
          if (k == strlen(str)) {
		      return true;
	      }
	}
	
		return false;
}
bool is_int_number(char str[])
{
	int k = 0;
	for (int i = 0; str[i]; i++) {

		if (str[i] >= '0' && str[i] <= '9') {
			k++;
		}
          if (k == strlen(str)) {
		     return true;
	      }
	}
	
		return false;

}
bool is_bin_number(char str[])
{
	int k = 0;
	for (int i = 0; str[i]; i++) {

		if (str[i] >= '0' && str[i] <= '1') {
			k++;
		}
          if (k == strlen(str)) {
		      return true;
	      }
	}

		return false;
}
bool is_hex_number(char str[])
{
	int k = 0;
	for (int i = 0; str[i]; i++) {

		if (str[i] >= '0' && str[i] <= '9' || str[i] >= 'A' && str[i] <= 'F'
			|| str[i] >= 'a' && str[i] <= 'f') {
			k++;
		}
          if (k == strlen(str)) {
		     return true;
	      }
	}
	
		return false;
}
int  bin_to_dec(char str[])
{
	int sum = 0;
	int k = strlen(str);
	for (int i = 0; str[i]; i++) {

		sum += (str[i] - '0') * pow(2, --k);
	}
	return sum;
}
int  dec_to_bin(int decimal)
{
	int k = 0, i = 0;
	char str[30];
	for (; decimal >= 1; i++) {
		k = decimal % 2;
		str[i] = k + '0';
		decimal /= 2;
	}
	str[i] = '\0';
	reverse(str);
	int n = to_int_number(str);
	return n;
}
int  to_int_number(char str[])
{
	int x, y = 0;
	int s = strlen(str) - 1;
	int sum = pow(10, s);
	for (int i = 0; str[i]; i++) {

		x = sum * (str[i] - '0');
		y += x;
		sum /= 10;
	}
	return y;
}
int  hex_to_dec(char str[])
{
	int f = 0, sum = 0;
	int s = strlen(str);
	for (int i = 0; str[i]; i++) {

		if (str[i] >= '0' && str[i] <= '9') {
			f = str[i] - '0';
		}
		if (str[i] >= 'A' && str[i] <= 'F') {
			f = str[i] - '7';
		}
		if (str[i] >= 'a' && str[i] <= 'f') {
			f = str[i] - 'W';
		}
		sum += f * pow(16, --s);
	}
	return sum;
}
string dec_to_hex(int decimal)
{
	int k = 0, i = 0;
	char str[30];
	for (; decimal >= 1; i++) {
		k = decimal % 16;
		if (k >= 10 && k <= 15) {
			str[i] = k + '7';
		}
		else
			str[i] = k + '0';
		decimal /= 16;
	}

	str[i] = '\0';
	reverse(str);
	string v = str;
	return v;
}
bool is_ip_address(char str[])
{
	int s = strlen(str);
	int k=0,m=0;
	for (int i = 0; str[i]; i++) {

		
		if (str[i] == '.') {
			k++;
		}
		if (str[i] >= '0' && str[i] <= '9') {
			m++;
		}
        if (k == 3 && m == s - 3) {
		     return true;
	    }
    }
	
	return false;


}
bool is_mac_address(char str[]) 
{
	int s = strlen(str);
	int k = 0, m = 0;
	for (int i = 0; str[i]; i++) {

		if (str[i] == ':' || str[i] == '-') {
			k++;
		}
		if (str[i] >= '0' && str[i] <= '9' || str[i] >= 'a' && str[i] <= 'f'
			|| str[i] >= 'A' && str[i] <= 'F') {
			m++;
		}
		if (k == 5 && m == s - 5) {
			return true;
		}
	}

	return false;
}