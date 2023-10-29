#include "employee.h"
#include <iostream>

void employee::set_name(std::string c_name) {
    while(c_name.length() <= 2){
        std::cout << "The name must contain at least 3 letters";
        std::cin >> c_name;
    }
    this->name = c_name;
}


void employee::set_egn(std::string c_egn) {
    while(c_egn.length() != 10){
        std::cout << "Enter a valid egn";
        std::cin >> c_egn;
    }
    this->egn = c_egn;
}

void employee::set_work_experience(std::string experience) {
    while(experience != "Junior" || experience != "Mid" || experience != "Senior"){
        std::cout << "Valid work experience is Junior-Mid-Senior";
        std::cin >> experience;
    }
    this->work_experience = experience;
}

void employee::set_hours_per_day(int hours) {
    while(hours < 4 || hours >16){
        std::cout << "Enter a valid number for hour 4-16";
        std::cin >> hours;
    }
    this->hours_per_day = hours;
}

employee::employee() {
    this->name = "";
    this->egn = "";
    this->hours_per_day = 0;
    this->work_experience = "";
//    this->current_project = NULL;
}

employee::employee(std::string name, std::string egn, std::string work_experience, int hours, project proj) {
    set_name(std::move(name));
    set_egn(std::move(egn));
    set_work_experience(std::move(work_experience));
    set_hours_per_day(hours);
    this->current_project = proj;
}

employee::~employee() {
    std::cout << "This employee is being fired!";
}

std::string employee::get_name() {
    return this->name;
}

std::string employee::get_egn() {
    return this->egn;
}

std::string employee::get_work_experience() {
    return this->work_experience;
}

int employee::get_hours_per_day() {
    return this->hours_per_day;
}

void employee::get_info() {
    std::cout << "The employee names is: " << this->name << std::endl;
    std::cout << "The ID of the employee is: " << this->egn << std::endl;
    std::cout << "The works " << this->hours_per_day << " hours per day" << std::endl;
    std::cout << "Experience: " << this->work_experience << std::endl;
    this->current_project.get_info();
}

