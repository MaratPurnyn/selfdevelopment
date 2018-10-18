//std libraries
#include <iostream>

class Log 
{ 
    private:
        //variables
        const char *m_msg;
    public:
        //functions
        Log();
        ~Log();
        void info(std::string msg);
};