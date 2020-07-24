#include <cstring>
#include <iostream>

class BaseErrorType {
   public:
      BaseErrorType(char * message);
      virtual ~BaseErrorType();

      virtual void msg();
   protected:
      char * message;
};

class SpecialError: public BaseErrorType {
   public:
      SpecialError(int severity, char * message);
      ~SpecialError();

      void msg();
   protected:
      int severity;
};
