//8 Queens 2D array problem with goto and backtracking

#include <iostream>
using namespace std;

int main()
{
    int b[8][8]{}, r = 0, c = 0;
    b[0][0] = 1;

    nc:
        c++;
        if(c == 8)
        {
            goto print;
        }
        r = -1;
    nr:
        r++;
        if(r == 8)
        {
            goto backtrack;
        }

    //row test
    for(int i = 0; i < c; i++)
    {
        if(b[r][i] == 1)
        {
            goto nr;
        }
    }

    //up diagonal test
    for(int i = 1; ((r-i) >= 0 && (c-i) >= 0); i++)
    {
        if(b[r-i][c-i] == 1)
        {
            goto nr;
        }
    }

    //down diagonal test
    for(int i = 1; ((r+i) < 8 && (c-i) >= 0); i++)
    {
        if(b[r+i][c-i] == 1)
        {
            goto nr;
        }
    }

    b[r][c] = 1;
    goto nc;

    backtrack:
        //go to last the queen position for that decrement c by 1 and assign r = 0. and look for queen
        c--;
        if(r == -1)
        {
            cout << "No more solution." << endl;
            return 0;
        }
        r = 0;
        while(b[r][c] != 1)
        {
            r++;
        }
        b[r][c] = 0; // when we find the queen just removed it
        goto nr;

    print:
        static int count = 0;
        cout << "Solution no #" << ++count <<":"<< endl;

        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        goto backtrack;

}
