#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player(int color);

        int getColor() const;


    private:
        int color;
};

#endif // PLAYER_H

