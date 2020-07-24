#include "error.h"
using namespace std;

BaseErrorType::BaseErrorType(char * message) {
   this -> message = new char [strlen(message) + 1];
   strcpy(this -> message, message);
}

BaseErrorType::~BaseErrorType() {}

void BaseErrorType::msg() {
   cout << "\nMESSAGE:\n" << message;
}

SpecialError::SpecialError(int severity, char * message): BaseErrorType(message) {
   this -> severity = severity;
}
SpecialError::~SpecialError(){}

void SpecialError::msg() {
   BaseErrorType::msg();
   cout << "severity: " << severity << endl;
}
