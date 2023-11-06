#include "project.h"
#include <iostream>



void project::set_name(std::string c_name) {
    while(c_name.length() <= 2){
        std::cout << "The name of the project can't be that short";
        std::cin >> c_name;
    }
    this->name = c_name;
}

void project::set_death_line(std::string date) {
    while(date.length() != 10){
        std::cout << "Enter a valid date";
        std::cin >> date;
    }
    this->death_line = date;
}

project::project() {
    this->name = "";
    this->death_line = "";
}

project::project(std::string name, std::string death_line) {
    set_death_line(std::move(death_line));
    set_name(std::move(name));
}

project::~project() {
//    std::cout << "This project is completed or just being removed";
}

std::string project::get_name() {
    return this->name;
}

std::string project::get_death_line() {
    return this->death_line;
}

void project::get_info() {
    std::cout << "The project name is " << this->name << std::endl;
    std::cout << "The death line of the project is " << this->death_line << std::endl;
}

std::ostream& operator<<(std::ostream& os, const project& obj){
    os << "The project name is " << obj.name << std::endl;
    os << "The death line of the project is " << obj.death_line << std::endl;

    return os;
}
