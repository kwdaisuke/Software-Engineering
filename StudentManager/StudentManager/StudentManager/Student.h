#pragma once
#include <string>
using namespace std;

class Student
{
	private :
		int ID;
		string name;
		char sex;
		float* score;
		size_t length_score;

	public :
		Student(int id,string name,char sex);

		//Getter
		int getID() {
			return this->ID;
		}

		string getName() {
			return this->name;
		}

		char getSex() {
			return this->sex;
		}

		size_t getScore(float* score) {
			score = (float*)malloc(this->length_score * sizeof(float));
			for (size_t i = 0; i < this->length_score; i++)
			{
				score[i] = this->score[i];
			}
			return this->length_score;
		}

		//Setter
		void setID(int id) {
			if (id >= 0) {
				this->ID = id;
			}
		}

		void setName(string name) {
			this->name = name;
		}

		void setSex(char s) {
			if (s == 'm' || s == 'f') {
				this->sex = s;
			}
		}

		void addScore(float score);

		void removeScore(size_t i);

		void print();

		void printScores();

		float average();

		float maxScore();

		float minScore();

};

