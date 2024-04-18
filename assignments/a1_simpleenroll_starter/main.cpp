/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 */

#include "utils.cpp"
#include <exception>
#include <iostream>
#include <system_error>
#include <vector>

std::string COURSES_PATH = "/Users/hardenyu/Study/cs106L/assignments/a1_simpleenroll_starter/courses.csv";
std::string PYTHON_EXE_PATH = "~/opt/anaconda3/envs/hardenyu/bin/python3";
std::string pythonScript = "assignments/a1_simpleenroll_starter/utils/autograder.py";
bool structTest() {
  Course c{"Standard C++ Programming", "1", "2023-2024 Winter"};
  return true;
}

int main() {
  std::vector<Course> vector_of_courses;

  if (!structTest()) {
    std::cerr << "structTest Failed 😞";
  } else {
    std::cout << "structTest Passed! ✅" << '\n';
  }

  parse_csv(COURSES_PATH, vector_of_courses);

  write_courses_offered(vector_of_courses);

  write_courses_not_offered(vector_of_courses);


  // 构建完整的Python命令
  std::stringstream ss;
  ss << PYTHON_EXE_PATH << " " << pythonScript;
  std::string pythonCommand = ss.str();
  FILE *pipe = popen(pythonCommand.c_str(), "r");
  if (!pipe)
    return -1;

  char buffer[128];
  while (!feof(pipe)) {
    if (fgets(buffer, 128, pipe) != NULL)
      std::cout << buffer;
  }
  pclose(pipe);

  // uncomment this line to debug
  //print_vector(vector_of_courses);
  return 0;
}

