#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <cctype>
#include <string.h>

using namespace std;

void reverse(char str[]);
void to_lower(char str[]);
void remove_symbol(char str[], char symbol);
void shrink(char str[]);
bool is_palindrome(char str[]);
bool is_hex_number(char str[]);
bool is_int_number(char str[]);
bool is_bin_number(char str[]);
string  dec_to_bin(int decimal);
int  to_int_number(char str[]);
int  hex_to_dec(char str[]);
string dec_to_hex(int decimal);
bool is_ip_address(char str[]);
bool is_mac_address(char str[]);
int  bin_to_dec(char str[]);

int main()
{
	setlocale(LC_ALL, "ru");
	const int s = 256;
	char str[s];
	cout << "Введите строку" << endl;
	SetConsoleCP(1251);
	cin.getline(str, s);
	SetConsoleCP(866);
	cout << str << (is_int_number(str) ? " " : " НЕ ") << "является целым числом." << endl;
	cout << (is_int_number(str) ? to_int_number(str) : 0) << endl;
	cout << str << (is_palindrome(str) ? "" : " НЕ") << " является полиндромом" << endl;
	cout << str << (is_bin_number(str) ? "" : " НЕ") << " является двоичным числом" << endl;
	cout << (is_bin_number(str) ? bin_to_dec(str) : 0) << endl;
	cout << str << (is_hex_number(str) ? " " : " НЕ ") << "является шеснадцатиричным числом." << endl;
	cout << (is_hex_number(str) ? hex_to_dec(str) : 0) << endl;
	int num; cout << "введите десятичное число: "; cin >> num;
	cout << num << " в двоичной системе - " << dec_to_bin(num) << endl;
	cout << num << " в шеснадцатеричной системе - " << dec_to_hex(num) << endl;

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
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++) {
		str[i] = tolower(str[i]);
	}
}
void remove_symbol(char str[], char symbol) {

	for (int i = 0; str[i]; i++) {

		while (str[i] == symbol) {

			for (int j = i; str[j]; j++) {

				str[j] = str[j + 1];
			}
		}
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
	int length = strlen(str);
	char* buffer = new char[length + 1];
	strcpy(buffer, str);
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	for (int i = 0, j = strlen(buffer) - 1; buffer[i] / 2; i++, j--) {

		if (buffer[i] != buffer[j]) {
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}
bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++) if (!isdigit(str[i])) return false;
	return true;
}
int  to_int_number(char str[])
{
	int num;
	if (is_int_number(str)) return num = atoi(str);
	return 0;
}
int  bin_to_dec(char str[])
{
	int sum = 0;
	int k = strlen(str);
	for (int i = 0; str[i]; i++) {

		if (str[i] != ' ') {
			sum += (str[i] - '0') * pow(2, --k);
		}
	}
	return sum;
}
bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++) {

		if (str[i] != '0' && str[i] != '1' && str[i] != ' ') return false;
		if (str[i] == ' ' && str[i - 1] == ' ' && str[i + 1] == ' ') 	return false;

	}
	return true;
}
string  dec_to_bin(int decimal)
{
	int capacity = 0, x = 0, k = 0;
	int buffer = decimal;
	for (; buffer > 0; capacity++) {
		if (x == 4) {
			capacity++;
		}
		if (x == 8) {
			capacity += 2;
			x = 0;
		}
		buffer /= 2;
		x++;
	}
	const int s = 256;
	char bin[s];
	capacity = s - capacity;
	for (int i = (s - capacity) - 1; decimal; i--) {
		if (k == 4) {
			bin[i--] = ' ';
		}
		if (k == 8) {
			bin[i--] = ' ';
			bin[i--] = ' ';
			k = 0;
		}
		bin[i] = decimal % 2 + '0';
		decimal /= 2;
		k++;
	}
	bin[s - capacity] = '\0';
	string v = bin;
	return v;
}
bool is_hex_number(char str[])
{
	for (int i = 0; str[i]; i++) if (!isxdigit(str[i])) return false;
	return true;
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
	int k = 0, m = 0;
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