#ifndef AI_H
#define AI_H

class AI
{
public:
    AI();
    int action(const int time, const int HP);
private:
    int mode,stage,count,time_count;
};

#endif // AI_H
