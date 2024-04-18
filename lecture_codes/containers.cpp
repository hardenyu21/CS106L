// containers and iterators

#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <iostream>

/*vector: unsequential*/
void vector_demo(){
    
    int n = 5, k = 1, i = 10;
    std::vector<int> vec1;   //initialize with default value
    std::vector<int> vec2(n); // initialize with default value given size
    std::vector<int> vec3(n, k); // initialize with given value and given size
    
    vec1.push_back(k);  //append
    vec1.clear(); //remove all
    
    int value = vec1[i]; // error if out of range
    int size = vec1.size();   //size of vec
    //loop
    for (std::size_t j = 0; j < size; ++j){
        continue;
    }
    vec1[i] = k; //replace, error if out of range
}

/*set:associative*/
void set_demo(){
    
    int k = 1;
    std::set<int> s;
    s.insert(k);  //(1)
    s.erase(k); //()
    bool in_set = s.count(k); //check if k in set
    bool is_empty = s.empty();  // check if empty
}


/*map: associative*/

void map_demo(){
    int k = 1;
    std::string v = "test";
    std::map<int, std::string> m;

    //insert
    m.insert({k, v});
    //m[k] = v;

    m.erase(k); //remove

    bool in_map = m.count(k);     // > 0 
    bool is_empty = m.empty();

    //overwrite and retrieve
    std::string s = m.at(k); //error if key not in map
    m.at(k) = v;

    std::string s1 = m[k]; //auto insert if key not in map
    m[k] = v;

}


/*container adaptors*/
void adap_demo(){
    std::queue<int> que;    //FIFO
    std::stack<int> sta;    //LIFO
    std::priority_queue<int> p_que; 
}


//iterator
void ite_demo(){
    
    int n = 10;
    std::vector<int> vec(n);
    for (std::size_t i = vec.size(); i < vec.size(); i++){
        vec[i] = i * 2 + 1;
    }
    for(auto it = vec.begin(); it != vec.end(); ++it){
        const int num = *it;
        std::cout << num << std::endl;
    }


}