/*
 * File: UniversalHealthCoverage.cpp
 * ----------------------
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 3 - Pt. 4 - Universal Health Care
 */
#include <iostream>
#include <string>
#include <vector>
#include "set.h"
#include "vector.h"
#include "console.h"
using namespace std;

////////// FUNCTION PROTOTYPES //////////

/*
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
                                        Vector< Set<string> > result);

bool assertEquals(bool expected, bool actual);
bool assertEquals(Vector<Set<string> > expected, Vector<Set<string> > actual);
void testDoesLocationCombinationCoverCities();
void testCanOfferUniversalCoverage();
void runTests();

////////// FUNCTION IMPLEMENTATION //////////

bool doesLocationCombinationCoverCities(Set<string> cities,
                                        Vector< Set<string> > result) {
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

/* Recursively lists off all combinations of k elements from the master
 * set s, under the assumption we've already built up the partial set
 * soFar.
 */
bool recListCombinationsOf(Vector<Set<string> > s,
                           int k,
                           Vector<Set<string> > soFar,
                           Set<string>& cities,
                           Vector< Set<string> >& result) {
	if (k == 0) {
        /* Base case 1: If there are no more elements to pick, output
         * what we have so far.
         */
        if (doesLocationCombinationCoverCities(cities, soFar)) {
            result = soFar;
            return true;
        }
	} else if (k != 0 && k <= s.size()) {
		/* Pick some element from the set. */
		Set<string> elem = s[0];
        Vector<Set<string> > soFarAdjusted = soFar;
        soFarAdjusted.add(elem);
        
		/* Option 1: Pick this element. Then we need k - 1 elements from
		 * the remainder of the set.
		 */
        Vector<Set<string> > sPruned = s;
        sPruned.remove(0);
		if (recListCombinationsOf(sPruned, k - 1,
                                  soFarAdjusted,
                                  cities,
                                  result)) {
            return true;
        }
        
		/* Option 2: Don't pick this element. Then we need k elements from
		 * the remainder of the set.
		 */
		if (recListCombinationsOf(sPruned,
                                  k,
                                  soFar,
                                  cities,
                                  result)) {
            return true;
        }
	}
}

bool canOfferUniversalCoverage(Set<string>& cities,
                               Vector< Set<string> >& locations,
                               int numHospitals,
                               Vector< Set<string> >& result) {
    
    Vector<Set<string> > emptySet;
    // Start at 1 so we find the most efficient solution first and stop then
    for (int i = 1; i <= numHospitals; i++) {
        if (recListCombinationsOf(locations, i, emptySet, cities, result)) {
            return true;
        }
    }
    return false;
}

int main() {
    runTests();
    return 0;
}

////////// UNIT TESTS //////////

bool assertEquals(bool expected, bool actual) {
    if (expected == actual) {
        return true;
    } else {
        cout << "Expected: " << expected << "; Actual: " << actual << endl;
        return false;
    }
}

bool assertEquals(Vector<Set<string> > expected, Vector<Set<string> > actual) {
    if (expected.size() != actual.size()) {
        cout << "Unequal Vectors" << endl;
        return false;
    }
    for (int i = 0; i < expected.size(); i++) {
        if (expected[i] != actual[i]) {
            cout << "Vector " << i << " is unequal" << endl;
            return false;
        }
    }
    return true;
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
    hospitalCoverage3 += "B", "F";
    
    Set<string> hospitalCoverage4;
    hospitalCoverage4 += "C", "E", "F";
    
    Vector< Set<string> > locations1;
    locations1.add(hospitalCoverage1);
    locations1.add(hospitalCoverage2);
    locations1.add(hospitalCoverage3);
    locations1.add(hospitalCoverage4);
    
    Vector< Set<string> > result1;
    
    assertEquals(true, canOfferUniversalCoverage(cities1,
                                                 locations1,
                                                 3,
                                                 result1));
    
    assertEquals(false, canOfferUniversalCoverage(cities1,
                                                  locations1,
                                                  2,
                                                  result1));
    
}

void runTests() {
    testDoesLocationCombinationCoverCities();
    testCanOfferUniversalCoverage();
}
