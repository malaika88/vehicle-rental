/*
 *  vehicleLog.h
 *
 *  COSC 052 Fall 2018
 *  Project #2
 *
 *  Due on: OCT 11, 2018
 *  Author: mmn60
 *
 *
 *  In accordance with the class policies and Georgetown's
 *  Honor Code, I certify that, with the exception of the
 *  class resources and those items noted below, I have neither
 *  given nor received any assistance on this project.
 *
 *  References not otherwise commented within the program source code.
 *  Note that you should not mention any help from the TAs, the professor,
 *  or any code taken from the class textbooks.
 */



#ifndef _COSC052_FALL2018_P2_VEHICLE_LOG_H_
#define _COSC052_FALL2018_P2_VEHICLE_LOG_H_



#include <iostream>
#include <vector>
#include "vehicle.h"
#include "exceptions.h"
#include <fstream>

using std::vector;


/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class VehicleLog declaration                           **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Fall 2018 to use in                        **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

/**
 * <P>The <code>VehicleLog</code> class.</P>
 *
 * <P>This class stores information about <code>Individaul</code>, <code>Passenger</code>, and
 * <code>Cargo</code> objects derived from the Vehicle class.</P>
 *
 * <P>Its vehicles vector data member is defined to store pointers to
 * the base class (<code>Vehicle</code>) objects.  We shall store addresses
 * of derived objects in this vector's elements.</P> 
 *
 * <P>Class <code>VectorLog</code> provides
 * methods for destructing, reading, printing, and totaling
 * object capacities (if applicable).</P>
 *
 * @author W. A. Woods (waw23 at georgetown dot edu)
 * @version 1.1, 2018/09/24
 * @version 1.2, 2018/09/25
 * @version 1.3, 2018/09/26
 *
 */

class VehicleLog
{
private:
    
    vector<Vehicle*> vehicles; /*!< the vehicles for this log */
  
public:
    
    VehicleLog(){;}
    
    int getTotalPassengerCapacity() const;
    double getTotalCargoCapacity() const;
    
    void print( ostream& os = cout ) const throw (invalid_argument);
    void read( string fileName ) throw ( invalid_argument, bad_vehicle_code );
    
    /** accessor method returns size of vector data member, implemented in-line  */
    unsigned long size() const { return vehicles.size(); }
    
    /** mutator method returns a reference to the object whose pointer is stored at index "ndx"
     within the vector data member, implemented in-line  */
    Vehicle &at(unsigned long ndx) { return *(vehicles.at(ndx)); }
    
    ~VehicleLog();
    
}; // END class VehicleLog



#endif /*  _COSC052_FALL2018_P2_VEHICLE_LOG_H_  */
