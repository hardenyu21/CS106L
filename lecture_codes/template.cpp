//Template class and template functions


#include <iostream>
#include <string>

template <typename T>
class TemplateClass {
public:
    TemplateClass(T value) : value(value) {}
    void print() { 
        std::cout << value << std::endl; 
    }

private:
    T value;
};

template <typename T>
void print_info (T value){
    std::cout << value << std::endl;
}

template <typename T, typename U>
auto smaterMin (T a, U b){
    return a < b? a : b;
}

int main(){

TemplateClass<int> IntInstance(42);
IntInstance.print();

TemplateClass<double> DoubleInstance(3.14);
DoubleInstance.print();

print_info<int> (2);
print_info<std::string> ("C++");
std::cout << smaterMin(3.14, 4) << std::endl;

return 0;

}