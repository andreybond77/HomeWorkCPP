#include <iostream>
#include <string>
using namespace std;

#define random(a,b) a+rand()%(b+1-a)

const int countNames = 5;
const string names[] = { "����", "����","����","����", "���" };

class Student {
	static int id;
	int uniqId;
	string name;
	int* marks = nullptr;
	int countMarks = 0;
public:




	Student() {
		name = names[random(0, countNames - 1)];
		uniqId = id++;
	}
	Student(Student& st) : Student() {

		countMarks = st.countMarks;
		marks = new int[countMarks];
		for (int i = 0; i < countMarks; i++) {
			marks[i] = st.marks[i];
		}
	}
/*
	~Student() {
		cout << uniqId << "was deleted";

		if (this->marks != nullptr) {
			delete[] marks;
		}
	}
*/
	void operator = (Student& st) {
		name = st.name;
		countMarks = st.countMarks;
		marks = new int[countMarks];
		for (int i = 0; i < countMarks; i++) {
			marks[i] = st.marks[i];
		}
	}

	void addMark(int mark) {
		int* buf = new int[countMarks + 1];
		for (int i = 0; i < countMarks; i++) {
			buf[i] = marks[i];
		}
		buf[countMarks++] = mark;
		delete[]marks;
		marks = buf;
	}

	void delMark(int index, int mark) {
		if (countMarks == 0) return;
		if (countMarks == 1) {
			countMarks = 0;
			delete[]marks;
			marks = nullptr;
			return;
		}
		int* buf = new int[countMarks - 1];
		for (int i = 0; i < index; i++) {
			buf[i] = marks[i];
		}
		for (int i = index + 1; i < countMarks; i++) {
			buf[i - 1] = marks[i];
		}
		delete[]marks;
		marks = buf;
		countMarks--;
	}

	void changeMark(int index, int mark) {
		if (index >= 0 && index < countMarks) {
			marks[index] = mark;
		}
	}



	void showInfo() {
		cout << uniqId << " : " << name << " : ";
		for (int i = 0; i < countMarks; i++) {
			cout << marks[i] << " ";
		}
		cout << endl;
		
	}

};
int Student::id = 0;

struct GroupName {
	static int num;
	static char alpha;
public:
	static string getUniqGroupName() {
		if (num == 3) return "";
		int numPrev = num;
		char alphaPrev = alpha;

		if (alpha == '�') {
			alpha = '�';
			num += 1;
		}
		else alpha++;

		return to_string(numPrev) + alphaPrev;
	}
};
int GroupName::num = 1;
char GroupName::alpha = '�';

class Group {

	string uniqId;
	Student** students;
	int countStudents;
public:
	Group() {
		this->countStudents = 0;
		uniqId = GroupName::getUniqGroupName();
		if (uniqId == "") cout << "��������� ������ �����";
	}

	int getCountStudents() {
		return countStudents;
	}

	void showInfo() {
		if (uniqId != "") cout << uniqId << " " << endl;
		for (int i = 0; i < countStudents; i++) {
			students[i]->showInfo();
		}
	}
	


	void addStudent(Student& st) {
		if (this->countStudents == 5) {
			cout << "�������� ���������� ������ ���������� ���������";
			return;
		}
		Student** buf = new Student * [countStudents + 1];
		for (int i = 0; i < countStudents; i++) {
			buf[i] = students[i];
		}
		delete[]students;

		buf[countStudents] = new Student(st);

		countStudents++;
		students = buf;
	}

	
	Student** add = new Student * [countStudents + 1];
	

	void delStudent(int index) {
		if (countStudents == 0) {
			return;
		}
		if (this->countStudents == 1) {
			delete[] students[0];
			students = nullptr;
			return;
		}
		Student** buf = new Student * [countStudents - 1];
		for (int i = 0; i < index; i++) {
			buf[i] = students[i];
		}
		for (int i = index + 1; i < countStudents; i++) {
			buf[i - 1] = students[i];
			add[i] = students[index];
		}
	
		delete students[index];
		delete[]students;

		countStudents--;
		students = buf;

	}
	
	void addStudent1(Student& st) {
		if (this->countStudents == 6) {
			cout << "�������� ���������� ������ ���������� ���������";
			return;
		}
		Student** buf = new Student * [countStudents + 1];
		for (int i = 0; i < countStudents; i++) {
			buf[i] = students[i];
		}
		delete[]students;

		buf[countStudents] = new Student(st);

		countStudents++;
		students = buf;
	}


	Student* getStudentByIndex(int index) {
		return students[index];
	}



};

class School
{
private:
	static int id;
	string name;
	int uniqId;
	Student** student;
	int countStudent = 0;
	int getIndexStudentById(int id);
public:
	class School();
	int getId();
	Student* sellStudent(int id);
	void buyStudent(Student student);
	void showInfo();

	/*

	int Student::getIndexStudentById(int id)
	{
		for (int i = 0; i < countStudent; i++) {
			if (student[i]->getId() == id) return i;
		}
		return -1;
	}

	School::Student()
	{
		uniqId = id++;

	}

	Student* School::sellStudent(int id)
	{
		int index = getIndexStudentById(id);
		if (index == -1) return nullptr;
		Student* sellStudent = student[index];
		Student** buf = new Student * [countStudent - 1];
		for (int i = 0; i < index; i++) {
			buf[i] = student[i];
		}
		for (int i = index + 1; i < countStudent; i++) {
			buf[i - 1] = student[i];
		}

		delete[]student;
		student = buf;
		countStudent--;
		return sellStudent;
	}

	void School::buyStudent(Student student)
	{
		Student** buf = new Student * [countStudent + 1];
		for (int i = 0; i < countStudent; i++) {
			buf[i] = student[i];
		}
		buf[countStudent++] = new Student(student);
		delete[]student;
		student = buf;
	}






	void School::showInfo()
	{

		cout << "page: " << ++uniqId << endl;


		for (int i = 0; i < countStudent; i++) {
			student[i]->showInfo();

		}



	}

	
	int School::getId()
	{
		return uniqId;
	}
	int School::id = 0;
	Student* getStudentByIndex(int index) {
		return students[index];
	}
*/
};













int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	
	int const countGroups = 7;
	Group** groups = new Group * [countGroups];
	for (int i = 0; i < 7; i++) {
		groups[i] = new Group();
	}
	for (int i = 0; i < 30; i++) {

		int indexStudentInGroup = random(0, countGroups - 1);
		while (groups[indexStudentInGroup]->getCountStudents() != 5) {
			Student st;
			for (int j = 0; j < 4; j++) {
				st.addMark(random(2, 5));
			}
			groups[indexStudentInGroup]->addStudent(st);
		}




	}
	for (int i = 0; i < countGroups; i++) {
		groups[i]->showInfo();
	}

	groups[0]->delStudent(0);
	cout << "after remove: " << endl;
	for (int i = 0; i < countGroups; i++) {
		//groups[i]->showInfo();
	}

	cout << "test uno student: " << endl;

	Student st;

	groups[3]->showInfo();
	groups[3]->getStudentByIndex(3)->changeMark(0, 12);

	


	
	//Student st;
	groups[3]->showInfo();
	groups[3]->delStudent(3);
	groups[3]->showInfo();
	groups[2]->addStudent1(st);
	groups[2]->showInfo();


}