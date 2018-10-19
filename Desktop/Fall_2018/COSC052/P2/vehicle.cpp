/*
 *  vehicle.cpp
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

#include "vehicle.h"

/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Vehicle implementation                           **
 **																		   **
 ****************************************************************************/

Vehicle:: Vehicle()
{
	id = "p0000000000000000";
	name = "none"; 
	inspectionDate = Date (MIN_YYYY, MIN_MM, MIN_DD); 
	status = 'm';

}//END default constructor for Vehicle 

Vehicle :: Vehicle( string id, string name, Date iDate, char status ) throw ( invalid_argument )
{
	setID(id); 
	setName(name); 
	setInspectionDate(iDate);
	setStatus(status); 
}// END constructor w/ parameters for Vehicle 

void Vehicle::setID( string id ) throw ( invalid_argument )
{
	//exactly 17 characters in length
	if (id.length() != 17)
	{
		throw invalid_argument ("Error in setID: id was not exactly 27 characters"); 
	}
	// first character must be valid vechile type code (i,p,c)
	char valid = ' '; 
	istringstream firstStrm(id); 
	firstStrm>>valid;

	valid= tolower(valid);
	if (valid != 'i' && valid != 'c' && valid != 'p')
	{
		throw invalid_argument("Error in setID: first character must be c,i,or p");
	}
	//all characters are alpha-numeric (no special characters)

	for (int i =0; i <id.size(); i++)
	{
		if(!isalpha(id[i]) && !isdigit(id[i]))
		{
			throw invalid_argument("Error in setID: no special characters");
		}
	}
	//set the object id data member 
	this-> id = id; 
}//END setID

void Vehicle:: setInspectionDate( Date iDate ) throw ( invalid_argument )
{
	// call setDate to perform data validation
	inspectionDate.setDate(iDate); 
	//set object's inspectionDate data member
	iDate = inspectionDate;
}//END setInspectionDate

void Vehicle::setStatus( char status ) throw ( invalid_argument )
{
	// must be character m,s,a 
	status=tolower(status);
	if (status != 'm' && status != 's' && status != 'a')
	{
		throw invalid_argument("Error in setStatus: invalid status"); 
	}
	//set object's status data member 
	this->status = status; 
}//END setStatus

 bool Vehicle::readDoubleQuotedString (istream & is, string & s) 
	throw (logic_error, invalid_argument)
{ 
	if (is.fail())
	{
		throw invalid_argument("Error in readDoubleQuotedString: stream not working"); 
	}
	//cout<< " inside Double Quoted String " <<endl;
	char startquotes = ' '; 
	char startquotestrue = '\"'; 
	char endquotes = ' '; 
	char endquotestrue = '\"'; 
	bool valid = false ; 
	
	s = "";

	is >> startquotes;
	//cout << startquotes<<endl;
	if (startquotes == startquotestrue)
	{
		endquotes = is.get(); 
		//cout<< endquotes<<endl;
		while( endquotes != endquotestrue)
		{
			s += endquotes;
			endquotes= is.get();
			//cout<<endquotes<<endl;
			valid= true; 
			
		}
		//cout << s<<endl; 
	}
	if ( valid == false) 
	{
		throw logic_error("Error in readDoubleQuotedString: char is not double quoted string"); 
	}
	return valid; 
}

void Vehicle::print( ostream& os) const throw ( invalid_argument )
{
	//cout << "inside Vehicle::print"<<endl;
	// checks if stream is in failed state 
	if(!os)
	{
		throw invalid_argument("Vehicle::print File did not open. Check file name");
	}
	// outputs all data members to the output stream formatted
	cout<<endl<<endl;
	os << "Vehicle ID: " << id <<endl;
	os<< "Make/Model: " << name <<endl;
	os<< "Last Inspection: "<< inspectionDate<<endl;
	os<< "Current Status: ";
	if(status == 'm'){ os << "In Maintenance";} 
	if (status == 'a'){os<<"Available";}
	if(status == 's'){os<<"In Service";}

}//END Vehicle::print

void Vehicle:: read( istream& is ) throw ( invalid_argument, logic_error )
{
	//cout<< "inside Vehicle::read"<<endl;
	if (!is)
	{
		throw invalid_argument("Vehicle::read File did not open. Check file name"); 
	}
	string i, n; 
	Date d; 
	char s; 

	is >> i; 
	readDoubleQuotedString(is,n);
	is >> d; 
	is >> s; 

	setID(i); 
	setName(n);
	setInspectionDate(d); 
	setStatus(s); 

}//END Vehicle:read

/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Individual declaration                           **
 **                                                                        **
 **																		   **
 ****************************************************************************
 ****************************************************************************/
Individual:: Individual():Vehicle()
{
	//default constructor
}
Individual:: Individual(string id, string n, Date iDate, char s):Vehicle(id,n,iDate,s)
{
	//constructor with parameters 
}


/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Passenger declaration                            **
 **                                                                        **
 **																		   **
 ****************************************************************************
 ****************************************************************************/
Passenger:: Passenger(): Vehicle()
{
	capacity = 0; 
}
Passenger::Passenger(string id, string n, Date iDate, char s, int cap):Vehicle(id,n,iDate,s)
{
	setCapacity(cap);
}
    
void Passenger::setCapacity(int cap)
{
 	capacity=cap; 
}

void Passenger::print( ostream& os) const throw ( invalid_argument )
{
	//cout<< "inside Passenger::print"<<endl;
	if (!os)
	{
		throw invalid_argument("Passenger::print File did not open.Check file name");
	}
	//cout<< "calling Vehicle::print"<<endl;
	Vehicle::print(os); 
	//cout<< "returned from call"<<endl;
	cout<<endl;
	os << "Max Passenger: "<< capacity;
}//END Passenger::print 

void Passenger::read( istream& is ) throw ( invalid_argument )
{
	//cout<< "inside Passenger::read"<<endl; 
	Vehicle::read(is); 
	//cout<< "returned from call"<<endl; 
	int p;
	is>>p ;
	setCapacity(p);
}//END Passenger :: read

/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Cargo declaration                                **
 **                                                                        **
 **																		   **
 ****************************************************************************
 ****************************************************************************/
Cargo:: Cargo(): Vehicle()
{
	capacity = 0.0; 
}
Cargo::Cargo(string id, string n, Date iDate, char s, double cap):Vehicle(id,n,iDate,s)
{
	setCapacity(cap);
}
    
void Cargo::setCapacity(double cap)
{
 	capacity = cap; 
}

void Cargo::print( ostream& os) const throw ( invalid_argument )
{
	//cout<< "inside Cargo::print"<<endl;
	if (!os)
	{
		throw invalid_argument("Cargo::print File did not open.Check file name");
	}
	//cout<< "calling Cargo::print"<<endl;
	Vehicle::print(os); 
	//cout<< "returned from call"<<endl;
	cout<<endl;
	os << "Max Payload: "<< capacity <<endl;
}//END Cargo::print 

void Cargo::read( istream& is ) throw ( invalid_argument )
{
	//cout<< "inside Cargo::read"<<endl; 
	Vehicle::read(is); 
	//cout<< "returned from call"<<endl; 
	double c;
	is>>c; 
	setCapacity(c);
}//END Cargo :: read
