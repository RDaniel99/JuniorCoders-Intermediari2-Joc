#ifndef H_SMART_BOT
#define H_SMART_BOT

#include "player.h"

class SmartBot: public Player {

public:
    SmartBot();
    SmartBot(string name, int color, Board* board);
    bool makeMove();
};

#endif // H_SMART_PLAYER
