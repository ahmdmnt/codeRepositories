/*
 * Project 01:
 * Address Book:
 *     Simple address book program that allows users to add, update, and search for contacts.
 */

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cctype>

#define COUNT_DECREMENT 0
#define COUNT_INCREMENT 1
#define COUNT_CLEAR 2

/* ENUM: Address Book Options ********************************************************************/
enum class AddressBookOptions : unsigned char {
    NONE,
    LIST_ALL,
    ADD,
    DELETE,
    DELETE_ALL,
    SEARCH,
    CLOSE
};
/* END OF ENUM ***********************************************************************************/

/* CLASS: Contact Address ************************************************************************/
class contactAddress {
    private:
    static int contactCount;
    int contactId;
    std::string contactName;
    int phoneNumber;

    public:
    void setContactAddress(std::string name, int phone);
    static void updateContactCount(int contactCountStatus);
    void printContact(void);
    std::string getContactName(void);
    static int getAddressBookCount(void);
    static void printAddressBookHeader(void);
    static void printAddressBookFooter(void);
};

int contactAddress::contactCount = 0;

void contactAddress::setContactAddress(std::string name, int phone) {
    contactId = 1000+contactCount;
    contactName = name;
    phoneNumber = phone;
}

void contactAddress::updateContactCount(int contactCountStatus) {
    if(COUNT_INCREMENT == contactCountStatus) {
        contactCount++; 
    }
    else if (COUNT_DECREMENT == contactCountStatus)
    {
        contactCount--; 
    }
    else if (COUNT_CLEAR == contactCountStatus) {
        contactCount = 0;
    }
    else {}
    std::cout<< std::endl << "Total Contact Count = " << contactCount << std::endl;
}

void contactAddress::printContact(void) {
    std::cout<< "+------+-----------------+-----------------+" <<std::endl;
    std::cout<< "| " << std::setw(4) << std::right << contactId << " | " 
                << std::setw(15) << std::left << contactName << " | " 
                << std::setw(15) << phoneNumber << " | " << std::endl;
}

std::string contactAddress::getContactName(void) {
    return this->contactName;
}

int contactAddress::getAddressBookCount(void) {
    return contactCount;
}

void contactAddress::printAddressBookHeader(void) {
    std::cout<< std::endl << std::endl;
    std::cout<< "+------------------------------------------+" << std::endl;
    std::cout<< "|    Address Book    -   Total Count: " << std::setw(2) << contactCount << "   |" << std::endl;
}

void contactAddress::printAddressBookFooter(void) {
    std::cout<< "+------+-----------------+-----------------+" <<std::endl;
}
/* END OF CLASS **********************************************************************************/

/* Function Prototypes ***************************************************************************/
int AppInit(void);
/* END OF PROTOTYPES *****************************************************************************/

/* MAIN FUNCTION *********************************************************************************/
int main() {
    bool shutdownFlag {false};
    std::vector<contactAddress> contactAddressList {};
    contactAddress contactInstance;

    AddressBookOptions selectedOption {};
    int totalContactCount {};

    std::string inputContactName {};
    int inputPhoneNumber {};
    int inputContactId {};
    bool foundFlag {false};
    do {
        shutdownFlag = false;
        selectedOption = static_cast<AddressBookOptions>(AppInit());

        switch (selectedOption)
        {
        case AddressBookOptions::LIST_ALL:
            totalContactCount = contactAddress::getAddressBookCount();
            std::cout<< "Total Contact Count: " << totalContactCount << std::endl;

            contactAddress::printAddressBookHeader();
            for(auto instance: contactAddressList) {
                instance.printContact();
            }
            contactAddress::printAddressBookFooter();
            break;
        case AddressBookOptions::ADD:
            std::cout<< "Enter Contact Name: ";
            std::cin>> inputContactName;
            std::cout<< "Enter Contact Phone Number: ";
            std::cin>> inputPhoneNumber;

            contactInstance.setContactAddress(inputContactName, inputPhoneNumber);
            contactAddressList.push_back(contactInstance);
            contactAddress::updateContactCount(COUNT_INCREMENT);

            std::cout<< "New Contact [ID: " << contactAddress::getAddressBookCount() << "] is added successfully!" << std::endl;
            break;
        case AddressBookOptions::DELETE:
            contactAddress::printAddressBookHeader();
            for(auto instance: contactAddressList) {
                instance.printContact();
            }
            contactAddress::printAddressBookFooter();
            
            std::cout<< "Which Address ID, you want to delete? : ";
            std::cin>> inputContactId;

            contactAddressList.erase( contactAddressList.begin()+(inputContactId-1000) );
            contactAddress::updateContactCount(COUNT_DECREMENT);
            break;
        case AddressBookOptions::DELETE_ALL:
            contactAddressList.erase( contactAddressList.begin(), contactAddressList.end() );
            contactAddress::updateContactCount(COUNT_CLEAR);
            break;
        case AddressBookOptions::SEARCH:
            std::cout<< "Enter Contact Name : ";
            std::cin>> inputContactName;

            for(auto instance: contactAddressList) {
                if(inputContactName == instance.getContactName()) {
                    instance.printContact();
                    contactAddress::printAddressBookFooter();
                    foundFlag = true;
                }
            }
            if(!foundFlag) {
                std::cout<< "Contact Not Found!" << std::endl;
            }
            break;
        case AddressBookOptions::CLOSE:
            std::cout<< "Closing, ";
        case AddressBookOptions::NONE:
        default:
            shutdownFlag = true;
            std::cout<< "Application Shutdown ..." << std::endl;
            break;
        }

        std::cout<< "**************************************************************" << std::endl;
    } while(shutdownFlag == false);
    std::cout<< std::endl << std::endl;
    return 0;

}
/* END OF MAIN ***********************************************************************************/


/* FUNCTION DEFINITION ***************************************************************************/
int AppInit(void) {
    std::cout<< std::endl;
    std::cout<< " -------- Welcome to Address Book ------- " << std::endl;
    std::cout<< "+----+-------------+---------------------+" << std::endl;
    std::cout<< "|" << std::setw(4) << std::right << "1 " << "|" << std::setw(13) << std::left << " List All" << "|" << std::setw(21) << " List all Users." << "|" << std::endl;
    std::cout<< "|" << std::setw(4) << std::right << "2 " << "|" << std::setw(13) << std::left << " Add" << "|" << std::setw(21) << " Add an User." << "|" << std::endl;
    std::cout<< "|" << std::setw(4) << std::right << "3 " << "|" << std::setw(13) << std::left << " Delete" << "|" << std::setw(21) << " Delete an User." << "|" << std::endl;
    std::cout<< "|" << std::setw(4) << std::right << "4 " << "|" << std::setw(13) << std::left << " Delete All" << "|" << std::setw(21) << " Delete all Users." << "|" << std::endl;
    std::cout<< "|" << std::setw(4) << std::right << "5 " << "|" << std::setw(13) << std::left << " Search" << "|" << std::setw(21) << " Search on a User." << "|" << std::endl;
    std::cout<< "|" << std::setw(4) << std::right << "6 " << "|" << std::setw(13) << std::left << " Close" << "|" << std::setw(21) << " Close Phonebook." << "|" << std::endl;
    std::cout<< "+----+-------------+---------------------+" << std::endl;
    std::cout<< "Enter your choice: ";
    
    int inputData;
    std::cin>> inputData;

    return inputData;
}
/* END OF FN DEFINITION **************************************************************************/
