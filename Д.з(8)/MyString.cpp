#include "MyString.h"
MyString::MyString(const char arr[])
{
	size = 0;
	for (int i = 0; arr[i] != '\0'; i++) size++;
	str = new char[size + 1];
	for (int i = 0; i < size + 1; i++) str[i] = arr[i];
}

void MyString::show()
{
	if (size > 0)
		std::cout << str << std::endl;
}

bool MyString::empty()
{
	return !size;
}

void MyString::clear()
{
	delete[] str;
	size = 0;
}

void MyString::append(const char arr[])
{
	int size2 = 0;
	for (int i = 0; arr[i] != '\0'; i++) size2++;
	char* buf = new char[size + size2 + 1];
	for (int i = 0; i < size; i++) {
		buf[i] = str[i];
	}
	for (int i = 0; i <= size2; i++) {
		buf[size + i] = arr[i];
	}
	delete[] str;
	str = buf;
	size += size2;


}

void MyString::append(const MyString& newString)
{
	append(newString.str);
}

void MyString::operator=(const char arr[])
{
	if (size > 0) delete[] str;
	size = 0;
	for (int i = 0; arr[i] != '\0'; i++) size++;
	str = new char[size + 1];
	for (int i = 0; i < size + 1; i++) str[i] = arr[i];
}

int MyString::compare(const char arr[])
{
	for (int i = 0; i <= size; i++) {
		if (str[i] > arr[i]) return 1;
		else if (str[i] < arr[i]) return -1;
	}
	return 0;
}

int MyString::compare(const MyString& newString)
{
	return compare(newString.str);
}

int MyString::stoi(const char arr[])
{
	int num = 0;
	int k = (arr[0] == '-') ? 1 : 0;
	for (int i = 0 + k; arr[i] != '\0'; i++) {
		if (arr[i] >= '0' && arr[i] <= '9') {
			num = num * 10 + (arr[i] - 48);
		}
		else return NULL;
	}
	if (k == 1) num *= -1;
	return num;
}

void MyString::find()
{
	int* find(int* start, int* end, int value) {
		while (start != end) {
			if (*start == value) return start;

			start++;
		}

		return end;
	}
}



void MyString::insert()
{
	int x = s1.find(s2);
	while (x != string::npos) {
		s1.replace(x, size, s3);
		x = s1.find(s2, x + s3.size());
	}
}

void MyString::replace()
{
	const T& old_value, const T& new_value)
	{
		for (; first != last; ++first)
			if (*first == old_value)
				*first = new_value;
}
}


