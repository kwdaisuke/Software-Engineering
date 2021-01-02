#pragma once
#include <iostream>
#include <map>
#include "Student.h"
using namespace std;
class StudentManager
{

	private :
		map<int,Student> studentList;
		int lastID;

	public :
		StudentManager();
		void start();
		void addStudent(string name, char sex);
		void removeStudent(int id);
		void printStudents();
		Student getStudentByID(int id);
		Student minScore();
		Student maxScore();
		~StudentManager();

};

