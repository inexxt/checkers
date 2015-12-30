#ifndef header_h
#define header_h

#include <string>

#define MAXLEVELAI 3

#define wht 0
#define blk 1
#define wht_p 0
#define blk_p 1
#define wht_e 2
#define blk_e 3

using namespace std;

string site, name;
int z[8][8];
int s;
int round;

const int MAXTABG = 100000;
struct where
{
    int i1; //from y
    int j1; //from x
    int i2; //where y
    int j2; //where x
    bool f; // if fight
    int fi; //where fight y
    int fj; //where fight x
};

struct position
{
    int r[8];
    int mother;
    int edge;
    int prize;
};

int maxk, NUMPOS;
position maxkpos;
position bestposition;


where actmove;

vector<position> v[MAXTABG];
vector<position> vo[MAXTABG];

//position tabg[MAXTABG];
#endif
