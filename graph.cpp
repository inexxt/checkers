#include "header.h"

void out(int k)
{
    switch(k)
    {
        case wht_p: cout << "@";
                break;
        case blk_p: cout << "H";
                break;
        case wht_e: cout << "O";
                break;
        case blk_e: cout << " ";
                break;
    }
}

void showscreen()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
            out(z[i][j])
        cout << "\n";
    }
    cout << "\n\n\n";
}
