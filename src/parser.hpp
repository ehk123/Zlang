#pragma once

#include "tokenization.hpp"

struct NodeExpr
{
    Token int_lit;
};

struct NodeYeet
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
        if (peak().has_value() && peak().value().type == TokenType::int_lit)
        {
            return NodeExpr{.int_lit = consume()};
        }
        else
        {
            return {};
        }
    }

    std::optional<NodeYeet> parse()
    {
        std::optional<NodeYeet> yeet_node;
        while (peak().has_value())
        {
            if (peak().value().type == TokenType::yeet)
            {
                consume();
                if (auto node_expr = parse_expr())
                {
                    yeet_node = NodeYeet{.expr = node_expr.value()};
                }
                else
                {
                    std::cerr << "Ur code is cooked." << std::endl;
                    exit(EXIT_FAILURE);
                }
                if (peak().has_value() && peak().value().type == TokenType::semi)
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
        return yeet_node;
    }

private:
    [[nodiscard]] inline std::optional<Token> peak(int ahead = 1) const
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