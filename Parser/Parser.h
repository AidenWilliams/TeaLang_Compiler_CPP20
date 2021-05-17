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
    class Parser {
    public:
        Parser(std::vector<lexer::Token> tokens) {
            currentToken = tokens.begin();
            nextToken = currentToken + 1;
        };
        ASTProgramNode* parseProgram();
        ASTStatementNode* parseStatement();
        ASTDeclarationNode* parseDeclaration();
        ASTExprNode* parseExpression();
        ASTExprNode* parseSimpleExpression();
        ASTExprNode* parseTerm();
        ASTExprNode* parseFactor();
        TYPE parseType(const std::string& identifier);

    private:
        std::vector<lexer::Token>::iterator currentToken;
        std::vector<lexer::Token>::iterator nextToken;

        void moveTokenWindow(int step = 1);
    };
}
#endif //TEALANG_COMPILER_CPP20_PARSER_H
