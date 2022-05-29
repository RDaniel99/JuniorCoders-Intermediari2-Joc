#ifndef H_GAME
#define H_GAME

#include "board.h"
#include "player.h"

class Game {

    public:
        Game();
        void init();
        void changePlayer();
        void play();
    private:
        void initPlayer();
        void initBoard();
        void paintPoints(vector<Point> &points) const;
        pair<int, int> getmouseclick() const;
        int detectClickedPoints() const;

        Board board;
        Player playerOne;
        Player playerTwo;
        Player* currentPlayer;
};
#endif // H_GAME
