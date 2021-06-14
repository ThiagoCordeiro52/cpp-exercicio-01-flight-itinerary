/*!
 * \file route.cpp
 */

#include <string>    // std::string
#include <sstream>   // std::ostringstream
#include <iostream>
#include <string.h>

#include "route.h"

std::string find_route( const std::string & start, Pair segs[], size_t sz )
{
    // TODO: Add your solution here.
    int doBreak = 0;
    int valueOne = -1;
    int valueTwo = -1;
    int used[sz];
    int pos = 0;
    int positions[sz];
    int positives = 0;
    for (int i = 0; i < sz; i++) 
    {
        used[i] = -1;
        positions[i] = -1;
    }

    std::string value = start;

    // Empty route.
    std::ostringstream route{""}; // Stores the airports that compose the route.

    for (int j = 0; j < sz; j++) 
    {
        for(int i = 0; i < sz; i++)
        {
            doBreak = 0;
            for (int z = 0; z < sz; z++) 
            {
                if(i == used[z]) {
                    doBreak = 1;
                    break;
                }
            }

            if(segs[i].orig == value && doBreak == 0) 
            {
                for(int w = i + 1; w < sz; w++) {

                    doBreak = 0;
                    for (int z = 0; z < sz; z++) 
                    {
                        if(w == used[z]) {
                            doBreak = 1;
                            break;
                        }
                    }

                    if(segs[w].orig == value && doBreak == 0 && segs[w].dest < segs[i].dest) {
                        i = w;
                    } 
                }

                route << value << " ";
                value = segs[i].dest;
                used[pos] = i;
                pos++;
                break;
            }
        }

    }
    route << value;

    for (int i = 0; i < sz; i++) {
        if(used[i] >= 0) {
            positives += 1;
        }
    }

    if(positives < sz || sz == 0) {
        return "null";
    }

    return route.str() ; // Stub: replace this return as you see fit.
}