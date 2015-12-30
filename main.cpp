#include "header.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


position codeposition(int mom, int edge)
{
    position act;
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            act.r[i]+=z[i][j];
            act.r[i]*=4;
        }
    act.mother = mom;
    act.edge = edge;
    return act;
}

void countposition(position act)
{
    int counter = 0;
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            act.r[i]/=4;
            if(act.r[i]%4 == s)
                counter++;
        }
    return counter;
}

void decodeposition(position act)
{
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            act.r[i]/=4;
            z[i][j] = act.r[i]%4;
        }
}

void init()
{
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            if(!(i+j%2))
                if(i<3)
                    z[i][j]=blk_p;
                else
                    z[i][j]=blk_e;
            else
                if(i>4)
                    z[i][j]=wht_p;
                else
                    z[i][j]=wht_e;
}

bool check(where loc)
{
    if(loc.j2>7 || loc.j2<0 || loc.i2>7 || loc.i2<0 || loc.j1>7 || loc.j1<0 || loc.i1>7 || loc.i1<0) return 0;
    if(z[loc.i1][loc.j1] < 2) return 0;
    if(abs(loc.i1-loc.i2) == 1 && abs(loc.j1-loc.j2) == 1) return 1;
    if(abs(loc.i1-loc.i2) == 2 && abs(loc.j1-loc.j2) == 2)
        if(z[(loc.i1+loc.i2)/2][(loc.j1+loc.j2)/2] == !who)
        {
            loc.f=1;
            loc.fi=(loc.i1+loc.i2)/2;
            loc.fj=(loc.j1+loc.j2)/2;
            return 1;
        }
    actmove = loc;
    return 0;
}

void run()
{
    if(!actmove.f)
    {
        z[actmove.i2][actmove.j2] = z[actmove.i1][actmove.j1];
        z[actmove.i1][actmove.j1] = who;
    }
    else
    {
        z[actmove.i2][actmove.j2] = z[actmove.i1][actmove.j1];
        z[actmove.i1][actmove.j1] = who;
        z[actmove.fi][actmove.fj] = !who+1;
    }
}

void mrun()
{
    if(!actmove.f)
    {
        z[actmove.i1][actmove.j1] = z[actmove.i2][actmove.j2];
        z[actmove.i2][actmove.j2] = who;
    }
    else
    {
        z[actmove.i1][actmove.j1] = z[actmove.i2][actmove.j2];
        z[actmove.i2][actmove.j2] = who;
        z[actmove.fi][actmove.fj] = !who;
    }
}

bool mv(int player)
{
    w1 = false;
    w2 = false;
    if(player == s)
    {
        ask();
        run();
    }
    else AI();

    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            if(z[i][j] == wht) w1 = true;
            if(z[i][j] == blk) w2 = true;
        }
    if(w1 && w2) return false;
    return true;
}

void mainloop()
{
    while(1)
    {
        showscreen();
        ifwin = mv(who);
        if(ifwin) return;
        round++;
        who = !who;
    }
}

int main()
{
    hello();
    init();
    mainloop();
    bye();
    return 0;
}
