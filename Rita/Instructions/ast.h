#include "../Core/type.h"

enum class InstructionType
{
    BINOP,
    LEAF,
    ASSIGNMENT,
    IF,
    WHILE,
};


class WhileInstruction : public IfInstruction
{
public:
    WhileInstruction(std::vector<std::shared_ptr<Instruction>>& body, std::shared_ptr<BinOpInstruction> expr) : IfInstruction(body, expr)
    {
        this->type = InstructionType::WHILE;
    }
};