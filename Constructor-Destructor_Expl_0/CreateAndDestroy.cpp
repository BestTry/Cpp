// Fig. 9.14: CreateAndDestroy.cpp
// CreateAndDestroy class member-function definitions.
#include <format>
#include <iostream>
#include "CreateAndDestroy.h" // include CreateAndDestroy class declaration


                              // Constructor sets object's ID number and descriptive message
CreateAndDestroy::CreateAndDestroy(int ID, std::string_view message)
   : m_ID{ ID }, m_message{ message } {
   std::cout << format(" Object {}   constructor runs   {}\n",
      m_ID, m_message);
}

                              // Destructor for class - Note the tilde ' ~ '                                            
CreateAndDestroy::~CreateAndDestroy() {
                              // Output newline for certain objects; helps readability 
   std::cout << format(" {}Object {}   destructor runs    {}\n",
      (m_ID == 1 || m_ID == 6 ? "\n " : ""), m_ID, m_message);
}


