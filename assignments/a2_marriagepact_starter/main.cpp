/* 
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and pointers.
There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <fstream>
#include <sstream>
#include <random>

std::string YOUR_NAME = "SS";
std::string filename = "/Users/hardenyu/Study/CS106L/assignments/a2_marriagepact_starter/students.txt";

std::set<std::string> get_applicants(std::string filename) {
    // TODO: Implement this function. Feel free to change std::set to std::unordered_set if you wish!

    std::ifstream ifs(filename);
    std::string name;
    std::set<std::string> students;
    if(ifs.is_open()){
        while(std::getline(ifs, name)){
            students.insert(name);
        }
    }
    return students;
}

std::queue<std::string*> find_matches(std::set<std::string> &students) {
    // TODO: Implement this function.
    std::queue<std::string*> que;
    for (auto it = students.begin(); it != students.end(); it++){

        std::string* ptr = new std::string(*it); 
        std::string name = *it;
        std::istringstream ss(name);
        std::string token;
        std::string initial;

        while(std::getline(ss, token, ' ')){
            initial += token[0];
        }
        if (initial == YOUR_NAME){
            que.push(ptr);
        }
        else{
            delete ptr;
        }
    }
    return que;
}



int main() {
    // Your code goes here. Don't forget to print your true love!
    
    std::set <std::string> students = get_applicants(filename);
    //std::cout << students.size() << std::endl;  1000
    std::queue<std::string*> que = find_matches(students);
    if (que.empty()){
        std::cout << "NO STUDENT FOUND." << std::endl;
    }
    else{
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, que.size());
        int random_idx = dis(gen);
        for (int i = 1; i < random_idx; i++){
            que.pop();
        }
        std::string* match = que.front();
        std::cout << "STUDENT MATCHES WITH YOU: " << *match << std::endl;
    }

    return 0;
}
