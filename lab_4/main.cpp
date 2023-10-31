#include <iostream>


class item {
    public:
        std::string title;
        int price;
        int id; //do it to be an autoincrement variable
        std::string date;
        std::string media_format;

        item(std::string i_title, int i_price,int i_id, std::string i_date);
        void show_item();
};


item::item(std::string i_title, int i_price, int i_id, std::string i_date) {
    this->title = i_title;
    this->price = i_price;
    this->id = i_id;
    this->date = i_date;
    this->media_format = "";
}

void item::show_item() {
    std::cout << this->media_format << " с заглавие"  << this->title << "е била за купена на цена " << this->price << "на дата " << this->date;
}

class movie: public item {
public:
    int rating;
    std::string const type = "Movie";
    movie(int m_rating, std::string i_title, int i_price,int i_id, std::string i_date):item(i_title, i_price, i_id, i_date){
        this->rating = m_rating;
        this->media_format = type;
    }

    void show_movie(){
        this->show_item();
        std::cout << ". The rating of the movie is " << this->rating;
    }
};

class game:public item{
public:
    int difficulty_level;
    std::string const type = "Game";
    game(int diff_level, std::string i_title, int i_price,int i_id, std::string i_date):item(i_title, i_price, i_id, i_date){
            this->difficulty_level = diff_level;
            this->media_format = type;
    }

    void show_game(){
        this->show_item();
        std::cout << ". The difficult of the game is: " << this->difficulty_level;
    }
};

class music:public item{
    std::string band_or_artist;
    std::string const type = "Music";
    music(std::string band_artist, std::string i_title, int i_price,int i_id, std::string i_date):item(i_title, i_price, i_id, i_date){
        this->band_or_artist = band_artist;
        this->media_format = type;
    }
    void show(){
        this->show_item();
        std::cout << ". The artist is: " << this->band_or_artist;
    }
};


int main() {
    movie m1(2, "Herry", 23, 1, "22/22/2022");
    m1.show_movie();
}
