/*
 *  vehicle.h
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



#ifndef _COSC052_FALL2018_P2_VEHICLE_H_
#define _COSC052_FALL2018_P2_VEHICLE_H_



#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <exception>
#include <cstdlib>

#include "DateTime.h"

using std::string;
using std::invalid_argument;
using std::logic_error;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;
using std::ostringstream;
using std::istringstream;



const int DERIVED_CLASS_COUNT = 3;
const int STATUS_CODE_COUNT = 3;
const int ID_REQUIRED_LENGTH = 17;

enum DerivedNames { _INDIVIDUAL_, _PASSENGER_, _CARGO_ };
enum StatusNames { _IN_MAINTENANCE_, _IN_SERVICE_, _AVAILABLE_ };

const char TYPE_CODES[DERIVED_CLASS_COUNT + 1] = {'i', 'p', 'c', '\0'};
const char STATUS_CODES[STATUS_CODE_COUNT + 1] = {'m', 's', 'a', '\0'};



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Vehicle declaration                              **
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
 * <P>The <code>Vehicle</code> class.</P>
 *
 * <P>This base class stores information common to all vehicle objects:</P>
 * <OL>
 *     <LI>id - identification number</LI>
 *     <LI>name - make and model</LI>
 *     <LI>inspectionDate - last safety inspection </LI>
 *     <LI>status - current status (in service, in maintenance, available)</LI>
 * </OL>
 *
 * @author W. A. Woods (waw23 at georgetown dot edu)
 * @version 1.1, 2018/09/23
 * @version 1.2, 2018/09/24
 * @version 1.3, 2018/09/26
 *
 */

class Vehicle
{
protected:
    string id;            /*!< Vehicle Identification Number (VIN) (with vehicle type prefix) */
    string name;          /*!< vehicle make and model */
    Date inspectionDate;  /*!< last comprehensive mechanical, operational, safety inspection */
    char status;          /*!< code indicating current status/available */
    
    
public:
    Vehicle();
    Vehicle( string id, string name, Date iDate, char status ) throw ( invalid_argument );
    
    string getID() const{return id;}
    string getName() const{return name;}
    Date getInspectionDate() const{return inspectionDate;}
    char getStatus() const{return status;}
    
    void setID( string id ) throw ( invalid_argument );
    void setName( string name ){this-> name = name;}
    void setInspectionDate( Date iDate ) throw ( invalid_argument );
    void setStatus( char status ) throw ( invalid_argument );
    
    bool readDoubleQuotedString( istream&, string& ) throw (logic_error, invalid_argument);

    virtual void print( ostream& os = cout ) const throw ( invalid_argument );
    virtual void read( istream& is ) throw ( invalid_argument, logic_error );
    
    virtual ~Vehicle(){;}
    
}; // END Vehicle class declaration



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Individual declaration                           **
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
 * <P>The <code>Individaul</code> class.</P>
 *
 * <P>This class for stores information about an <code>Individual</code> vehicle defined
 * as a vehicle for personal, family, or small group use (maximum of 6 passengers).</P>
 *
 * <P>The <code>Individual</code> class inherits all of its members from the <code>Vehicle</code>
 * base class only constructors are added and these use member initialization lists to call
 * the base class constructor to initialize all data members.</P>
 *
 * @author W. A. Woods (waw23 at georgetown dot edu)
 * @version 1.1, 2018/09/23
 * @version 1.2, 2018/09/24
 * @version 1.3, 2018/09/26
 *
 */

class Individual : public Vehicle
{
public:
    
    Individual();
    Individual(string id, string name, Date inspectionDate, char status);
    
}; // END class Individual declaration



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Passenger declaration                            **
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
 * <P>The <code>Passenger</code> class.</P>
 *
 * <P>This class for stores information about an <code>Passenger</code> vehicle defined
 * as a vehicle for transporting medium to large numbers of persons
 * (7 to 40 or more passemgers).</P>
 *
 * <P>The <code>Passenger</code> class adds a data member to store the maximum passenger
 * capacity.  It also adds accessor and mutator functions associated
 * with the new data member, as well as overriding the inherited print and read
 * methods.  Its default constructor and constructor with parameters are expected to call
 * the appropriated parent class constructor and pass applicable arguments
 * to initialize inherited data members.</P>
 *
 * @author W. A. Woods (waw23 at georgetown dot edu)
 * @version 1.1, 2018/09/23
 * @version 1.2, 2018/09/24
 * @version 1.3, 2018/09/26
 *
 */

class Passenger : public Vehicle
{
private:
    
    int capacity; /*!< maximum passenger transport capacity */
    
public:
    
    Passenger();
    Passenger(string id, string name, Date inspectionDate, char status, int cap);
    
    int getCapacity() const{return capacity;}
    
    void setCapacity(int cap);

    virtual void print( ostream& os = cout ) const throw ( invalid_argument );
    virtual void read( istream& is ) throw ( invalid_argument );
    
}; // END class Passenger declaration



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Cargo declaration                                **
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
 * <P>The <code>Cargo</code> class.</P>
 *
 * <P>This class for stores information about a <code>Cargo</code> vehicle defined
 * as a truck or van for hauling medium to heavy cargo.</P>
 *
 * <P>The <code>Cargo</code> class adds a data member to store the maximum payload
 * capacity.  It also adds accessor and mutator functions associated
 * with the new data member, as well as overriding the inherited print and read
 * methods.  Its default constructor and constructor with parameters are expected to call
 * the appropriated parent class constructor and pass applicable arguments
 * to initialize inherited data members.</P>
 *
 * @author W. A. Woods (waw23 at georgetown dot edu)
 * @version 1.1, 2018/09/23
 * @version 1.2, 2018/09/24
 * @version 1.3, 2018/09/26
 *
 */

class Cargo : public Vehicle
{
private:
    
    double capacity;  /*!< maximum payload hauling capacity (in tons) */
    
public:
    
    Cargo();
    Cargo(string id, string name, Date inspectionDate, char status, double cap);
    
    double getCapacity() const{return capacity;}
    
    void setCapacity(double cap);
    
    virtual void print( ostream& os = cout ) const throw ( invalid_argument );
    virtual void read( istream& is ) throw ( invalid_argument );
    
}; // END class Cargo declaration








#endif /*  _COSC052_FALL2018_P2_VEHICLE_H_  */
