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
            if(segs[i].orig == value) 
            {
                route << value << " ";
                value = segs[i].dest;
                break;
            }
        }    
    }

    route << value;

    std::cout << route.str() << std::endl;

    return route.str() ; // Stub: replace this return as you see fit.
}
