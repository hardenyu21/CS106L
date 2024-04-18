// types and struct
#include<iostream>
#include<stdio.h>
#include <vector>

struct Student{
    std::string name;
    int age;
    char gender;
    int height;
    double weight;
};


bool NotFound(std::string name, const std::vector<Student>& students){
    for (const auto& student : students){
        if (name == student.name){
            return false;
        }
    }
    return true;
}

Student getStudentWithName(std::string name, const std::vector<Student>& students){
    for (const auto& student : students){
        if (name == student.name){
            return student;
        }
    }
    return Student(); // Return a default-constructed Student if not found
}

std::pair<bool, Student> lookupStudent(std::string name, const std::vector<Student>& students) {
    if (NotFound(name, students)) {
        return std::make_pair(false, Student());
    }
    Student result = getStudentWithName(name, students);
    return std::make_pair(true, result);
}

int main() {
    std::vector<Student> students = {
        {"Alice", 20, 'F', 160, 50.5},
        {"Bob", 21, 'M', 175, 70.2},
        {"Charlie", 22, 'M', 180, 80.0}
    };

    auto output = lookupStudent("Bob", students);
    if (output.first) {
        std::cout << "Student found: " << output.second.name << std::endl;
        std::cout << "age: " << output.second.age << " years old" << std::endl;
        std::cout << "gender: " << output.second.gender << std::endl;
        std::cout << "height: " << output.second.height << " cm" << std::endl;
        std::cout << "weight: " << output.second.weight << " kg" << std::endl;
    } else {
        std::cout << "Student not found" << std::endl;
    }
    return 0;
}

