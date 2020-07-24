#include "error.h"
int SIZE = 100;
using namespace std;

int fallable_function() {
   char message[] = "This is a helpfull message\n";
   char response[SIZE];

   cout << "what type of exception to throw?\n\n";

   cin.get(response, SIZE, '\n');
   cin.ignore(100, '\n');

   if(!strcmp(response, "base")) {
      BaseErrorType exception(message);
      throw exception;
   }

   if(!strcmp(response, "special")) {
      int severity = 0;
      cout << "how severe?\n\n";
      cin >> severity;
      cin.ignore(100, '\n');

      SpecialError exception(severity, message);
      throw exception;
   }

   if(!strcmp(response, "int")) {
      int exception = 0;
      cout << "what int?\n\n";
      cin >> exception;
      cin.ignore(100, '\n');
      throw exception;
   }

   if(!strcmp(response, "char")) {
      char exception = 0;
      cout << "what char?\n\n";
      cin >> exception;
      cin.ignore(100, '\n');
      throw exception;
   }

   if(!strcmp(response, "none")) {
      cout << "no exception thrown";
      return 0;
   }

   throw true;
}

int main() {
   while(1) {
      try {
         return fallable_function();
      }
      catch(BaseErrorType &e) {
         e.msg();
      }
      catch(int e) {
         cout << "\nan int was thrown:\n" << e << endl;
      }
      catch(char e) {
         cout << "\na char was thrown\n" << e << endl;
      }
      catch(...) {
         cout << "\ncaught a generic exeption not caught by any other catch blocks\n";
      }
   }
}
