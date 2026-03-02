#include <iostream>
using namespace std;
     
int main()
{
    int limit = 6;
    int counter = 5;
    int starloop = 0;
    for (int k = 0; k < 5; k++)
    {
        for (int i = 1; i <= limit; i++)
        {
            bool visited = false;
            starloop = limit - counter;
            if (i <= counter)
            {
                cout << " ";
            }
            else
            {
                for (int j = starloop; j > 0; j--)
                {
                    cout << "*";
                    visited = true;
                }
            }
            if (visited)
            {
                i = limit + 1;
            }

            if (i == limit || i == limit + 1)
            {
                limit++;
                counter--;
                starloop = 0;
                cout << endl;
            }
        }
    }
}