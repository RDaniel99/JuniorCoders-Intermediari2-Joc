#include "smartbot.h"

SmartBot::SmartBot() {}

SmartBot::SmartBot(string name, int color, Board* board) {

    setName(name);
    setColor(color);
    setBoard(board);
}

bool SmartBot::makeMove() {

    int nroisp = this->board->numberOfIsolatedPoints();

    vector <Point> points = this->board->getPoints();

    for (int i = 0; i <= points.size() - 2; i++) {

        for (int j = i + 1; j <= points.size() - 1; j++) {

            if (points[i].getStatus() == Point::Status::FREE &&
                points[j].getStatus() == Point::Status::FREE &&
                this->board->canUnion(points[i], points[j])) {

                Segment segment(points[i], points[j]);
                this->board->addSegment(segment);

                int NROISP = this->board->numberOfIsolatedPoints();

                if ((nroisp % 2 == 1 or nroisp == 0) and NROISP > nroisp) {

                    this->board->markPoint(i, Point::Status::BLOCKED);
                    this->board->markPoint(j, Point::Status::BLOCKED);

                    points[i].Paint(getColor());
                    points[j].Paint(getColor());

                    segment.Paint(getColor());
                    return true;
                }

                else if ((nroisp % 2 == 1 or nroisp == 0) and NROISP == nroisp) {

                    this->board->popSegment();
                }

                else if (nroisp != 0 and nroisp % 2 == 0 and nroisp == NROISP) {

                    this->board->markPoint(i, Point::Status::BLOCKED);
                    this->board->markPoint(j, Point::Status::BLOCKED);

                    points[i].Paint(getColor());
                    points[j].Paint(getColor());

                    segment.Paint(getColor());
                    return true;
                }

                else if (nroisp != 0 and nroisp % 2 == 0 and nroisp == NROISP) {

                    this->board->popSegment();
                }
            }
        }
    }
    // if the bot can t make any favorable moves, he ll just make a random move

    for(int i = 0; i < points.size() - 1; i++) {

        for (int j = i + 1; j < points.size(); j++) {

            if (points[i].getStatus() == Point::Status::FREE and
                points[j].getStatus() == Point::Status::FREE and
                this->board->canUnion(points[i], points[j])) {

                this->board->markPoint(i, Point::Status::BLOCKED);
                this->board->markPoint(j, Point::Status::BLOCKED);

                points[i].Paint(getColor());
                points[j].Paint(getColor());

                Segment segment(points[i], points[j]);
                this->board->addSegment(segment);
                segment.Paint(getcolor());
                return true;
            }
        }
    }

    return false;

}
