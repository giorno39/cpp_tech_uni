#include <vector>
#include <string>
#include "department.h"
#include <fstream>

#ifndef TERM_PAPER_COMPANY_H
#define TERM_PAPER_COMPANY_H


class company {
    private:
        std::string name;
        std::string type_of_company;
        bool vat;
    public:
        company();
        company(std::string type, bool vat, std::string new_name);
        ~company();
        void set_name(std::string new_name);
        std::string get_name();
        void set_type_of_company(std::string type);
        std::string get_company_type();
        void set_vat(bool is_vat);
        bool get_vat();
        void get_department_info();
        void add_department();
        friend std::ostream& operator<<(std::ostream& os, const company& obj);
        std::vector <department> departments;
        void get_info();




};


#endif //TERM_PAPER_COMPANY_H
