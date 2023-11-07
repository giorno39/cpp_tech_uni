#include <iostream>
#include <utility>
#include "company.h"

void company::set_type_of_company(std::string type) {
    while(type != "OOD" && type != "AD" && type != "EOOD"){
        std::cout << "This type is not a valid one \nThe valid ones are - OOD AD EOOD: ";
        std::cin >> type;
    }
    this->type_of_company = type;
    std::cout << "Type of the company has been set!" << std::endl;
}

void company::set_vat(bool is_vat) {
    if(is_vat){
        this->vat = true;
    }else{
        this->vat = false;
    }
}

void company::set_name(std::string new_name) {
    while(new_name.length() <= 2){
        std::cout << "The name of the company should have at least 3 letters";
        std::cin >> new_name;
    }
    this->name = new_name;
}

company::company() {
    this->type_of_company = "";
    this->vat = NULL;
}

company::company(std::string type, bool vat, std::string new_name) {
    set_type_of_company(std::move(type));
    set_vat(vat);
    set_name(std::move(new_name));
}


company::~company(){

}



std::string company::get_company_type() {
    return this->type_of_company;
}



bool company::get_vat() {
    return this->vat;
}

void company::get_department_info() {
    int count = 0;
    if(departments.empty()){
        std::cout << "There are no departments in this company" << std::endl;
    }else{
        for(department c_dep:departments){
            std::cout << count << ". ";
            std::cout << c_dep;
            std::cout << std::endl;
            count++;
        }
    }
}

std::string company::get_name() {
    return this->name;
}

void company::add_department() {
    std::string c_name, c_date;
    std::cout << "Enter the name of the department: ";
    std::cin >> c_name;
    std::cout << "Enter the initial date of the department";
    std::cin >> c_date;
    department temp = department(c_name, c_date);
    departments.insert(departments.end(), temp);
}


std::ostream& operator<<(std::ostream& os, const company& obj) {
    os << "The name of the company is: " << obj.name << std::endl;
    os << "The type of company is " << obj.type_of_company << std::endl;
    os << "VAT: " << obj.vat << std::endl;
    os << "In this company there are " << obj.departments.size() << " departments" << std::endl;

    return os;
}

void company::get_info() {
    std::cout << "The name of the company is: " << this->name << std::endl;
    std::cout << "The type of company is " << this->type_of_company << std::endl;
    std::cout << "VAT: " << this->vat << std::endl;
    std::cout << "In this company there are " << departments.size() << " departments" << std::endl;
}




