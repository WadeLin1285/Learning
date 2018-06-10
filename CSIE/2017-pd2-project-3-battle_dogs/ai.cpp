#include "ai.h"

AI::AI()
{
    mode = 0;
    stage = 0;
    count = 0;
    time_count = 0;
}

int AI::action(const int time,const int HP)
{
    time_count++;
    if (mode == 0 && stage == 0 && HP < 1800 && time_count > 70) {
        mode = 1;
        stage = 1;
        time_count = 0;
    }
    if (mode == 0 && stage == 1 && HP < 750 && time_count > 100) {
        mode = 2;
        stage = 2;
        time_count = 0;
    }
    if (stage == 2 && HP < 700 && time_count > 20) mode = 4;

    if (mode == 1) {
        switch (count) {
        case 0:
            count = 1;
            return 7;
            break;
        case 1:
            count = 2;
            return 12;
            break;
        case 2:
            count = 3;
            return 3;
            break;
        case 3:
            count = 0;
            mode = 0;
            return 9;
            break;
        default:
            break;
        }
    }
    else if (mode == 2) {
        switch (count) {
        case 0:
            count = 1;
            return 2;
            break;
        case 1:
            count = 2;
            return 16;
            break;
        case 2:
            count = 3;
            return 5;
            break;
        case 3:
            count = 4;
            return 2;
            break;
        case 4:
            count = 0;
            mode = 0;
            return 18;
            break;
        default:
            break;
        }
    }
    else if (mode == 3) {
        switch (count) {
        case 0:
            count = 1;
            return 16;
            break;
        case 1:
            count = 2;
            return 16;
            break;
        case 2:
            count = 3;
            return 5;
            break;
        case 3:
            count = 4;
            return 2;
            break;
        case 4:
            count = 5;
            return 19;
            break;
        case 5:
            count = 0;
            mode = 0;
            return 20;
            break;
        default:
            break;
        }
    }
    else if (mode == 4){
        if (time % 300 == 0) return 15;
        if (time % 250 == 0) return 11;
        if (time % 150 == 0) return 8;
        if (time %  50 == 0) return 2;
    }
    else {

        if (time % 300 == 0) return 11;
        if (time % 250 == 0) return 16;
        if (time % 150 == 0) return 2;
        if (time %  50 == 0) return 1;
    }
    return 0;
}
