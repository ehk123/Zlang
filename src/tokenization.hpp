#pragma once

#include <string>
#include <vector>

enum class TokenType
{
    periodt,
    intlit,
    semi
};

struct Token
{
    TokenType type;
    std::optional<std::string> value{};
};

class Tokenizer
{
public:
    inline explicit Tokenizer(const std::string &src)
        : m_src(std::move(src))
    {
    }

    inline std::vector<Token> tokenize()
    {
        std::vector<Token> tokens;
        std::string buf;
        while (peek().has_value())
        {
            if (std::isalpha(peek().value()))
            {
                buf.push_back(consume());
                while (peek().has_value() && std::isalnum(peek().value()))
                {
                    buf.push_back(consume());
                }
                if (buf == "periodt")
                {
                    tokens.push_back({.type = TokenType::periodt});
                    buf.clear();
                    continue;
                }
                else
                {
                    std::cerr << "ur code is cooked." << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
            else if (std::isdigit(peek().value()))
            {
                buf.push_back(consume());
                while (peek().has_value() && std::isdigit(peek().value()))
                {
                    buf.push_back(consume());
                }
                tokens.push_back({.type = TokenType::intlit, .value = buf});
                buf.clear();
                continue;
            }
            else if (peek().value() == ';')
            {
                consume();
                tokens.push_back({.type = TokenType::semi});
                continue;
            }
            else if (std::isspace(peek().value()))
            {
                consume();
                continue;
            }
            else
            {
                std::cerr << "ur code is cooked." << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        m_index = 0;
        return tokens;
    }

private:
    [[nodiscard]] inline std::optional<char> peek(int ahead = 1) const
    {
        if (m_index + ahead > m_src.length())
        {
            return {};
        }
        else
        {
            return m_src.at(m_index);
        }
    }

    inline char consume()
    {
        return m_src.at(m_index++);
    }

    const std::string m_src;
    size_t m_index;
};