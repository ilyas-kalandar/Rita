#include <string>

#ifndef interpreter_hpp

namespace Interpreter
{
    /**
     * @brief 
     * 
     */
    class Interpreter
    {
    protected:
        bool isFile = false;
        bool outputTokens = false;
        bool outputAst = false;
        bool isInteractive = false;
        bool outputVersion = false;
        bool outputHelp = false;
        std::string fileName;

    std::string parseArg();

    public:
        Interpreter(const char* argv[], int argc);

        /**
         * @brief 
         * 
         */
        void Run();
    };
}

#endif