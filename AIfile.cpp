#include "header.h"
#include <vector>

/*int trans(position srch)
{
    for(int i=0; i<MAXTABG; i++)
    {
        if(tabg[i] == srch) return i;
    }
}*/

void DFSpawns(int i, int j, int k)
{
    where op;
    op.i1 = i;
    op.j1 = j;
    int b = 0;
    op.i2 = i+1;
    op.j2 = j+1;
    if(check(op))
    {
        run(op);
        b++;
        DFS(op.i2, op.j2, k);
        mrun(op);
    }

    op.i2 = i-1;
    op.j2 = j+1;
    if(check(op))
    {
        run(op);
        b++;
        DFS(op.i2, op.j2, k);
        mrun(op);
    }

    op.i2 = i+1;
    op.j2 = j-1;
    if(check(op))
    {
        run(op);
        b++;
        DFS(op.i2, op.j2, k);
        mrun(op);
    }

    op.i2 = i-1;
    op.j2 = j-1;
    if(check(op))
    {
        run(op);
        b++;
        DFS(op.i2, op.j2, k);
        mrun(op);
    }

    op.i2 = i+2;
    op.j2 = j+2;
    if(check(op))
    {
        run(op);
        b++;
        k++;
        DFS(op.i2, op.j2, k);
        mrun(op);
    }

    op.i2 = i-2;
    op.j2 = j+2;
    if(check(op))
    {
        run(op);
        b++;
        k++;
        DFS(op.i2, op.j2, k);
        mrun(op);
    }

    op.i2 = i+2;
    op.j2 = j-2;
    if(check(op))
    {
        run(op);
        b++;
        k++;
        DFS(op.i2, op.j2, k);
        mrun(op);
    }

    op.i2 = i-2;
    op.j2 = j-2;
    if(check(op))
    {
        run(op);
        b++;
        k++;
        DFS(op.i2, op.j2, k);
        mrun(op);
    }

    if(k>maxk)
    {
        maxk = k;
        maxkpos = codeposition();
    }
    k = (lvl%2) ? k : -k;
    if(!b) v[num].push_back(codeposition(num, k));
}

void DFSpos(int num, int lvl, int mother)
{
    position apdfs = v[num][0];
    //decodeposition(apdfs)

    if(lvl >= MAXLEVELAI)
    {
        vo.push_back(apdfs);
        return;
    }

    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            if( ((!lvl%2) && z[i][j]==s) || ((lvl%2) && z[i][j]!=s)) DFSpawns(i, j, 0);

    for(int i=1; i<v[num].size(); i++)
    {
        NUMPOS++;
        v[NUMPOS][0] = v[num][i];
        v[NUMPOS][0].prize = v[num][0].prize + v[NUMPOS][0].edge;
        DFSpos(NUMPOS, lvl+1, num);
    }
}


void AI()
{
    int NUMPOS = 0;
    v[0][0] = codeposition(0, 0);
    DFSpos(0, 0, 0);

    for(int i=0; i<vo.size(); i++)
    {
        if(vo[i].prize > maxprize)
        {
            maxprize = vo[i].prize;
            bestposition = vo[i];
        }
    }

    for(int i=0; i<lvl-1; i++)
    {
        bestposition = v[bestposition.mother];
    }
    decodeposition(bestposition);
}
