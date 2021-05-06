//
// Created by aiden on 04/05/2021.
//

#ifndef TEALANG_COMPILER_CPP20_VISITOR_H
#define TEALANG_COMPILER_CPP20_VISITOR_H

#include <string>

namespace parser {

    template <typename T> class ASTLiteralNode;
    class ASTActualParamNode;
    class ASTFunctionCallNode;
    class ASTIdentifierNode;
    class ASTSubExpression;
    class ASTUnaryExprNode;
    template <typename T> class ASTFactorNode;
    class ASTTermNode;
    class ASTSimpleExprNode;

    class ASTAssignmentNode;
    class ASTDeclarationNode;
    class ASTPrintNode;
    class ASTReturnNode;
    class ASTBlockNode;
    class ASTIfNode;
    class ASTForNode;
    class ASTWhileNode;
    class ASTFunctionDeclerationNode;

    class ASTProgramNode;

}

namespace visitor {

    class Visitor {

    public:
        virtual void visit(parser::ASTLiteralNode<float>*) = 0;
        virtual void visit(parser::ASTLiteralNode<int>*) = 0;
        virtual void visit(parser::ASTLiteralNode<bool>*) = 0;
        virtual void visit(parser::ASTLiteralNode<std::string>*) = 0;
        virtual void visit(parser::ASTActualParamNode*) = 0;
        virtual void visit(parser::ASTFunctionCallNode*) = 0;
        virtual void visit(parser::ASTFactorNode<parser::ASTLiteralNode<float>>*) = 0;
        virtual void visit(parser::ASTFactorNode<parser::ASTLiteralNode<int>>*) = 0;
        virtual void visit(parser::ASTFactorNode<parser::ASTLiteralNode<bool>>*) = 0;
        virtual void visit(parser::ASTFactorNode<parser::ASTLiteralNode<std::string>>*) = 0;
        virtual void visit(parser::ASTFactorNode<parser::ASTIdentifierNode>*) = 0;
        virtual void visit(parser::ASTFactorNode<parser::ASTFunctionCallNode>*) = 0;
        virtual void visit(parser::ASTFactorNode<parser::ASTSubExpression>*) = 0;
        virtual void visit(parser::ASTFactorNode<parser::ASTUnaryExprNode>*) = 0;
        virtual void visit(parser::ASTTermNode*) = 0;
        virtual void visit(parser::ASTSimpleExprNode*) = 0;
        virtual void visit(parser::ASTIdentifierNode*) = 0;
        virtual void visit(parser::ASTSubExpression*) = 0;
        virtual void visit(parser::ASTUnaryExprNode*) = 0;
        virtual void visit(parser::ASTAssignmentNode*) = 0;
        virtual void visit(parser::ASTDeclarationNode*) = 0;
        virtual void visit(parser::ASTPrintNode*) = 0;
        virtual void visit(parser::ASTReturnNode*) = 0;
        virtual void visit(parser::ASTBlockNode*) = 0;
        virtual void visit(parser::ASTIfNode*) = 0;
        virtual void visit(parser::ASTForNode*) = 0;
        virtual void visit(parser::ASTWhileNode*) = 0;
        virtual void visit(parser::ASTFunctionDeclerationNode*) = 0;
        virtual void visit(parser::ASTProgramNode*) = 0;
    };

}


#endif //TEALANG_COMPILER_CPP20_VISITOR_H
