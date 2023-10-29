#ifndef TERM_PAPER_DEPARTMENT_H
#define TERM_PAPER_DEPARTMENT_H
#include "vector"
#include "string"
#include "project.h"
#include "employee.h"


class department {
    private:
        std::string name;
        std::vector <employee> employees;
        std::string initial_date;
        std::vector <project> projects;
    public:
        department();
        department(std::string name, std::string date);
        ~department();
        std::string get_name();
        void set_name(std::string name);
        std::string get_initial_date();
        void set_initial_date(std::string date);
        void add_worker();
        // call the employee constructor and increment the workers value
        void add_project();
        //call the project constructor and write it in a file
        void get_info();
        void get_worker_info();
        void get_projects_info();

};


#endif //TERM_PAPER_DEPARTMENT_H
