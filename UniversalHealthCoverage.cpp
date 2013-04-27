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

bool doesLocationCombinationCoverCities(Set<string> cities,
                                        Vector< Set<string> >& result);

bool assertEquals(bool expected, bool actual) {
    if (expected == actual) {
        return true;
    } else {
        cout << "Expected: " << expected << "; Actual: " << actual << endl;
        return false;
    }
}

void testDoesLocationCombinationCoverCities() {
    Set<string> cities1;
    cities1 += "A", "B", "C", "D", "E", "F";

    Set<string> hospital1;
    hospital1 += "A", "B", "C";

    Set<string> hospital2;
    hospital2 += "A", "C", "D";

    Set<string> hospital3;
    hospital3 += "C", "E", "F";

    Vector< Set<string> > locationCombination;
    locationCombination.add(hospital1);
    locationCombination.add(hospital2);
    locationCombination.add(hospital3);

    assertEquals(true, doesLocationCombinationCoverCities(cities1,
                                                         locationCombination));
    Set<string> cities2;
    cities2 += "A", "B", "C", "D", "E", "F";
    
    Set<string> hospitalA1;
    hospitalA1 += "A", "B", "C";
    
    Set<string> hospitalA2;
    hospitalA2 += "A", "C", "D";
    
    Set<string> hospitalA3;
    hospitalA3 += "B", "F";
    
    Vector< Set<string> > locationCombination2;
    locationCombination2.add(hospitalA1);
    locationCombination2.add(hospitalA2);
    locationCombination2.add(hospitalA3);

    assertEquals(false, doesLocationCombinationCoverCities(cities2,
                                                         locationCombination2));
}

void testCanOfferUniversalCoverage() {
    Set<string> cities1;
    cities1 += "A", "B", "C", "D", "E", "F";

    Set<string> hospitalCoverage1;
    hospitalCoverage1 += "A", "B", "C";

    Set<string> hospitalCoverage2;
    hospitalCoverage2 += "A", "C", "D";

    Set<string> hospitalCoverage3;
    hospitalCoverage3 += "C", "E", "F";

    Vector< Set<string> > locations1;
    locations1.add(hospitalCoverage1);
    locations1.add(hospitalCoverage2);
    locations1.add(hospitalCoverage3);

    Vector< Set<string> > result1;
    
    assertEquals(true, canOfferUniversalCoverage(cities1,
                              locations1,
                              3,
                              result1));
}

void runTests() {
    testDoesLocationCombinationCoverCities();
    testCanOfferUniversalCoverage();
}

bool doesLocationCombinationCoverCities(Set<string> cities,
                                        Vector< Set<string> >& result) {
    if (cities.size() == 0) {
        // Base Case: Cities is empty; All cities covered
        return true;
    } else if (result.size() == 0) {
        // Base Case: All hospital locations taken into account
        return false;
    } else {
        Set<string> firstHospitalCoverage = result[0];
        result.remove(0);
        Set<string> uncoveredCities = cities - firstHospitalCoverage;
        return doesLocationCombinationCoverCities(uncoveredCities, result);
    }
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
        result.clear();
        return false;
    } else {
        Set<string> firstLocation = locations[0];
        Vector< Set<string> > combination = result;
        combination.add(firstLocation);
        locations.remove(0);
        canOfferUniversalCoverage(cities, locations, numHospitals, combination);
        
        canOfferUniversalCoverage(cities, locations, numHospitals, result);
    }

    // STEP 2: Clear() $result and return false
    result.clear();
    return false;
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

int main() {
    runTests();
    return 0;
}