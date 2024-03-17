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
        std::optional<NodePeriodt> periodt_node;
        while (peek().has_value())
        {
            if (peek().value().type == TokenType::periodt)
            {
                consume();
                if (auto node_expr = parse_expr())
                {
                    periodt_node = NodePeriodt{.expr = node_expr.value()};
                }
                else
                {
                    std::cerr << "Ur code is cooked." << std::endl;
                    exit(EXIT_FAILURE);
                }
                if (peek().has_value() && peek().value().type == TokenType::semi)
                {
                    consume();
                }
                else
                {
                    std::cerr << "ur code is cooked." << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
        }
        m_index = 0;
        return periodt_node;
    }

private:
    [[nodiscard]] inline std::optional<Token> peek(int ahead = 1) const
    {
        if (m_index + ahead > m_tokens.size())
        {
            return {};
        }
        else
        {
            return m_tokens.at(m_index);
        }
    }

    inline Token consume()
    {
        return m_tokens.at(m_index++);
    }

    const std::vector<Token> m_tokens;
    size_t m_index;
};