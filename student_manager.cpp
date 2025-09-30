#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    // Student st = {name, id, midterm, final};
    students[num_of_students++] = {name, id, midterm, final};
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    if (findStudentByID(id) > 0){
        for (int i=id + 1; i<num_of_students; i++) {
            students[i-1] = students[i];
        }
        num_of_students--;
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    if (findStudentByID(student.getID()) > -1)
        students[student.getID() - 1000] = student;
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for (int idx=0; idx<num_of_students; idx++) {
        if (students[idx].getID() == id){
            return idx;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    if (last_student_id <= 1000)    return -1;
    Student best = students[0];
    for (int idx=0; idx<num_of_students; idx++) {
        best = best.getRecord().getMidterm() < students[idx].getRecord().getMidterm() ? students[idx] : best;
    }
    return best.getRecord().getMidterm();
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    if (last_student_id <= 1000)    return -1;
    Student best = students[0];
    for (int idx=0; idx<num_of_students; idx++) {
        best = best.getRecord().getFinal() < students[idx].getRecord().getFinal() ? students[idx] : best;
    }
    return best.getRecord().getFinal();
}

int StudentManager::findBestStudent() const {
    /* TODO */
    if (last_student_id <= 1000)    return -1;
    Student best = students[0];
    for (int idx=0; idx<num_of_students; idx++) {
        best = best.getRecord().getFinal() < students[idx].getRecord().getFinal() ? students[idx] : best;
    }
    return best.getRecord().getTotal();
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float sum = 0.0f;

    for (int i=0; i<num_of_students; i++) 
        sum += students[i].getRecord().getMidterm();
    return sum/num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float sum = 0.0f;
    
    for (int i=0; i<num_of_students; i++) 
        sum += students[i].getRecord().getFinal();
    return sum/num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    return ((getMidtermAverage() + getFinalAverage())/2.0f);
}

