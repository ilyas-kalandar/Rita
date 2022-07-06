#include "../Core/type.h"

enum class InstructionType
{
    BINOP,
    LEAF,
    ASSIGNMENT,
    IF,
    WHILE,
};

enum class OpType
{
    PLUS,
    MINUS,
    MUL,
    DIV,
    EQUAL_EQUAL,
};

class Instruction
{
protected: 
    InstructionType type;
public:
    InstructionType GetType()
    {
        return this->type;
    }
};

class Leaf : public Instruction
{
private: 
    RitaObject* obj;
public:
    Leaf(RitaObject* obj)
    {
        this->type = InstructionType::LEAF;
        this->obj = obj;
    }
    RitaObject* GetObj()
    {
        return this->obj;
    }
};

class BinOpInstruction : public Instruction
{
private:
    std::shared_ptr<Instruction> first;
    std::shared_ptr<Instruction> second;
    OpType operation_type;
public:
    BinOpInstruction(std::shared_ptr<Instruction> first, std::shared_ptr<Instruction> second, OpType op_type)
    {
        this->type = InstructionType::BINOP;
    }
    std::shared_ptr<Instruction> GetFirst()
    {
        return this->first;
    } 
    std::shared_ptr<Instruction> GetSecond()
    {
        return this->second;
    }
    OpType GetOperationType()
    {
        return this->operation_type;
    }
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
    std::shared_ptr<BinOpInstruction> expr;
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