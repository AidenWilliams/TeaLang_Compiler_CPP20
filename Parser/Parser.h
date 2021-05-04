//
// Created by Aiden Williams on 03/05/2021.
//

#ifndef TEALANG_COMPILER_CPP20_PARSER_H
#define TEALANG_COMPILER_CPP20_PARSER_H

#include <vector>
#include <string>
#include <stdexcept>
#include "../Visitor/Visitor.h"
#include "../Lexer/Lexer.h"
#include "../Lexer/Token.h"
#include "AST.h"

namespace parser {

    bool isIdentifier();
    bool isSemicolon();

    class Parser {
    public:
        Parser(std::vector<lexer::Token> tokens) :
                tokens(std::move(tokens))
        {
            currentToken = tokens.begin();
            nextToken = currentToken + 1;
        };
        ASTProgramNode* parseProgram();

    private:
        void moveTokenWindow(int step=1);
        std::vector<lexer::Token> tokens;
        std::vector<lexer::Token>::iterator currentToken;
        std::vector<lexer::Token>::iterator nextToken;
        // Expression Nodes
        ASTExprNode* parseExpression();

        // Statement Nodes
        ASTStatementNode* parseStatement();
        ASTAssignmentNode* parseAssignment(const std::string& identifier);
        ASTDeclarationNode* parseDeclaration();
        ASTPrintNode* parsePrint();
        ASTReturnNode* parseReturn();
        ASTBlockNode* parseBlock();
        ASTIfNode* parseIf();
        ASTForNode* parseFor();
        ASTWhileNode* parseWhile();
        ASTFunctionDefinitionNode* parseFunctionDefinition();
    };
}


#endif //TEALANG_COMPILER_CPP20_PARSER_H
