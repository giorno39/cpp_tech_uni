#include <iostream>
#include "employee.h"
#include "company.h"
#include "department.h"
#include "project.h"
#include "vector"

std::vector<company> companies;

void add_company(){
    company c_comp = company();
    std::string type, c_name;
    int is_vat;

    std::cout << "Enter a name for the company: ";
    std::cin >> c_name;
    c_comp.set_name(c_name);
    std::cout << "Enter a type of company OOD - AD - EOOD: ";
    std::cin >> type;
    c_comp.set_type_of_company(type);
    std::cout << "Enter if the comapny has VAT or not 0 - 1: ";
    std::cin >> is_vat;
    c_comp.set_vat(is_vat);
    c_comp.get_info();
    companies.insert(companies.end(), c_comp);
}

void get_current_companies(){
    for (int i = 0; i < companies.size(); ++i) {
        std::cout << i << ". ";
        companies[i].get_info();
        std::cout << std::endl << std::endl;
    }
}


void edit_company(){
    int company_num;
    std::cout << "Enter the number of the company you want to edit: ";
    std::cin >> company_num;
    while(company_num < 0 || company_num >= companies.size()){
        std::cout << "Enter a valid number between 0 and " << companies.size() - 1;
        std::cin >> company_num;
    }

    company* c_comp = &companies[company_num];
    std::string c_name;
    std::cout << "Current name: " << c_comp->get_name() << std::endl << "Enter new name: ";
    std::cin >> c_name;
    c_comp->set_name(c_name);
    std::cout << "Other properties cannot be modified after the creation" << std::endl;

}

void edit_department(company* c_comp){
    int department_num;
    std::cout << "Enter the number of the company you want to edit: ";
    std::cin >> department_num;
    while(department_num < 0 || department_num >= c_comp->departments.size()){
        std::cout << "Enter a valid number between 0 and " << c_comp->departments.size() - 1;
        std::cin >> department_num;
    }

    department* dep = &c_comp->departments[department_num];
    std::string c_name;
    std::cout << "Current name: " << dep->get_name() << std::endl << "Enter a new name: ";
    std::cin >> c_name;
    dep->set_name(c_name);
    std::cout << "Current date: " << dep->get_initial_date() << std::endl << "Enter a new date";
    std::cin >> c_name;
    dep->set_initial_date(c_name);
    std::cout << "Other properties cannot be modified after the creation" << std::endl;

}

void project_menu(){
    
}

void department_menu(int company_num){
    company* c_comp = &companies[company_num];
    int action;
    int exit_flag = 0;




    while(true){
        std::cout << "Enter a number, based on the action you want to take: " << std::endl;
        std::cout << "1. Add department" << std::endl;
        std::cout << "2. See departments" << std::endl;
        std::cout << "3. Select and edit department" << std::endl;
        std::cout << "4. Go to workers menu of a department" << std::endl;
        std::cout << "5. Go to project menu of a department" << std::endl;
        std::cout << "6.Exit" << std::endl;
        std::cin >> action;
        switch (action) {
            case 1:
                c_comp->add_department();
                break;
            case 2:
                c_comp->get_department_info();
                break;
            case 3:
                edit_department(c_comp);
                break;
            case 4:
                break;
            case 5:
                project_menu();
                break;
            case 6:
                exit_flag = 1;
                break;
        }
        if(exit_flag){
            break;
        }
    }


}

void start(){
    int action;
    int exit_flag = 0;

    while(true){
        std::cout << "Enter a number, based on the action you want to take: " << std::endl;
        std::cout << "1. Add company" << std::endl;
        std::cout << "2. See companies" << std::endl;
        std::cout << "3. Select and edit company" << std::endl;
        std::cout << "4. Go to department menu of a company" << std::endl;
        std::cout << "5. Save and exit" << std::endl;
        std::cout << "6. Clear data and exit" << std::endl;
        std::cin >> action;
        switch (action) {
            case 1:
                add_company();
                break;
            case 2:
                get_current_companies();
                break;
            case 3:
                edit_company();
                break;
            case 4:
                int num;
                std::cout << "Enter the number of the company 0 - " << companies.size() - 1 << ": ";
                std::cin >> num;
                while(num < 0 || num >= companies.size()){
                    std::cout << "Enter the number of the company 0 - " << companies.size() - 1 << ": " ;
                    std::cin >> num;
                }
                department_menu(num);
                break;
            case 6:
                exit_flag = 1;
                break;
        }
        if(exit_flag){
            std::cout << "Thanks for using our service" << std::endl;
            break;
        }
    }
}

int main() {
    start();
    return 0;
}
