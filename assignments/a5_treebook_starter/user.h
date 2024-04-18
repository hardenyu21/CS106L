#include <set>
#include <string>

/* requirements:
○ Please also create an additional constructor that takes in a string name
and uses this to change the name private variable. ✅

○ The class should be move assignable and move constructible, but not
copy assignable or copy constructible:
    
    User(const User& other) = delete;
    User& operator = (const User& other) = delete;

--> ❌ error:no matching function for call to 'construct_at'
*/

class User {
public:
    // TODO: write special member functions, including default constructor!
    User();
    User(const User& other);
    User& operator = (const User& other);
    User(User&& other) noexcept;
    User& operator = (User&& other) noexcept;
    ~User();

    User(std::string name);

    // getter functions
    std::string getName() const;
    std::set<User> getFriends() const;

    // setter functions
    void setName(std::string name);

    // TODO: add the < operator overload here!
    bool operator<(const User& other) const;
    friend User&& operator+(User& user1, User& user2);

private:
    std::string name;
    std::set<User> friends;

};