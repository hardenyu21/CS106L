// initialization and references, stream

#include<iostream>
#include<vector>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>

std::tuple<std::string, std::string, std::string> getclassinfo(){
    std::string className = "CS106L";
    std::string buildingName = "Turing Auditorium";
    std::string language = "C++";
    return {className, buildingName, language};
}

void demo1(){

    /* 1 
    auto [className, buildingName, language] = getclassinfo();
    */
   /* 2
    auto classinfo = getclassinfo();
    std::string className = std::get<0>(classinfo);
    std::string buildingName = std::get<1>(classinfo);
    std::string language = std::get<2>(classinfo);
   */
    auto [className, buildingName, language] = getclassinfo();
    std::cout << "come to " << buildingName << " and join us for " << className
    << " to learn " << language << "!" << std::endl;
}

void squareN(int& n){
    n = std::pow(n, 2);
}

void demo2(){

    int num = 2;
    squareN(num);
    //squareN(2); raise error
    std::cout<< num << std::endl;
}

void shift(std::vector<std::pair<int, int>> &nums){

    /*1 not change 
    for (auto & [num1, num2]: nums){
        num1++;
        num2++;
    }
    */
   /*2 change*/
    for (auto & [num1, num2]: nums){
        num1++;
        num2++;
    }
}

void demo3(){
    std::vector<std::pair<int, int>> nums = {{1, 2}, {3, 4}, {5, 6}};
    shift(nums);
    for (auto [num1, num2]: nums){
        std::cout << num1 << " " << num2 << std::endl;
    }
}

void demo4(){

    std::vector<int> vec{ 1, 2, 3 };
    const std::vector<int> const_vec{ 1, 2, 3 };
    std::vector<int> & ref_vec{ vec };
    const std::vector<int> & const_ref { vec };
    
    vec.push_back(3);               // ok
    //const_vec.push_back(3);         // No
    ref_vec.push_back(3);           // ok
    //const_ref.push_back(3);         // No

}


void classExample() {
  std::string lectureString = "1 2 3 4 5 6";
  /// initializing a stringstream with lectureString
  std::stringstream ss(lectureString);

  ///  defining my output type as a int for 'one', 'two', 'three', 'four'
  int one, two, three, four;

  /// defining my output type for five as a string
  std::string five, six;

  ss >> one;
  ss >> two;
  ss >> three;
  ss >> four >> five >> six;

  std::cout << one + two + three + four << std::endl;
}

/*Bjarne Stroustrup said this: C makes*/
void extractedQuoteFailureExample() {
  /// partial Bjarne Quote
  std::string initial_quote =
      "Bjarne Stroustrup C makes it easy to shoot yourself in the foot";

  /// create a stringstream
  std::stringstream ss;
  ss << initial_quote;

  /// data destinations
  std::string first;
  std::string last;
  std::string language, extracted_quote;

  ss >> first >> last >> language >> extracted_quote;
  std::cout << first << " " << last << " said this: " << language << " "
            << extracted_quote << std::endl;
}

/*said:  Bjarne Stroustrup C makes it easy to shootyourself in the foot */
void extractedQuoteSuccessExample() {
  /// partial Bjarne Quote
  std::string initial_quote = "Bjarne Stroustrup C makes it easy to shoot"
                              "yourself in the foot ";

  /// create a stringstream
  std::stringstream ss(initial_quote);

  /// data destinations
  std::string first;
  std::string last;
  std::string language, extracted_quote;
  std::getline(ss, extracted_quote);
  ss >> first >> last >> language;

  std::cout << first << " " << last << " said: " << language << " "
            << extracted_quote << '\n';
}

/*
 * Weird behaviour!
 */
void extractedQuoteSuccessExampleOrdered() {
  /// partial Bjarne Quote
  std::string initial_quote = "Bjarne Stroustrup C makes it easy to shoot"
                              "yourself in the foot ";

  /// create a stringstream
  std::stringstream ss(initial_quote);

  /// data destinations
  std::string first;
  std::string last;
  std::string language, extracted_quote;
  ss >> first >> last >> language;
  std::getline(ss, extracted_quote);

  std::cout << first << " " << last;
  std::cout << " said: " << language << " " << extracted_quote << '\n';
}

void verifyPi() {
  double pi;
  std::cin >> pi;
  /// verify the value of pi and type
  std::cout << pi / 2 << '\n';
}

int outputFileStreamCodeTruncate() {
  /// associating file on construction
  std::ofstream ofs("truncate.txt");
  if (ofs.is_open()) {
    ofs << "Hello CS106L!" << '\n';
  }
  ofs.close();
  ofs << "this will not get written";

  // to append instead of truncate!
  ofs.open("truncate.txt");
  ofs << "this will though! It’s open again";
  return 0;
}

int outputFileStreamCodeAppend() {
  /// associating file on construction
  std::ofstream ofs("append.txt");
  if (ofs.is_open()) {
    ofs << "Hello CS106L!";
  }
  ofs.close();
  ofs << "this will not get written";

  // to append instead of truncate!
  ofs.open("append.txt", std::ios::app);
  ofs << "this will though! It’s open again";

  ofs.close();
  return 0;
}

int inputFileStreamExample() {
  std::ifstream ifs("append.txt");
  if (ifs.is_open()) {
    std::string line;
    std::getline(ifs, line);
    std::cout << "Read from the file: " << line << '\n';
  }

  if (ifs.is_open()) {
    std::string lineTwo;
    std::getline(ifs, lineTwo);
    std::cout << "After reopening, read: " << lineTwo << '\n';
  }

  return 0;
}

void cinFailure() {
  double pi;
  double tao;
  std::string name;
  std::cin >> pi;
  std::cin >> name;
  std::cin >> tao;
  std::cout << "my name is : " << name << " tao is : " << tao
            << " pi is : " << pi << '\n';
}

void cinGetlineBug() {
  double pi;
  double tao;
  std::string name;
  std::cin >> pi;
  std::getline(std::cin, name);
  std::cin >> tao;
  std::cout << "my name is : " << name << " tao is : " << tao
            << " pi is : " << pi << '\n';
}

void cinActuallyFixed() {
  double pi;
  double tao;
  std::string name;
  std::cin >> pi;

  /// consumes the '\n' character
  std::getline(std::cin, name);
  std::getline(std::cin, name);
  std::cin >> tao;
  std::cout << "my name is : " << name << " tao is : " << tao
            << " pi is : " << pi << '\n';
}

int testFstream() {
  std::fstream fs("append.txt", std::ios::in | std::ios::out | std::ios::app);

  // Write to the file
  if (fs.is_open()) {
    fs << "Hello CS106L!" << '\n';

    // moves the get pointer to the beginning of the file
    fs.seekg(0, std::ios::beg);

    std::string line;
    std::getline(fs, line);
    std::cout << "Read from the file: " << line << '\n';

    std::string lineTwo;
    std::getline(fs, lineTwo);
    std::cout << "Read from the file: " << lineTwo << '\n';
  } else {
    std::cout << "Whoops the file is not open!" << '\n';
  }
  // close the file when done!
  fs.close();

  return 0;
}

/*
 * TODO(Fabio): fix the stream bug in this code!
 *
int main() {
  std::map<std::string, std::function<void()>> functionMap = {
      {"extractedQuoteFailureExample", extractedQuoteFailureExample},
      {"extractedQuoteSuccessExample", extractedQuoteSuccessExample},
      {"extractedQuoteSuccessExampleOrdered",
       extractedQuoteSuccessExampleOrdered},
      {"verifyPi", verifyPi},
      {"cinFailure", cinFailure},
      {"cinGetlineBug", cinGetlineBug},
      {"cinActuallyFixed", cinActuallyFixed},
      {"testFstream", testFstream},
      {"classExample", classExample},
      {"outputFileStreamCodeTruncate", outputFileStreamCodeTruncate},
      {"outputFileStreamCodeAppend", outputFileStreamCodeAppend},
      {"inputFileStreamExample", inputFileStreamExample}};

  std::string inputFunctionName;
  while (true) {
    std::cout << "\nYou can run one of these functions:\n";
    for (const auto &pair : functionMap) {
      std::cout << pair.first << '\n';
    }
    std::cout << "\nEnter the name of the function you want to run (or 'exit' "
                 "to quit): ";
    std::getline(std::cin, inputFunctionName);

    if (inputFunctionName == "exit") {
      break;
    }

    auto iter = functionMap.find(inputFunctionName);
    if (iter != functionMap.end()) {
      std::cout << "\n###### OUTPUT ######\n";
      iter->second();
    } else {
      std::cout << "Function name not recognized. Please try again."
                << std::endl;
    }
  }

  return 0;
}
*/

int main(){
  
    //demo1();
    //demo2();
    //demo3();
    //demo4();
    //extractedQuoteFailureExample();
    //extractedQuoteSuccessExample();
    //extractedQuoteSuccessExampleOrdered();
    cinFailure();
    return 0;
}

