#include <windows.h>
#include <iostream>
using namespace std;

// Multi Dimensional Array (3D) Program #1
string movieList[5][7][5] = {
    // Action Movies from 2016-2022
    {{"The Nice Guys","Rogue One: A Star Wars Story","Suicide Squad","Deadpool","Jack Reacher: Never Go Back"},
    {"Blade Runner 2049","The Foreigner","John Wick 2", "Jumanji: Welcome to the Jungle","Logan Lucky"},
    {"The Meg","Spider-Man: Into the Spiderverse","The Equalizer 2","Ready Player One","Avengers: Infinity War"},
    {"The Gentlemen","Avengers: Endgame","John Wick 3: Parabellum","Ready Or Not","Star Wars: Episode IX - The Rise of Skywalker"},
    {"Tenet","Becky II","Wonder Woman","Birds of Prey","The Hunt 2"},
    {"Dune","Mortal Kombat","Those Who Wish Me Dead","Spiderman: No Way Home","Free Guy"},
    {"The Batman","Avatar: The Way of Water","Everything Everywhere All at Once","Top Gun: Maverick","Bullet Train"}},

    // Animated Movies from 2016-2022
    {{"Sing","Moana","Sausage Party","Zootopia","Your Name"},
    {"Coco","The Lego Batman Movie","Cars 3","Despicable Me 3","The Boss Baby"},
    {"Spiderman: Into the Spiderverse","Isle of Dogs","Incredibles 2","The Grinch","Ralph Breaks the Internet"},
    {"Toy Story 4","Frozen II","The Lego Movie 2: The Second Part","The Addams Family","How to Train your Dragon: The Hidden World"},
    {"Soul","Onward","Trolls World Tour","The Croods: New Age","Wolfwalkers"},
    {"Batman: Soul of the Dragon","I Am What","My Hero Academia: World Heroes Mission","Riverdance","Monster Family 2"},
    {"Puss in Boots: The Last Wish","Suzume","Guillermo De Toros Pinocchio","The Bad Guys","Turning Red"}},

    // Drama Movies from 2016-2022
    {{"Arrival","Hacksaw Ridge","Hell or High Water","La La Land","Me Before You"},
    {"Logan","Dunkirk","Blade Runner 2049","Baby Driver","Coco"},
    {"Avengers: Infinity War","Black Panther","Spiderman: Into the Spiderverse","Deadpool 2","Bohemian Rhapsody"},
    {"Joker","Midsommar","The Gentlemen","Once Upon a Time in Hollywood","Parasite"},
    {"Tenet","Promising Young Woman","Becky II","365 Days","Shiva Baby"},
    {"The Many Saints of Newark","Mass","Blue Bayou","Respect ","King Richard"},
    {"Talk to me","X II","The Batman","Dont Worry Darling","Death on the Nile"}},

    // Horror Movies from 2016-2022
    {{"Split IX","Terrifier","The Conjuring 2","Train to Busan","The Autopsy of Jane Doe"},
    {"It","Get Out","Jigsaw","Geralds Game","Life"},
    {"The Nun","Hereditary","The Meg","Annihilation","The House that Jack Built"},
    {"Midsommar","Doctor Sleep","Ready or Not","It Chapter Two","The Lighthouse"},
    {"Becky","Hubie Halloween","The Hunt 2","Empty Man","Spontaneous"},
    {"Wrong Turn","Willy's Wonderland","Fear of Rain","Son","The Seventh Day"},
    {"Talk to me","X II","The Menu","Pearl","Scream"}},

    // Romance Movies from 2016-2022
    {{"My Big Fat Greek Wedding 2","La La Land","Me Before You","The Handmaiden","Passengers"},
    {"Beauty and the Beast","Call me by your Name","The Shape of Water","Fifty Shades Darker","Phantom Thread"},
    {"Fifty Shades Freed","The Ballad of Buster Scruggs","Mamma Mia","The Matchmaker's Playbook","A Star is Born"},
    {"After","Five Feet Apart","Little Women","Aladdin","The King"},
    {"Love in the Time of Corona","To All the Boys","I Still Love You","The Prom","Holidate"},
    {"Two of Us","I'm Your Man","I Carry You With Me","Licorice Pizza","Supernova"},
    {"Where the Crawdads Sing","Thor: Love and Thunder","Bones and All","Purple Hearts","Three Thousand Years of Longing"}},
};

int len1 = size(movieList);
int len2 = size(movieList[0]);
int len3 = size(movieList[0][0]);
int genreChoice, yearChoice;

void genreScreen();
void yearScreen(string movieGenre);
void showTopMovie(string movieGenre, string movieYear);

int main(){
    genreScreen();
}

void genreScreen(){
    system("cls");
    cout << "***** Top 5 Movie List *****\n" << endl;
    cout << "[0] Action\n[1] Animated\n[2] Drama\n[3] Horror\n[4] Romance\n[9] Exit\n>> ";
    cin >> genreChoice;
    cout << endl;

    string movieGenre;

    if (genreChoice == 0){
        movieGenre = "Action";
    } else if (genreChoice == 1){
        movieGenre = "Animated";
    } else if (genreChoice == 2){
        movieGenre = "Drama";
    } else if (genreChoice == 3){
        movieGenre = "Horror";
    } else if (genreChoice == 4){
        movieGenre = "Romance";
    } else if (genreChoice == 9){
        system("cls");
        exit(0);
    }
    yearScreen(movieGenre);
}

void yearScreen(string movieGenre){
    system("cls");
    cout << "----- " << movieGenre << " Movies by Year -----" << endl;
    cout << "[0] 2016\n[1] 2017\n[2] 2018\n[3] 2019\n[4] 2020\n[5] 2021\n[6] 2022\n[9] Back\n>> ";
    cin >> yearChoice;

    string movieYear;

    if (yearChoice == 0){
        movieYear = "2016";
    } else if (yearChoice == 1){
        movieYear = "2017";
    } else if (yearChoice == 2){
        movieYear = "2018";
    } else if (yearChoice == 3){
        movieYear = "2019";
    } else if (yearChoice == 4){
        movieYear = "2020";
    } else if (yearChoice == 5){
        movieYear = "2021";
    } else if (yearChoice == 6){
        movieYear = "2022";
    } else if (yearChoice == 9){
        genreScreen();
    }
    showTopMovie(movieGenre, movieYear);
}

void showTopMovie(string movieGenre, string movieYear){
    system("cls");
    cout << "----- Top 5 " << movieGenre << " Movies in " << movieYear << " -----" << endl;
    
    int num = 0;
    for (int k = 0; k < len3; k++){
        num = k;
        num++;
        cout << num << ". " << movieList[genreChoice][yearChoice][k] << endl;
    }

    cout << endl;
    system("pause");
    genreScreen();
}