#include "../Core/type.h"

enum class InstructionType
{
    BINOP,
    LEAF,
    ASSIGNMENT,
    IF,
    WHILE,
};


class AssignmentInstruction : public Instruction
{
private:
    std::string& identifier;
    std::shared_ptr<Instruction> instr;
public: 
    AssignmentInstruction(std::string& id, std::shared_ptr<Instruction> inst) : identifier(id)
    {
        this->type = InstructionType::ASSIGNMENT;
        this->instr = inst;
    }
    std::shared_ptr<Instruction> GetRightInstr()
    {
        return this->instr;
    }
    const std::string& GetIdentifier()
    {
        return this->identifier;
    }
};

class IfInstruction : public Instruction
{
protected:
    std::shared_ptr<Instruction> expr;
    std::vector<std::shared_ptr<Instruction>>& body;

public:
    IfInstruction(std::vector<std::shared_ptr<Instruction>>& body, std::shared_ptr<BinOpInstruction> expr) : body(body)
    {
        this->expr = expr;
        this->type = InstructionType::IF;
    }
    std::shared_ptr<BinOpInstruction> GetExpr()
    {
        return this->expr;
    }
    std::vector<std::shared_ptr<Instruction>> GetBody()
    {
        return this->body;
    }
};

class WhileInstruction : public IfInstruction
{
public:
    WhileInstruction(std::vector<std::shared_ptr<Instruction>>& body, std::shared_ptr<BinOpInstruction> expr) : IfInstruction(body, expr)
    {
        this->type = InstructionType::WHILE;
    }
};