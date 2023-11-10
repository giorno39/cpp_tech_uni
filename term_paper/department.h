#ifndef TERM_PAPER_DEPARTMENT_H
#define TERM_PAPER_DEPARTMENT_H
#include "vector"
#include "string"
#include "project.h"
#include "employee.h"


class department {
    private:
        std::string name;
        std::string initial_date;
    public:
        department();
        department(std::string name, std::string date);
        ~department();
        std::string get_name();
        void set_name(std::string name);
        std::string get_initial_date();
        void set_initial_date(std::string date);
        void add_worker();
        void add_project();
        void get_info();
        void get_worker_info();
        void get_projects_info();
        std::vector <project> projects;
        std::vector <employee> employees;
        friend std::ostream& operator<<(std::ostream& os, const department& obj);


};


#endif //TERM_PAPER_DEPARTMENT_H
