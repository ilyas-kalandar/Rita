#include <functional>
#include <iostream>

#include "object.hpp"
#include "lexer.hpp"
#include "type.hpp"
#include "Instructions/binop_instruction.hpp"
#include "native_function.hpp"
#include "Instructions/leaf.hpp"
#include "parser.hpp"
#include "engine.hpp"
#include "ast_printer.hpp"
#include "string_obj.hpp"

#include "interpreter.hpp"

int main(int argc, const char* argv[])
{
    Interpreter::Interpreter i(argv, argc);

    i.Run();
}
