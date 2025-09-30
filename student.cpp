#include "student.h"

#include <iostream>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final) : midterm(midterm), final(final)
/* TODO: Initializer list 사용해 초기화 해보기 */
{}

float StudentRecord::getTotal() const {
    /* TODO */
    return getMidterm() + getFinal();
}

void StudentRecord::updateScores(float midterm, float final) {
    /* TODO: this keyword 사용해 보기 */
    // c++에서 this는 포인터입니다. 때문에 (*this).var 도 가능합니다만, 번거롭기 떼문에 this->var 를 사용합니다.
    this->midterm = midterm;
    (*this).final = final;
}


/* Student */

Student::Student() : name(""), id(-1), record(0,0)
/* TODO: Initializer list 사용해 초기화 해보기 */
{ }

Student::Student(const char *name, int id, float midterm, float final) : name(name), id(id), record(midterm, final)
/* TODO: Initializer list 사용해 초기화 해보기 */
{  }

void Student::updateRecord(const char *name, float midterm, float final) {
    /* TODO */
    this->name = name;
    (this->record).updateScores(midterm, final);
}

