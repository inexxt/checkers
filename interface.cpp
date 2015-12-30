#include "header.h"

void ask()
{
    where inow;
    do
    {
        cout << "Which pawn do you chose? [x,y]\n";
        cin >> inw.j1 >> inw.i1;
        inw.j1=inw.j1%8;
        inw.i1=inw.i1%8;
    }
    while (z[inw.i][inw.j]!=s);

    do
    {
        cout << "Where would you go? [x,y]\n";
        cin >> inw.j2 >> inw.i2;
    while (!check(inow));
}

void hello()
{
    cout << "What's your name?\n";
    cin >> name;
    cout <<"Hi, " << name << ". Would you prefer black or white site? [black/white] \n";
    cin << site;
    s = (site == "black") ? 1 : 0;
}

void bye()
{
    if(round%2) cout << "Winner is white\n";
    else cout << "Winner is black\n";
    if(s==round%2) cout << "Gratz :)"
    else cout << "So sad :<";
}
