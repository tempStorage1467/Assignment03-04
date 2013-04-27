/*
 * File: UniversalHealthCoverage.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the UniversalHealthCoverage problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */
#include <iostream>
#include <string>
#include "set.h"
#include "vector.h"
#include "console.h"
using namespace std;

/* Function: canOfferUniversalCoverage(Set<string>& cities,
 *                                     Vector< Set<string> >& locations,
 *                                     int numHospitals,
 *                                     Vector< Set<string> >& result);
 * Usage: if (canOfferUniversalCoverage(cities, locations, 4, result)
 * ==================================================================
 * Given a set of cities, a list of what cities various hospitals can
 * cover, and a number of hospitals, returns whether or not it's
 * possible to provide coverage to all cities with the given number of
 * hospitals.  If so, one specific way to do this is handed back in the
 * result parameter.
 */
bool canOfferUniversalCoverage(Set<string>& cities,
                               Vector< Set<string> >& locations,
                               int numHospitals,
                               Vector< Set<string> >& result);


int main() {
    /* TODO: Add testing code here! */
    return 0;
}

bool doesLocationCombinationCoverCities(Set<string>& cities,
                                        Vector< Set<string> >& result) {
    
}

bool canOfferUniversalCoverage(Set<string>& cities,
                               Vector< Set<string> >& locations,
                               int numHospitals,
                               Vector< Set<string> >& result) {
    // STEP 1: Determine Combinations of Locations <= numHospitals
    //   Iterate over each element in the vector $locations
    //   and determine all combinations;
    //   at each element, only look to the right to generate combinations as
    //   you don't want duplicates
    //   one by one, as each combination is generated, store it in $result,
    //   and evaluate it to determine whether it covers all cities.
    //   This evaluation is done by subtracting recursively from the
    //   combination, stored in $result, involving each element;
    if (doesLocationCombinationCoverCities(cities, result)) {
        return true;
    } else if (locations.size() == 0) {
        return false;
    } else {
        Set<string> firstLocation = locations[0];
        canOfferUniversalCoverage(cities, locations);
    }
    canOfferUniversalCoverage(1, 2)
    
    // take 0th element out of $locations and insert into $result
    //   keep appending into result; this gives 1; 1, 2; 1, 2, 3
    
    // STEP 2: Iteratr Over Groupings of Locations That
    //   Look for a Union function on Sets that does Set subtraction
    //     when locations - cities... recursively look for empty cities


    // STEP 3: Clear() $result and return false
}



//Vector< Vector< Set<string> > > getAllPossibleLocationCombinations() {
//}

//bool canOfferUniversalCoverage(Set<string>& cities,
//                               Vector< Set<string> >& locations,
//                               int numHospitals,
//                               Vector< Set<string> >& result) {
    // STEP 1: Determine Combinations of Locations <= numHospitals
    //   Iterate over each element in the vector and generate all
    //   combinations involving each element; at each element, only
    //   look to the right to generate combinations as
    //   you don't want duplicates
    
    // STEP 2: Iteratr Over Groupings of Locations That
    //   Look for a Union function on Sets that does Set subtraction
    //     when locations - cities... recursively look for empty cities
    
    
    // STEP 3: Clear() $result and return false
//}