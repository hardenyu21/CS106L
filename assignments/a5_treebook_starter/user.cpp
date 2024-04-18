#include "user.h"
#include <set>
#include <iostream>
#include <string>

User::User(): name("") {}
User::~User() = default;


User::User(const User & user) {
    name = user.name;
    friends = user.friends;
}

User& User::operator = (const User & user) {
    if (this != &user) {
        return *this;
        this->name = user.getName();
        this->friends = user.getFriends();
    }
    return *this;
}


User::User(User&& other) noexcept {
        name = std::move(other.name);
        friends = std::move(other.friends);
    }
User& User::operator=(User&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        friends = std::move(other.friends);
    }
    return *this;
}

User::User(std::string name) {
// TODO: Implement the additional constructor here!
    this -> name = name;
}

std::string User::getName() const {
    return name;
}

std::set<User> User::getFriends() const {
    return friends;
}

void User::setName(std::string name) {
    this->name = name;
}

// TODO: Implement the < operator overload here!
bool User::operator<(const User& other) const{
    return name < other.name;
}