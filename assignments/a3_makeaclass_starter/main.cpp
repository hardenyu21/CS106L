/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor  ✅
 * Must have a default constructor  ✅
    - i.e. constructor overloading
 * Must have private members (functions and/or variables) ✅
 * Must have public members (functions)  ✅
 * Must have at least one getter function ✅
 * Must have at least one setter function ✅
 */

#include "class.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector> 
#include <iostream>

std::string FILE_PATH = "/Users/hardenyu/Study/CS106L/assignments/a3_makeaclass_starter/transcript.csv";

int main() {
  // initialize class and run this file
  std::ifstream ifs(FILE_PATH);
  std::string name = "HardenYu";
  std::string major = "Computer Science";
  std::string uid = "hy221666";
  std::map<std::string, Grades> transcript;
  if (ifs.is_open()) {
    std::string line;
    while (std::getline(ifs, line)) {
      std::stringstream ss(line);
      std::string token;
      Grades Grade;
      std::vector<std::string> course_vec;
      while (std::getline(ss, token, ',')){
        course_vec.push_back(token);
      }
      Grade = {course_vec[0], std::stoi(course_vec[1]), std::stof(course_vec[2]), course_vec[3]};
      transcript.insert({course_vec[0], Grade});
      }
  }
  ifs.close();


  Student student(name, major, uid, transcript);

  //getname
  std::cout << "Stdudent Name: " << student.getName() << std::endl;

  //getmajor
  std::cout << "Stdudent Major: " << student.getMajor() << std::endl;

  //getname
  std::cout << "Stdudent Uid: " << student.getUid() << std::endl;

  //getGrade
  std::vector<std::string> subjects= {"Database", "Computer Architecture"};
  for (std::string subject: subjects){
    int score = student.getGrade(subject);
    if (score == -1){
      std::cout << "Subject Not Found" << std::endl;
    }
    else{
      std::cout << "Score of " << subject << ": " << score << std::endl;
    }
  }

  //setmajor
  std::string new_major = "Data Science";
  student.setMajor(new_major);
  std::cout << "Stdudent Major: " << student.getMajor() << std::endl;

  //setuid
  std::string new_uid = "HY221666";
  student.setUid(new_uid);
  std::cout << "Stdudent Uid: " << student.getUid() << std::endl;

  //setgrade
  Grades Grade1 = {"Database", 99, 3.0, "2024 Spring"};
  student.setGrades(Grade1);
  std::cout << "Score of " << Grade1.course << ": " << student.getGrade(Grade1.course) << std::endl;

  Grades Grade2 = {"Computer Architecture", 91, 3.0, "2024 Winter"};
  student.setGrades(Grade2);
  std::cout << "Score of " << Grade2.course << ": " << student.getGrade(Grade2.course) << std::endl;

  student.print_transcript();

  return 0;
}


