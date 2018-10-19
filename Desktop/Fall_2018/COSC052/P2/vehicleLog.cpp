/*
 *  vehicleLog.cpp
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

#include "vehicleLog.h"

VehicleLog::~VehicleLog()
{
	unsigned long deleteCount = 0 ; 
	for (unsigned int g = 0; g<vehicles.size();g++)
	{
		delete vehicles.at(g); 
		deleteCount++; 
	}
	cout<<deleteCount << " objects deleted and memory deallocated."<<endl;
}//END VehicleLog deconstructor

 int VehicleLog::getTotalPassengerCapacity() const
 {
    int answer = 0;
    //loop through vector
    for (unsigned long v=0; v < vehicles.size(); v++)
    {
        Passenger *pPtr = dynamic_cast <Passenger*> (vehicles.at(v));  
        if (pPtr)
        {
            //update running total    
            answer += pPtr -> getCapacity();
        }
    }//End loop to iterate over all elements of the vector. Only the first character
    // computes and returns the total passenger capacity of all vehicles stored in the vector
    return answer; 
 }// END VehicleLog::getTotalPassengerCapacity
 
 double VehicleLog::getTotalCargoCapacity() const
 {
    double answer = 0;
    //loop through vector
    for (unsigned long v=0; v < vehicles.size(); v++)
    {
        Cargo *cPtr = dynamic_cast <Cargo*> (vehicles.at(v));
        if (cPtr)
        {
            //update running total     
            answer += cPtr -> getCapacity();
        }
    }//End loop to iterate over all elements of the vector. Only the first character.
    // computes and returns the total passenger capacity of all vehicles stored in the vector
    return answer; 
 }//END VehicleLog::getTotalCargoCapacity

 void VehicleLog::print (ostream & os) const throw(invalid_argument)
 {
	// throws exception if stream is initially in failed state 
	cout<< "in VehicleLog::print"<<endl;
	if (!os)
		{
			throw invalid_argument( "Error VehicleLog::print:Ostream is in a failed state"); 
		}
	//outputs all vehicles to the stream object passed into its parameter formatted
	/* loops through all elements of vehicle vector and calls the print method of 
	   each element stored on the vector*/
	for (unsigned int i=0; i< vehicles.size(); i++)
	{
		 
		vehicles[i]->print(os); 
	}
	//cout<< "exiting VehicleLog::print"<<endl;
 }

 void VehicleLog:: read( string fileName ) throw ( invalid_argument, bad_vehicle_code )
{ std::fstream vStrm( fileName.c_str());
    if (!vStrm) 
    {
        string errmsg= "" ; 
        errmsg += "Input file didn't open, check path and name:\n"; 
        errmsg+= fileName; 
        errmsg+= "\n";
        cout<< errmsg; 
        throw invalid_argument(errmsg); 
    }// End if (!inFile)
    
    char carTypeCode = '?';
    
    Vehicle *v0 = NULL;
    
    string junk = "";
    
    //vStrm >> carTypeCode;
    
    while ( vStrm )
    {
        try
        {
            vStrm >> carTypeCode;
            vStrm.putback(carTypeCode);
            
            carTypeCode = tolower(carTypeCode);
            
            if ( carTypeCode == 'i')
            {
                v0 = new Individual;
            }
            else if ( carTypeCode == 'p' )
            {
                v0 = new Passenger;
            }
            else if ( carTypeCode == 'c' )
            {
                v0 = new Cargo;
            }
            else
            {
                // throw exception
                throw bad_vehicle_code("car code not valid!");
            }
            
            v0->read(vStrm);
            
            vehicles.push_back(v0);
            
            //vStrm >> carTypeCode;
            
        } // END nested try block
        
        catch (bad_vehicle_code &e)
        {
            cout << "caught bad_vehicle_code exception in while loop reading file" << endl;
            cout << "continue processing, but skip this loop." << endl;
            cout << e.what() << endl;
            
            getline(vStrm, junk);
            
            //vStrm >> carTypeCode;
            
        }
      catch (invalid_argument &e)
      {
        cout<< " caught invalid_argument exception in while loop reading file"<<endl;
        cout<< "continue processing , but skip this loop."<<endl;
        cout << e.what()<<endl;
        
        getline(vStrm,junk);
      }
        
        catch (...)
        {
            cout << "caught unknown exception inside while loop, terminate program" << endl;
            throw;
        }
        
    } // END loop to read file contents
}