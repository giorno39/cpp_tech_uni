#include "department.h"
#include <iostream>
#include "company.h"

void department::set_name(std::string name) {
    while(name.length() <= 2){
        std::cout << "The name of the department can't be that short";
        std::cin >> name;
    }
    this->name = name;
}

void department::set_initial_date(std::string date) {
    while(date.length() != 10) {
        std::cout << "Enter a valid date";
        std::cin >> date;
    }
    this->initial_date = std::move(date);
}

department::department() {
    this->name = "";
    this->initial_date = "";
}

department::department(std::string name, std::string date) {
    set_name(std::move(name));
    set_initial_date(date);
}


department::~department() {
//    std::cout << "This department is being closed";
}

std::string department::get_name() {
    return this->name;
}

std::string department::get_initial_date() {
    return this->initial_date;
}


void department::add_worker() {
    std::string egn, exp, name;
    int h, proj;
    std::cout << "Enter a name: ";
    std::cin >> name;
    std::cout << "Enter egn: ";
    std::cin >> egn;
    std::cout << "Enter experience Junior-Mid-Senior: ";
    std::cin >> exp;
    std::cout << "Enter hours per day 4-16";
    std::cin >> h;
    std::cout << "Enter a valid project 0-" << projects.size() - 1;
    std::cin >> proj;
    while(proj < 0 || proj >= projects.size()){
        std::cout << "Enter a valid project 0-" << projects.size() - 1;
        std::cin >> proj;
    }
    project c_proj = projects[proj];
    employee c_employee = employee(name, egn, exp, h, c_proj);
    employees.insert(employees.end(), c_employee);
}

void department::add_project() {
    std::string c_name, c_date;
    std::cout << "Enter a name for the project: ";
    std::cin >> c_name;
    std::cout << "Enter the death line for the prject: ";
    std::cin >> c_date;
    project temp = project(c_name, c_date);
    projects.insert(projects.end(), temp);
}


void department::get_info() {
    std::cout << "The name of the department is " << this->name << std::endl;
    std::cout << "There are " << this->employees.size() << " employees in this department" << std::endl;
    std::cout << "This department opened at " << this->initial_date << std::endl;
    std::cout << "This department is working on " << this->projects.size() << " projects" << std::endl;
}

void department::get_worker_info() {
    for(employee c_emp: this->employees){
        c_emp.get_info();
    }
}

void department::get_projects_info() {
    for(project c_proj:projects){
        c_proj.get_info();
    }
}