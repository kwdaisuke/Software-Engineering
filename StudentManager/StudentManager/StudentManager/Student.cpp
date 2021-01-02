#include "Student.h"
#include <iostream>

Student::Student(int id, string name, char sex)
{
	this->ID = id;
	this->name = name;
	this->sex = sex;
	this->length_score = 0;
}

void Student::addScore(float score) {
	float* temp = (float*)malloc((this->length_score + 1) * sizeof(float));
	for (size_t i = 0; i < this->length_score; i++)
	{
		temp[i] = this->score[i];
	}
	temp[this->length_score++] = score;
	delete this->score;
	this->score = temp;
}

void Student::removeScore(size_t i) {
	if (i >= this->length_score) {
		return;
	}
	float* temp = (float*)malloc((this->length_score -1) * sizeof(float));
	for (size_t j = 0 , k =0; j < this->length_score; j++)
	{

		if (j == i) {
			temp[k] = this->score[j];
			k++;
		}
	}
	this->length_score--;
	delete this->score;
	this->score = temp;
}

void Student::print() {
	cout << "Stutdent " << this->ID << endl
		<< "Name : " << this->name << endl
		<< "Gender : " << this->sex << endl;
	this->printScores();
}

void Student::printScores() {
	cout << "Scores : " << endl;
	for (size_t i = 0; i < this->length_score; i++)
	{
		cout << "Score at " << i << " : " << this->score[i];
	}
}

float Student::average() {
	float sum = 0;
	for (size_t i = 0; i < this->length_score; i++)
	{
		sum += this->score[i];
	}

	return sum / this->length_score;
}

float Student::maxScore() {
	float max = 0;
	for (size_t i = 0; i < this->length_score; i++)
	{
		max = max < this->score[i] ? this->score[i] : max;
	}

	return max;
}

float Student::minScore() {
	float min =2000;
	for (size_t i = 0; i < this->length_score; i++)
	{
		min= min > this->score[i] ? this->score[i] : min;
	}

	return min;
}