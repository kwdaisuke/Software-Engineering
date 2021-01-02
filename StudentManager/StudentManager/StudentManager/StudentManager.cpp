#include "StudentManager.h"

StudentManager::StudentManager() {
	this->studentList = map<int,Student>();
	this->lastID = 1;
}

//function to start process
void StudentManager::start() {
	int choice = 0;
	do {


		cout << "============================================" << endl;
		cout << "                     Menu                   " << endl << endl << endl;
		cout << "============================================" << endl;
		cout << "1. Add student record" << endl;
		cout << "2. Delete student record" << endl;
		cout << "3. Update student record" << endl;
		cout << "4. View all student records" << endl;
		cout << "5. Calculate an average of a selected student’s scores" << endl;
		cout << "6. Show student who gets the max score" << endl;
		cout << "7. Show student who gets the min score" << endl;
		cout << "8. Find student by ID" << endl <<endl;
		cout << "0. Exit" << endl;
		cout << "Choose an action :" << endl;
		cin >> choice;
		if (choice == 1) {
			string name;
			char s;
			system("CLS");
			cout << "============================================" << endl;
			cout << "           Delete Student Record            " << endl << endl << endl;
			cout << "============================================" << endl;
			cout << "Add a Student Record" << endl;
			cout << "Enter Name :" << endl;
			cin >> name;
			cout << "Enter gender (M/F): " << endl;
			cin >> s;
			this->addStudent(name, s);
			cout << "Student record added" << endl;
		}
		else if (choice == 2) {
			int id_student;
			system("CLS");
			cout << "============================================" << endl;
			cout << "           Delete Student Record            " << endl << endl << endl;
			cout << "============================================" << endl;
			this->printStudents();
			cout << "Enter ID :" << endl;
			cin >> id_student;
			this->removeStudent(id_student);
			cout << "Student record deleted" << endl;
		}
		else if (choice == 3) {
			int update_student_id;
			int action = 0;
			system("CLS");
			cout << "============================================" << endl;
			cout << "           Update Student Record            " << endl << endl << endl;
			cout << "============================================" << endl;
			this->printStudents();
			cout << "Enter ID :" << endl;
			cin >> update_student_id;
			cout << "1. Add score" << endl;
			cout << "2. Update name" << endl;
			cout << "3. Update gender" << endl <<endl;
			cout << "0. Cancel" << endl;
			cout << "Choose an action : " << endl;
			cin >> action;
			if (action == 1) {
				int score=0;
				cout << "Enter a score between 0 and 100 :" << endl;
				cin >> score;
				this->studentList.at(update_student_id).addScore(score);
				cout << "Score added." << endl;
			}
			else if (action == 2) {
				string name;
				cout << "Enter the new name :" << endl;
				cin >> name;
				this->studentList.at(update_student_id).setName(name);
				cout << "Name updated." << endl;
			}
			else if (action == 3) {
				char gender;
				cout << "Enter the new gender (M/F) :" << endl;
				cin >> gender;
				this->studentList.at(update_student_id).setSex(gender);
				cout << "Gender updated." << endl;
			}

		}
		else if (choice == 4) {
			system("CLS");
			cout << "============================================" << endl;
			cout << "           View all student records            " << endl << endl << endl;
			cout << "============================================" << endl;
			this->printStudents();
		}
		else if (choice == 5) {
			int selected_student_id;
			system("CLS");
			cout << "=====================================================" << endl;
			cout << " Calculate an average of a selected student’s scores " << endl << endl << endl;
			cout << "=====================================================" << endl;
			this->printStudents();
			cout << "Enter ID :" << endl;
			cin >> selected_student_id;
			Student selected_student = this->getStudentByID(selected_student_id);
			cout << "The average scord for " << selected_student.getName() << "is " << selected_student.average() <<endl;

		}
		else if (choice == 6) {
			system("CLS");
			cout << "=============================================" << endl;
			cout << "     Show student who gets the max score     " << endl << endl << endl;
			cout << "=============================================" << endl;
			Student max = this->maxScore();
			cout << "The student with max score is " << max.getName() << "with a score of " << max.maxScore() << endl;
		}
		else if (choice == 7) {
			system("CLS");
			cout << "=============================================" << endl;
			cout << "     Show student who gets the min score     " << endl << endl << endl;
			cout << "=============================================" << endl;
			Student max = this->maxScore();
			cout << "The student with min score is " << max.getName() << "with a score of " << max.minScore() << endl;
		}
		else if (choice == 8) {
			int selected_student_id;
			system("CLS");
			cout << "============================================" << endl;
			cout << "            Find student by ID              " << endl << endl << endl;
			cout << "============================================" << endl;
			this->printStudents();
			cout << "Enter ID :" << endl;
			cin >> selected_student_id;
			Student selected_student = this->getStudentByID(selected_student_id);
			selected_student.print();
			selected_student.printScores();
		}
		else if (choice == 0) {
			system("CLS");
			cout << "============================================" << endl;
			cout << "          Good Bye. See you soon!           " << endl << endl << endl;
			cout << "============================================" << endl;
		}
		else {
			system("CLS");
			cout << "============================================" << endl;
			cout << "          This action is unknown.           " << endl << endl << endl;
			cout << "============================================" << endl;
		}
		system("pause");
		system("CLS");
	} while (choice != 0);
}
void StudentManager::addStudent(string name, char sex) {
	Student newStudent = Student(this->lastID++, name, sex);
	this->studentList.insert({ newStudent.getID(),newStudent });
}

void StudentManager::removeStudent(int id) {
	this->studentList.erase(id);
}

void StudentManager::printStudents() {
	map<int, Student>::iterator it;

	for (it = this->studentList.begin(); it != this->studentList.end(); it++)
	{
		cout << it->second.getID() << " - " << it->second.getName() << endl;
		
	}
}

Student StudentManager::getStudentByID(int id) {
	return this->studentList.at(id);
}

Student StudentManager::minScore() {
	map<int, Student>::iterator it;
	float minscore = 2000;
	Student minStudent = this->studentList.begin()->second;
	for (it = this->studentList.begin(); it != this->studentList.end(); it++)
	{
		float studentScore=it->second.minScore();
		minStudent = minscore > studentScore ? it->second : minStudent;
		minscore = minscore > studentScore ? studentScore : minscore;
	}
	return minStudent;
}

Student StudentManager::maxScore() {
	map<int, Student>::iterator it;
	float maxScore = 0;
	Student maxStudent = this->studentList.begin()->second;
	for (it = this->studentList.begin(); it != this->studentList.end(); it++)
	{
		float studentScore = it->second.maxScore();
		maxStudent = maxScore < studentScore ? it->second : maxStudent;
		maxScore = maxScore < studentScore ? studentScore : maxScore;
	}
	return maxStudent;
}

StudentManager::~StudentManager() {

}