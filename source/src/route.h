/*!
 * \file route.h
 */

#ifndef _ROUTE_H_
#define _ROUTE_H_

#include <string>    // std::string
#include <sstream>   // std::ostringstream

/// Pair representing a flight leg.
struct Pair {
    std::string orig; //!< origin airport.
    std::string dest; //!< destination airport.
};


/*!
 * Given a starting airport and a list of flight segments,
 * this function composes and returns a string with the route
 * (sequencial list of airports) from the starting airport
 * passing through all airpors present in the fligh segments,
 * if such a route exists.
 * In case there is no segment with the starting point or one or
 * more segments cannot be part of the route, the function shall
 * return the string `null`.
 * \param start The route's starting airport.
 * \param segs Unordered list of flight legs, called *segments*.
 * \param sz The size of the flight legs list.
 * \return A string with all the airports that compose a route,
 * or the string `null` if it is not possible to establish a route
 * *through all the flight legs provided*.
 */
std::string find_route( const std::string & start , Pair segs[], size_t sz );

#endif
