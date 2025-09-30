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
    int idx = findStudentByID(id);
    if (idx >= 0){
        for (int i = idx + 1; i < num_of_students; i++) {
            students[i-1] = students[i];
        }
        num_of_students--;
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    if (findStudentByID(student.getID()) > -1)
        students[student.getID() - 1001] = student;
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
    return best.getID();
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    if (last_student_id <= 1000)    return -1;
    Student best = students[0];
    for (int idx=0; idx<num_of_students; idx++) {
        best = best.getRecord().getFinal() < students[idx].getRecord().getFinal() ? students[idx] : best;
    }
    return best.getID();
}

int StudentManager::findBestStudent() const {
    /* TODO */
    if (num_of_students <= 0)    return -1;
    Student best = students[0];
    for (int idx=0; idx<num_of_students; idx++) {
        best = best.getRecord().getMidterm() + best.getRecord().getFinal() < students[idx].getRecord().getMidterm() + students[idx].getRecord().getFinal() ? students[idx] : best;
    }
    return best.getID();
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float sum = 0.0f;

    for (int i=0; i<num_of_students; i++) 
        sum += students[i].getRecord().getMidterm();
    
    float avr = sum/num_of_students;
    return avr;
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
    return ((getMidtermAverage() + getFinalAverage()));
}

