#include <iterator>             // std::begin(), std::end()
#include <functional>           // std::function
#include <algorithm>            // std::min_element
#include <iterator>
#include <algorithm>
#include <random>


#include "include/tm/test_manager.h" // TestManager testing framework
#include "../src/route.h"

int main ( void )
{

    // Creates a test manager for the flight tests.
    TestManager tm{ "Testing Flight Route Solution" };

    {
        //=== Test #1
        BEGIN_TEST(tm, "SingleLeg", "Single leg itinerary Ok." );

        Pair segs[]{ {"1","2"} };
        auto segs_sz = sizeof( segs ) / sizeof( segs[0] );

        std::string start{"1"};
        auto route = find_route( start, segs, segs_sz );

        EXPECT_EQ( route, "1 2");
    }

    {
        //=== Test #2
        BEGIN_TEST(tm, "OrderedLeg", "A set of ordered flights." );

        Pair segs[]{ {"1","2"}, {"2","3"}, {"3", "4"}, {"4","5"} };
        auto segs_sz = sizeof( segs ) / sizeof( segs[0] );

        std::string start{"1"};
        auto route = find_route( start, segs, segs_sz );

        EXPECT_EQ( route, "1 2 3 4 5");
    }

    {
        //=== Test #3
        BEGIN_TEST(tm, "ReverseOrderedLeg", "A set of flights in reverse order." );

        Pair segs[]{ {"1","2"}, {"2","3"}, {"3", "4"}, {"4","5"} };
        auto segs_sz = sizeof( segs ) / sizeof( segs[0] );
        // Reverse order.
        std::reverse( std::begin(segs), std::end(segs) );

        std::string start{"1"};
        auto route = find_route( start, segs, segs_sz );

        EXPECT_EQ( route, "1 2 3 4 5");
    }

    {
        //=== Test #4
        BEGIN_TEST(tm, "RadomOrderLeg", "A set of flights in random order." );

        Pair segs[]{ {"1","2"}, {"2","3"}, {"3", "4"}, {"4","5"} };
        auto segs_sz = sizeof( segs ) / sizeof( segs[0] );

        // Random order.
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(std::begin(segs), std::end(segs), g );

        std::string start{"1"};
        auto route = find_route( start, segs, segs_sz );

        EXPECT_EQ( route, "1 2 3 4 5");
    }

    {
        //=== Test #5
        BEGIN_TEST(tm, "DuplicateSameOriginAdjacentLeg", "Two adjacent legs have the same origin." );

        Pair segs[]{ {"1","2"}, {"2","3"}, {"2","9"}, {"3", "4"}, {"4","5"}, {"5", "2"} };
        auto segs_sz = sizeof( segs ) / sizeof( segs[0] );

        std::string start{"1"};
        auto route = find_route( start, segs, segs_sz );

        EXPECT_EQ( route, "1 2 3 4 5 2 9");
    }

    {
        //=== Test #6
        BEGIN_TEST(tm, "DuplicateSameOriginNonAdjacentLeg", "Two non-adjacent legs have the same origin." );

        Pair segs[]{ {"1","2"}, {"2","9"}, {"3", "4"}, {"4","5"}, {"2","3"}, {"5", "2"} };
        auto segs_sz = sizeof( segs ) / sizeof( segs[0] );

        std::string start{"1"};
        auto route = find_route( start, segs, segs_sz );

        EXPECT_EQ( route, "1 2 3 4 5 2 9");
    }

    {
        //=== Test #7
        BEGIN_TEST(tm, "NoLegNoRoute", "Input has no flights." );

        Pair segs[]{  };
        auto segs_sz = sizeof( segs ) / sizeof( segs[0] );

        std::string start{"1"};
        auto route = find_route( start, segs, segs_sz );

        EXPECT_EQ( route, "null");
    }

    {
        //=== Test #7
        BEGIN_TEST(tm, "SingleLegNoOriginPresent", "Single flight, specified origin not present." );

        Pair segs[]{ {"1","2"} };
        auto segs_sz = sizeof( segs ) / sizeof( segs[0] );

        std::string start{"3"};
        auto route = find_route( start, segs, segs_sz );

        EXPECT_EQ( route, "null");
    }

    {
        //=== Test #8
        BEGIN_TEST(tm, "MultiplLegsNoOriginPresent", "Multiple flights, specified origin not present." );

        Pair segs[]{ {"1","2"}, {"2","9"}, {"3", "4"}, {"4","5"}, {"2","3"}, {"5", "2"} };
        auto segs_sz = sizeof( segs ) / sizeof( segs[0] );

        std::string start{"10"};
        auto route = find_route( start, segs, segs_sz );

        EXPECT_EQ( route, "null");
    }

    {
        //=== Test #9
        BEGIN_TEST(tm, "MultiplLegsNoRoute", "Multiple flights but route misses one leg." );

        Pair segs[]{ {"1","2"}, {"2","9"}, {"3", "4"}, {"4","5"}, {"2","3"}, {"5", "3"} };
        auto segs_sz = sizeof( segs ) / sizeof( segs[0] );

        std::string start{"1"};
        auto route = find_route( start, segs, segs_sz );

        EXPECT_EQ( route, "null");
    }

    {
        //=== Test #10
        BEGIN_TEST(tm, "TwoRoutes", "Find the lexicographically smallest route between two possible routes." );

        Pair segs[]{ {"1","2"}, {"1","4"}, {"2","4"}, {"4", "1"} };
        auto segs_sz = sizeof( segs ) / sizeof( segs[0] );

        std::string start{"1"};
        // Rotate the legs around so we test different leg sequences.
        for ( auto i{0} ; i<3 ; ++i ) {
            // simple rotation to the left
            std::rotate( std::begin(segs), std::begin(segs) + 1, std::end(segs) );
            auto route = find_route( start, segs, segs_sz );
            EXPECT_EQ( route, "1 2 4 1 4");
        }
        // Alternative route is:
        // EXPECT_EQ( route, "1 4 1 2 4");
    }

    tm.summary();
}
