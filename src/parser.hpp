#pragma once

#include "tokenization.hpp"

struct NodeExpr
{
    Token int_lit;
};

struct NodePeriodt
{
    NodeExpr expr;
};

class Parser
{
public:
    inline explicit Parser(std::vector<Token> tokens)
        : m_tokens(std::move(tokens))
    {
    }

    std::optional<NodeExpr> parse_expr()
    {
        if (peek().has_value() && peek().value().type == TokenType::int_lit)
        {
            return NodeExpr{.int_lit = consume()};
        }
        else
        {
            return {};
        }
    }

    std::optional<NodePeriodt> parse()
    {
        std::optional<NodePeriodt> exit_node;
        while (peek().has_value())
        {
            if (peek().value().type == TokenType::exit && peek(1).has_value() && peek(1).value().type == TokenType::open_paren)
            {
                consume();
                consume();
                if (auto node_expr = parse_expr())
                {
                    exit_node = NodePeriodt{.expr = node_expr.value()};
                }
                else
                {
                    std::cerr << "ur expression is cooked." << std::endl;
                    exit(EXIT_FAILURE);
                }
                if (peek().has_value() && peek().value().type == TokenType::close_paren)
                {
                    consume();
                }
                else
                {
                    std::cerr << "no `)` is cooked." << std::endl;
                }
                if (peek().has_value() && peek().value().type == TokenType::semi)
                {
                    consume();
                }
                else
                {
                    std::cerr << "no `;` is cooked." << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
        }
        m_index = 0;
        return exit_node;
    }

private:
    [[nodiscard]] inline std::optional<Token> peek(int offset = 0) const
    {
        if (m_index + offset >= m_tokens.size())
        {
            return {};
        }
        else
        {
            return m_tokens.at(m_index + offset);
        }
    }

    inline Token consume()
    {
        return m_tokens.at(m_index++);
    }

    const std::vector<Token> m_tokens;
    size_t m_index;
};