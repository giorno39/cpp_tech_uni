#ifndef TERM_PAPER_EMPLOYEE_H
#define TERM_PAPER_EMPLOYEE_H
#include "string"
#include "project.h"

class employee {
    private:
        std::string name;
        std::string egn;
        std::string work_experience;
        int hours_per_day;
        project current_project;
    public:
        employee();
        employee(std::string name, std::string egn, std::string work_experience, int hours, project proj);
        ~employee();
        std::string get_name();
        void set_name(std::string c_name);
        std::string get_egn();
        void set_egn(std::string egn);
        std::string get_work_experience();
        void set_work_experience(std::string experience);
        int get_hours_per_day();
        void set_hours_per_day(int hours);
        void get_info();
        project get_project();
        friend std::ostream& operator<<(std::ostream& os, const employee& obj);
};


#endif
