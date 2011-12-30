/*******************************************************************************
* intelhexclass - class definitions                                            *
*                                                                              *
* A class to handle the encoding and decoding of an Intel HEX format file as   *
* generated by many tool chains for embedded processors and microcontrollers.  *
*                                                                              *
* This class is constructed based upon the definition given in the document    *
* 'Hexadecimal Object File Format Specification', Revision A, January 6, 1988, *
* © 1998 Intel Corporation                                                     *
*------------------------------------------------------------------------------*
* class intelhex                                                               *
*   Member Functions:                                                          *
*                                                                              *
*******************************************************************************/
#include <iostream>
#include <map>

using namespace std;

enum intelhexRecordType {
    DATA_RECORD,
    END_OF_FILE_RECORD,
    EXTENDED_SEGMENT_ADDRESS,
    START_SEGMENT_ADDRESS,
    EXTENDED_LINEAR_ADDRESS,
    START_LINEAR_ADDRESS,
    NO_OF_RECORD_TYPES
};

class intelhex {
        /* Output stream operator to encode contents                          */
        friend ostream& operator<<(ostream& dataOut, 
                                   const intelhex& intelhexData);
        
        /* Input stream to decode contents                                    */
        friend istream& operator>>(istream& dataIn, 
                                   const intelhex& intelhexData);
                                   
        /* Converts ASCII char to their HEX values                            */
        friend unsigned char charToHex(char value);
        
    private:
        /* Stores the addresses and their data of the HEX file                */
        map<int, unsigned char> ihContent;
        
        /* Iterator for Intel HEX Content map                                 */
        map<int, unsigned char>::iterator ihIterator;
        
        /* Return value for handling results of map operations                */
        pair<map<int, unsigned char>::iterator,bool> ihReturn;
  
        /* Stores the current address                                         */
        unsigned long currentAddress;
        
        /* Stores the CS register value for a 'Start Segment Address Record'  */
        unsigned short csRegister;
        
        /* Stores the IP register value for a 'Start Segment Address Record'  */
        unsigned short ipRegister;
        
        /* Stores the EIP register value for a 'Start Linear Address Record'  */
        unsigned long eipRegister;
        
    public:
        /* Constructor                                                        */
        intelhex();

        /* Destructor                                                         */
        ~intelhex();
};
    
