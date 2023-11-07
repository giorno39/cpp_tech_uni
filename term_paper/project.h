#ifndef TERM_PAPER_PROJECT_H
#define TERM_PAPER_PROJECT_H
#include "string"

class project{
    private:
        std::string name;
        std::string death_line;
    public:
        project();
        project(std::string name, std::string death_line);
        ~project();
        std::string get_name() const;
        void set_name(std::string c_name);
        std::string get_death_line();
        void set_death_line(std::string date);
        void get_info();
        friend std::ostream& operator<<(std::ostream& os, const project& obj);
};


#endif
