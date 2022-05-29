#include "game.h"
#include "config.h"
#include "generator.h"

#include <iostream>

using namespace std;

Game::Game() {}

void Game::changePlayer() {
    if(this -> currentPlayer == &this -> playerOne){
        this -> currentPlayer = &this -> playerTwo;
    }
    else {
        this -> currentPlayer = &this -> playerOne;
    }
}


void Game::play(){

    while(this -> board.existSolution()){
        int firstClickedPoint = detectClickedPoints();
        if(firstClickedPoint == -1) continue;
        if(this-> board.getPointStatus(firstClickedPoint) == Point::status::BLOCKED){

            cout << "Point selected before.\n";
            continue;
        }
        cout << "Mark point (" << firstClickedPoint <<") as selected.\n";

        this -> board.markPoint(firstClickedPoint, Point::status::SELECTED)
        this -> board.getPoints()[firstClickedPoint].paint(this -> currentPlayer -> getcolor());

        int secondClickedPoints = detectClickedPoints();
        while(secondClickedPoints == -1){
            secondClickedPoints = detectClickedPoints();
        }
        cout <<"Detected second point: " << secondClickedPoints <<'\n';
        cout <<"Status second:" << this -> board.getPointStatus(secondClickedPoints) <<'\n';

        if(this -> board.getPointStatus(secondClickedPoints) == Point::status:FREE)
        if(!this -> board.canUnion(this -> board.getPoints()[firstClickedPoint], this -> board.getPoints()[secondClickedPoints])){

            cout <<"Segment intersects  with another segments. Unmark points\n";
            this -> board.markPoint(firstClickedPoint, Point::status::FREE)
            this -> board.getPoints()[firstClickedPoint].paint();
                continue;
        }
         cout << "Nice. You picked a good pair\n";

         this -> board.markPoint(firstClickedPoint, Point::status::BLOCKED);
         this -> board.markPoint(secondClickedPointsClickedPoint, Point::status::BLOCKED);

         this -> board.getPoints()[secondClickedPoints].paint(this -> currentPlayer -> getcolor());
            Segment segment(this -> board. getPoints()[firstClickedPoint], this -> board. getPoints()[secondClickedPoints]);
            this -> board.addSegment(segment);
            segment.paint(this -> currentPlayer -> getcolor());
            changePlayer();
            continue;
    }
     if(this -> board.getPointStatus(secondClickedPoints) == Point::status::SELECTED) {

            cout << "Unmark selected point\n";
            this->board.markPoint(secondClickedPoints, Point::status::FREE);

            this->board.getPoints()[secondClickedPoints].paint();
            continue;

          cout << "Selected point was already blocked. Unblocking first point\n";
        this->board.markPoint(firstClickedPoint, Point::status::FREE);
        this->board.getPoints()[firstClickedPoint].paint();
    }

    changePlayer();
    if(this -> currentPlayer == &this -> playerOne){
        cout << "PLAYER ONE WINS!\n";
    else cout << "PLAYER TWO WINS!\n";
    }
}
int Game::detectClickedPoints() const {
    pair<int, int> mouseclick = getmouseclick;
     for(unsigned int index = 0; index < this ->  board.getPoints().size(); index++) {
        Point point = this -> board.getPoints()[index];
     if(point.isClicked(mouseclick.first, mousclick.second)) {
        return index;
     }
    }
    return -1;
}


pair<int, int> Game::getMouseClick() const {

    int x, y;

    do {

        getmouseclick(WM_LBUTTONDOWN, x, y);
    } while(x < 0 && y < 0);

    cout << "Click detected on " << x << ' ' << y << '\n';

    return {x, y};
}


void Game::init() {

    this->initPlayers();
    this->initBoard();
}


void Game::initPlayers() {

    this->playerOne = Player(PLAYER_ONE_NAME, PLAYER_ONE_COLOR);
    this->playerTwo = Player(PLAYER_TWO_NAME, PLAYER_TWO_COLOR);
    this->currentPlayer = &this->playerOne;
}


void Game::initBoard(){
    Generator generator;

    vector<Point> points = generator.generatePoints(DEFAULT_NUMBER_OF_POINTS)
    this -> board = Board(points);
    paintPoints(points);
}


void Game::paintPoints(vector<Point> &points) const {
    for(auto point: points) {
        point.paint();
    }
}
