// Blank header file
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


#include <string>
#include <map>
#include <vector>

struct Grades{
    std::string course;
    int score;
    float credit;
    std::string curriculum;
};

class Student{
    public:
        Student();
        Student(std::string name, std::string major, std::string uid,
                 std::map<std::string, Grades> transcript);

        std::string getName();
        std::string getMajor();
        std::string getUid();
        int getGrade(const std::string subject);

        void setMajor(const std::string major);
        void setUid(const std::string Uid);
        void setGrades(const Grades grade);
        void print_transcript() const;

    private:
        std::string name;
        std::string major;
        std::string uid;
        std::map<std::string, Grades> transcript;
        float total_credit;
        float average_score;

};

