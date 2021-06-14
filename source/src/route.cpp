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
    int used[sz];
    int pos = 0;
    int positives = 0;
    for (int i = 0; i < sz; i++) 
    {
        used[i] = -1;
    }

    std::string value = start;

    std::cout << "Start: " << start <<std::endl;

    std::cout << "rotas: " << std::endl;

    for(int i = 0; i < sz; i++) {
        std::cout << "origem: " << segs[i].orig << " destino: " << segs[i].dest << std::endl;
    }

    

    // Empty route.
    std::ostringstream route{""}; // Stores the airports that compose the route.

    if(sz == 1) 
    {
        route << segs[0].orig;
        route << " " << segs[0].dest;
        std::cout << route.str() << std::endl;
        return route.str() ;
    }

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
    if(positives < sz) {
        return "null";
    }

    std::cout << route.str() << std::endl;


    return route.str() ; // Stub: replace this return as you see fit.
}