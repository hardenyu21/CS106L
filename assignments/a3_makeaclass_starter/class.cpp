// Blank cpp file

#include <iostream>
#include <iomanip>
#include "class.h"

Student::Student(){
    name = "Zhang san";
    major = "Computer science";
    uid = "xxxxxxxx";
    Grades Grade = {"C++", 90, 3.0, "2023-2024 Winter"};
    transcript = {{"C++", Grade}};
    average_score = Grade.score;
    total_credit = Grade.credit;
}

Student::Student(std::string name, std::string major, std::string uid,
                 std::map<std::string, Grades> transcript){

    this -> name = name;
    this -> major = major;
    this -> uid = uid;
    this -> transcript = transcript;
    float average_score = 0;
    float total_credit = 0;
    float sum_score = 0;
    if(transcript.empty()){
        this -> average_score = average_score;
        this -> total_credit = total_credit;
    }
    else{
        for(auto it = transcript.begin(); it != transcript.end(); it++){
            Grades Grade = it -> second;
            total_credit += Grade.credit;
            sum_score += Grade.score * Grade.credit;
        }
        this -> total_credit = total_credit;
        this -> average_score = sum_score / total_credit;
    }
}

std::string Student::getName(){
    return name;
}
std::string Student::getMajor(){
    return major;
}
std::string Student::getUid(){
    return uid;
}
int Student::getGrade(const std::string subject){
    try {
        Grades Grade = transcript.at(subject); 
        return Grade.score;
    } 
    catch (const std::out_of_range& oor) {
        return -1;
    }
}


void Student::setMajor(const std::string major){
    this -> major = major;
}
void Student::setUid(const std::string uid){
    this -> uid = uid;
}
void Student::setGrades(const Grades Grade){
    std::string course = Grade.course;
    int score = Grade.score;
    float credit = Grade.credit;
    if (transcript.count(course) > 0){
        Grades oldGrade =  transcript[course];
        average_score = (average_score * total_credit + score * credit - oldGrade.score * oldGrade.credit) / (total_credit + credit - oldGrade.credit);
        total_credit += credit - oldGrade.credit;
        transcript[course] = Grade;
    }
    else{
    average_score = (average_score * total_credit + score * credit) / (total_credit + credit);
    total_credit += credit;
    transcript.insert({course, Grade});
    }
}

void Student::print_transcript() const{
    if (transcript.empty()){
        std::cout << "The transcript of the student is None" << std::endl;
    }
    else{
        std::cout << std::setw(30) << std::left << "Course"
              << std::setw(30) << std::left << "Score"
              << std::setw(30) << std::left << "Credit" 
              << std::setw(30) << std::left << "Curriculum" << std::endl;
        std::cout << std::setw(100) << std::setfill('-') << "" << std::endl;
        std::cout << std::setfill(' ');
        for(auto it = transcript.begin(); it != transcript.end(); it++){
            Grades Grade = it -> second;
            std::cout << std::setw(30) << std::left << Grade.course
                << std::setw(30) << std::left << Grade.score
                << std::setw(30) << std::left << Grade.credit
                << std::setw(30) << std::left << Grade.curriculum << std::endl;
        }
        std::cout << std::setw(100) << std::setfill('-') << "" << std::endl;
        std::cout << std::setfill(' ');
        std::cout << "Average_score: " << average_score << std::endl;
        std::cout << "Total_credit: " << total_credit << std::endl;  
    }
}