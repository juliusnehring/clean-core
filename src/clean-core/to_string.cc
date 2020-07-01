#include "to_string.hh"

#include <cinttypes>
#include <cstdio>
#include <type_traits>

#include <clean-core/always_false.hh>
#include <clean-core/assert.hh>
#include <clean-core/char_predicates.hh>
#include <clean-core/string.hh>
#include <clean-core/string_stream.hh>
#include <clean-core/string_view.hh>

cc::string cc::to_string(char value) { return string::filled(1, value); }
cc::string cc::to_string(bool value) { return value ? "true" : "false"; }
cc::string cc::to_string(const char* value) { return value == nullptr ? "[nullptr]" : value; }
cc::string cc::to_string(cc::string_view value) { return value; }
cc::string cc::to_string(cc::nullptr_t) { return "nullptr"; }

cc::string cc::to_string(void* value)
{
    if (value == nullptr)
        return "nullptr";

    char buffer[16 + 2 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "0x%.16zx", size_t(value));
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(signed char value)
{
    char buffer[3 + 1 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "%hhd", value);
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(short value)
{
    char buffer[6 + 1 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "%hd", value);
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(int value)
{
    char buffer[10 + 1 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "%d", value);
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(long value)
{
    char buffer[19 + 1 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "%ld", value);
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(long long value)
{
    char buffer[19 + 1 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "%lld", value);
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(unsigned short value)
{
    char buffer[6 + 1 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "%hu", value);
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(unsigned char value)
{
    char buffer[3 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "%hhu", value);
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(unsigned int value)
{
    char buffer[10 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "%u", value);
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(unsigned long value)
{
    char buffer[20 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "%lu", value);
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(unsigned long long value)
{
    char buffer[20 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "%llu", value);
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(float value)
{
    char buffer[20 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "%g", value);
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(double value)
{
    char buffer[30 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "%g", value);
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(long double value)
{
    char buffer[40 + 1];
    auto res = std::snprintf(buffer, sizeof(buffer), "%Lg", value);
    CC_ASSERT(res >= 0);
    return string_view(buffer, res);
}

cc::string cc::to_string(std::byte value)
{
    static constexpr auto hex = "0123456789ABCDEF";
    auto v = uint8_t(value);
    auto s = cc::string::uninitialized(2);
    s[0] = hex[v % 16];
    s[1] = hex[v / 16];
    return s;
}

cc::string to_string(char value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(bool value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(char const* value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(cc::string_view value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(nullptr_t, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, nullptr_t{}, fmt_str);
    return ss.to_string();
}

cc::string to_string(void* value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}

cc::string to_string(std::byte value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}

cc::string to_string(signed char value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(short value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(int value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(long value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(long long value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(unsigned char value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(unsigned short value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(unsigned int value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(unsigned long value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(unsigned long long value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}

cc::string to_string(float value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(double value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}
cc::string to_string(long double value, cc::string_view fmt_str)
{
    cc::string_stream ss;
    to_string(ss, value, fmt_str);
    return ss.to_string();
}

void to_string(cc::string_stream& ss, char value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, bool value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, char const* value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, cc::string_view value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, nullptr_t) { to_string(ss, nullptr_t{}, ""); }

void to_string(cc::string_stream& ss, void* value) { to_string(ss, value, ""); }

void to_string(cc::string_stream& ss, std::byte value) { to_string(ss, value, ""); }

void to_string(cc::string_stream& ss, signed char value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, short value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, int value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, long value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, long long value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, unsigned char value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, unsigned short value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, unsigned int value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, unsigned long value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, unsigned long long value) { to_string(ss, value, ""); }

void to_string(cc::string_stream& ss, float value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, double value) { to_string(ss, value, ""); }
void to_string(cc::string_stream& ss, long double value) { to_string(ss, value, ""); }

namespace
{
// to_string implementations for builtin types
// format_spec ::=  [[fill]align][sign]["#"]["0"][width]["." precision][type]
// fill        ::=  <a character other than '{' or '}'>
// align       ::=  "<" | ">" | "^"
// sign        ::=  "+" | "-" | " "
// width       ::=  integer | "{" arg_id "}"
// precision   ::=  integer | "{" arg_id "}"
// type        ::=  int_type | "a" | "A" | "c" | "e" | "E" | "f" | "F" | "g" | "G" | "L" | "p" | "s"
// int_type    ::=  "b" | "B" | "d" | "o" | "x" | "X"
struct parsed_fmt_args
{
    int width = -1;                       // width of the replacement, use fill to match width
    int precision = -1;                   // for float/double: precision after comma / dot. For other types: max length
    char fill = ' ';                      // anything but '{' or '}'
    char align = '>';                     // '<': left | '>': right | '^': center
    char sign = '-';                      // '+': show both + and - | '-': show only - | ' ': show only -, but leave space if +
    char type = 0;                        // type: individual for each type. Sometimes determines how type should be interpreted, eg char
    bool alternative_mode = false;        // alternative display mode
    bool sign_aware_zero_padding = false; // add leading zeros after the sign +0000123
};

enum class align_t
{
    left,
    center,
    right,
};

enum class sign_t
{
    only_negative,
    both,
    negative_or_space,
};

struct int_format_args
{
    enum base
    {
        decimal,
        binary,
        octal,
        hex,
    };
    int width = 0;
    char fill = ' ';
    base type = decimal;
    bool print_prefix = false;
    bool caps = false;
    bool sign_aware_zero_padding = false;
};

parsed_fmt_args parse_args(cc::string_view fmt_args)
{
    auto const is_align = [](char c) { return c == '<' || c == '>' || c == '^'; };
    auto const is_sign = [](char c) { return c == '+' || c == '-' || c == ' '; };

    auto const parse_unsigned_int = [&](char const* begin, char const* end, int& out) -> char const* {
        out = *begin - '0';
        ++begin;
        while (begin != end && cc::is_digit(*begin))
        {
            out *= 10;
            out += *begin - '0';
            ++begin;
        }
        return begin;
    };

    auto current = fmt_args.begin();
    auto const end = fmt_args.end();

    parsed_fmt_args result;

    if (current == end)
        return result;

    // fill
    if (is_align(*current))
    {
        result.align = *current;
        ++current;
    }
    // alignment and fill
    else if ((current + 1) != end && is_align(*(current + 1)))
    {
        result.fill = *current;
        ++current;
        result.align = *current;
        ++current;
    }
    // sign
    if (current != end && is_sign(*current))
    {
        result.sign = *current;
        ++current;
    }
    // alternative mode
    if (current != end && (*current == '#'))
    {
        result.alternative_mode = true;
        ++current;
    }
    // zero padding and width
    if (current != end && (*current == '0'))
    {
        result.sign_aware_zero_padding = true;
        ++current;
        CC_ASSERT(current != end && cc::is_digit(*current) && "Invalid format string: Zero padding must be followed by by width");
        CC_ASSERT(*current != '0' && "Invalid format string: Width can have at most one preceeding zero");
    }
    // width
    if (current != end && cc::is_digit(*current))
    {
        current = parse_unsigned_int(current, end, result.width);
    }
    // precision
    if (current != end && *current == '.')
    {
        ++current;
        CC_ASSERT(current != end && cc::is_digit(*current) && "Invalid format string: . must be followed by precision");
        current = parse_unsigned_int(current, end, result.precision);
    }
    // type
    if (current != end)
    {
        result.type = *current;
        ++current;
    }
    CC_ASSERT(current == end && "Invalid format string: Malformed argument");

    return result;
}

constexpr bool is_int_type(char c) { return c == 'd' || c == 'b' || c == 'B' || c == 'o' || c == 'x' || c == 'X'; }
constexpr bool is_float_type(char c) { return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'f' || c == 'F' || c == 'g' || c == 'G'; }

/// parse an int to binary and assume that the buffer is large enough. Returns the start of the non zero terminated values
template <class IntType>
char const* unsigned_int_to_binary(IntType value, char* end)
{
    static_assert(std::is_unsigned_v<IntType>);
    while (value)
    {
        --end;
        *end = value & 1 ? '1' : '0';
        value = value >> 1;
    }
    return end;
}

template <class IntType>
void unsigned_to_string_impl(cc::string_stream& ss, IntType value, parsed_fmt_args const& args)
{
    static_assert(std::is_unsigned_v<IntType>);
    switch (args.type)
    {
    case 0:   // fallthrough
    case 'd': // default, decimal
    {
        if constexpr (sizeof(IntType) == 1)
        {
            char buffer[3 + 1 + 1];
            auto const length = std::snprintf(buffer, sizeof(buffer), "%hhu", value);
            ss << cc::string_view(buffer, length);
        }
        if constexpr (sizeof(IntType) == 2)
        {
            char buffer[6 + 1 + 1];
            auto const length = std::snprintf(buffer, sizeof(buffer), "%hu", value);
            ss << cc::string_view(buffer, length);
        }
        if constexpr (sizeof(IntType) == 4)
        {
            char buffer[10 + 1 + 1];
            // the cast prevents a warning on MSVC where 32 bit integer are unsigned long
            auto const length = std::snprintf(buffer, sizeof(buffer), "%u", static_cast<unsigned int>(value));
            ss << cc::string_view(buffer, length);
        }
        if constexpr (sizeof(IntType) == 8)
        {
            char buffer[19 + 1 + 1];
            auto const length = std::snprintf(buffer, sizeof(buffer), "%llu", value);
            ss << cc::string_view(buffer, length);
        }
    }
    break;
    case 'b': // binary, with # prefix 0b
    {
        if (args.alternative_mode)
            ss << "0b";

        if constexpr (sizeof(IntType) == 1)
        {
            char buffer[8 + 1 + 1];
            auto const end = buffer + sizeof(buffer);
            auto const begin = unsigned_int_to_binary(value, end);
            ss << cc::string_view(begin, end);
        }
        if constexpr (sizeof(IntType) == 2)
        {
            char buffer[16 + 1 + 1];
            auto const end = buffer + sizeof(buffer);
            auto const begin = unsigned_int_to_binary(value, end);
            ss << cc::string_view(begin, end);
        }
        if constexpr (sizeof(IntType) == 4)
        {
            char buffer[32 + 1 + 1];
            auto const end = buffer + sizeof(buffer);
            auto const begin = unsigned_int_to_binary(value, end);
            ss << cc::string_view(begin, end);
        }
        if constexpr (sizeof(IntType) == 8)
        {
            char buffer[65 + 1 + 1];
            auto const end = buffer + sizeof(buffer);
            auto const begin = unsigned_int_to_binary(value, end);
            ss << cc::string_view(begin, end);
        }
    }
    break;
    case 'B': // binary, with # prefix 0B
    {
        if (args.alternative_mode)
            ss << "0B";

        if constexpr (sizeof(IntType) == 1)
        {
            char buffer[8 + 1 + 1];
            auto const end = buffer + sizeof(buffer);
            auto const begin = unsigned_int_to_binary(value, end);
            ss << cc::string_view(begin, end);
        }
        if constexpr (sizeof(IntType) == 2)
        {
            char buffer[16 + 1 + 1];
            auto const end = buffer + sizeof(buffer);
            auto const begin = unsigned_int_to_binary(value, end);
            ss << cc::string_view(begin, end);
        }
        if constexpr (sizeof(IntType) == 4)
        {
            char buffer[32 + 1 + 1];
            auto const end = buffer + sizeof(buffer);
            auto const begin = unsigned_int_to_binary(value, end);
            ss << cc::string_view(begin, end);
        }
        if constexpr (sizeof(IntType) == 8)
        {
            char buffer[65 + 1 + 1];
            auto const end = buffer + sizeof(buffer);
            auto const begin = unsigned_int_to_binary(value, end);
            ss << cc::string_view(begin, end);
        }
    }
    break;
    case 'o': // octal, with # prefix 0
    {
        if (args.alternative_mode)
            ss << "0";

        if constexpr (sizeof(IntType) == 1)
        {
            char buffer[3 + 1 + 1];
            auto const length = std::snprintf(buffer, sizeof(buffer), "%hho", value);
            ss << cc::string_view(buffer, length);
        }
        if constexpr (sizeof(IntType) == 2)
        {
            char buffer[6 + 1 + 1];
            auto const length = std::snprintf(buffer, sizeof(buffer), "%ho", value);
            ss << cc::string_view(buffer, length);
        }
        if constexpr (sizeof(IntType) == 4)
        {
            char buffer[10 + 1 + 1];
            // the cast prevents a warning on MSVC where 32 bit integer are unsigned long
            auto const length = std::snprintf(buffer, sizeof(buffer), "%o", static_cast<unsigned int>(value));
            ss << cc::string_view(buffer, length);
        }
        if constexpr (sizeof(IntType) == 8)
        {
            char buffer[19 + 1 + 1];
            auto const length = std::snprintf(buffer, sizeof(buffer), "%llo", value);
            ss << cc::string_view(buffer, length);
        }
    }
    break;
    case 'x': // hexadecimal, with # prefix 0x
    {
        if (args.alternative_mode)
        {
            if constexpr (sizeof(IntType) == 1)
            {
                char buffer[3 + 1 + 1];
                auto const length = std::snprintf(buffer, sizeof(buffer), "%#hhx", value);
                ss << cc::string_view(buffer, length);
            }
            if constexpr (sizeof(IntType) == 2)
            {
                char buffer[6 + 1 + 1];
                auto const length = std::snprintf(buffer, sizeof(buffer), "%#hx", value);
                ss << cc::string_view(buffer, length);
            }
            if constexpr (sizeof(IntType) == 4)
            {
                char buffer[10 + 1 + 1];
                // the cast prevents a warning on MSVC where 32 bit integer are unsigned long
                auto const length = std::snprintf(buffer, sizeof(buffer), "%#x", static_cast<unsigned int>(value));
                ss << cc::string_view(buffer, length);
            }
            if constexpr (sizeof(IntType) == 8)
            {
                char buffer[19 + 1 + 1];
                auto const length = std::snprintf(buffer, sizeof(buffer), "%#llx", value);
                ss << cc::string_view(buffer, length);
            }
        }
        else
        {
            if constexpr (sizeof(IntType) == 1)
            {
                char buffer[3 + 1 + 1];
                auto const length = std::snprintf(buffer, sizeof(buffer), "%hhx", value);
                ss << cc::string_view(buffer, length);
            }
            if constexpr (sizeof(IntType) == 2)
            {
                char buffer[6 + 1 + 1];
                auto const length = std::snprintf(buffer, sizeof(buffer), "%hx", value);
                ss << cc::string_view(buffer, length);
            }
            if constexpr (sizeof(IntType) == 4)
            {
                char buffer[10 + 1 + 1];
                // the cast prevents a warning on MSVC where 32 bit integer are unsigned long
                auto const length = std::snprintf(buffer, sizeof(buffer), "%x", static_cast<unsigned int>(value));
                ss << cc::string_view(buffer, length);
            }
            if constexpr (sizeof(IntType) == 8)
            {
                char buffer[19 + 1 + 1];
                auto const length = std::snprintf(buffer, sizeof(buffer), "%llx", value);
                ss << cc::string_view(buffer, length);
            }
        }
    }
    break;
    case 'X': // hexadecimal, with # prefix 0X
    {
        if (args.alternative_mode)
        {
            if constexpr (sizeof(IntType) == 1)
            {
                char buffer[3 + 1 + 1];
                auto const length = std::snprintf(buffer, sizeof(buffer), "%#hhX", value);
                ss << cc::string_view(buffer, length);
            }
            if constexpr (sizeof(IntType) == 2)
            {
                char buffer[6 + 1 + 1];
                auto const length = std::snprintf(buffer, sizeof(buffer), "%#hX", value);
                ss << cc::string_view(buffer, length);
            }
            if constexpr (sizeof(IntType) == 4)
            {
                char buffer[10 + 1 + 1];
                // the cast prevents a warning on MSVC where 32 bit integer are unsigned long
                auto const length = std::snprintf(buffer, sizeof(buffer), "%#X", static_cast<unsigned int>(value));
                ss << cc::string_view(buffer, length);
            }
            if constexpr (sizeof(IntType) == 8)
            {
                char buffer[19 + 1 + 1];
                auto const length = std::snprintf(buffer, sizeof(buffer), "%#llX", value);
                ss << cc::string_view(buffer, length);
            }
        }
        else
        {
            if constexpr (sizeof(IntType) == 1)
            {
                char buffer[3 + 1 + 1];
                auto const length = std::snprintf(buffer, sizeof(buffer), "%hhX", value);
                ss << cc::string_view(buffer, length);
            }
            if constexpr (sizeof(IntType) == 2)
            {
                char buffer[6 + 1 + 1];
                auto const length = std::snprintf(buffer, sizeof(buffer), "%hX", value);
                ss << cc::string_view(buffer, length);
            }
            if constexpr (sizeof(IntType) == 4)
            {
                char buffer[10 + 1 + 1];
                // the cast prevents a warning on MSVC where 32 bit integer are unsigned long
                auto const length = std::snprintf(buffer, sizeof(buffer), "%X", static_cast<unsigned int>(value));
                ss << cc::string_view(buffer, length);
            }
            if constexpr (sizeof(IntType) == 8)
            {
                char buffer[19 + 1 + 1];
                auto const length = std::snprintf(buffer, sizeof(buffer), "%llX", value);
                ss << cc::string_view(buffer, length);
            }
        }
    }
    break;
    default:
        CC_ASSERT(false && "Invalid format string: Unsupported argument type for int type");
    }
}

template <class IntType>
void int_to_string_impl(cc::string_stream& ss, IntType value, parsed_fmt_args const& args)
{
    auto const is_neg = value < 0;
    std::make_unsigned_t<IntType> unsigned_value = is_neg ? -value : value;

    switch (args.sign)
    {
    case ' ':
        ss << (is_neg ? "-" : " ");
        break;
    case '-':
        if (is_neg)
            ss << "-";
        break;
    case '+':
        ss << (is_neg ? "-" : "+");
        break;
    }
    unsigned_to_string_impl(ss, unsigned_value, args);
}

template <class FloatType>
void to_string_float_impl(cc::string_stream& ss, FloatType value, parsed_fmt_args const& args)
{
    // note: currently completely relys on std::sprintf

    cc::string_stream sprintf_args;
    sprintf_args << "%";
    if (args.sign == ' ')
        sprintf_args << " ";
    if (args.sign == '+')
        sprintf_args << "+";
    if (args.alternative_mode)
        sprintf_args << "#";
    if (args.sign_aware_zero_padding)
        sprintf_args << "0";
    if (args.width >= 0)
        to_string(sprintf_args, args.width, "");
    if (args.precision >= 0)
    {
        sprintf_args << ".";
        to_string(sprintf_args, args.precision, "");
    }

    switch (args.type)
    {
    case 0: // default, like g but always one digit after decimal point, when fixed point notation is used
            // note: currently same as g due to limitation of sprintf
        sprintf_args << "g";
        break;
    case 'a': // hexadecimal 0x prefix, 'p' exponent, lowercase letters
        sprintf_args << "a";
        break;
    case 'A': // hexadecimal 0x prefix, 'P' exponent, uppercase letters
        sprintf_args << "A";
        break;
    case 'e': // scientific exponent notation, 'e' exponent
        sprintf_args << "e";
        break;
    case 'E': // scientific exponent notation, 'E' exponent
        sprintf_args << "E";
        break;
    case 'f': // fixed-point
        sprintf_args << "f";
        break;
    case 'F': // fixed-point, but "nan" and "inf" become "NAN" and "INF"
        sprintf_args << "F";
        break;
    case 'g': // general form, precision significant digits and fixed-point or exponent notation depending on magnitute
        sprintf_args << "g";
        break;
    case 'G': // same as 'g' but uppercase version
        sprintf_args << "G";
        break;
    default:
        CC_ASSERT(cc::always_false<FloatType> && "Invalid format string: Unsupported argument type for float type");
    }

    // Note: We cannot explicitly convert float as long as we do not run our own float conversion, because sprintf will automatically convert float to double
    constexpr size_t buffer_size = std::is_same_v<FloatType, float> || std::is_same_v<FloatType, double> ? 31 : 41;
    char buffer[buffer_size];
    auto const s = sprintf_args.to_string();
    auto res = std::snprintf(buffer, sizeof(buffer), sprintf_args.to_string().c_str(), value);
    CC_ASSERT(res >= 0);
    ss << cc::string_view(buffer, res);
}
}

void cc::to_string(cc::string_stream& ss, char value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    if (args.type == 0 || args.type == 'c')
    { // handle as character
        ss << string_view(&value, 1);
    }
    else
    { // handle as int
        CC_ASSERT(is_int_type(args.type) && "Invalid format string: wrong argument type for char");
        int_to_string_impl(ss, value, args);
    }
}
void cc::to_string(cc::string_stream& ss, bool value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    if (args.type == 0) // default
    {
        ss << (value ? "true" : "false");
    }
    else
    { // handle as int
        CC_ASSERT(is_int_type(args.type) && "Invalid format string: wrong argument type for char");
        int_to_string_impl(ss, int(value), args);
    }
}
void cc::to_string(cc::string_stream& ss, char const* value, cc::string_view fmt_str)
{
    if (value)
    {
        cc::to_string(ss, string_view(value), fmt_str);
    }
    else
    {
        ss << "[nullptr]";
    }
}
void cc::to_string(cc::string_stream& ss, cc::string_view value, cc::string_view fmt_str)
{
    if (fmt_str.empty())
    {
        ss << value;
        return;
    }

    auto const args = parse_args(fmt_str);

    if (args.precision >= 0 && args.precision <= int(value.size()))
    {
        ss << cc::string_view(value.data(), args.precision);
        return;
    }

    if (args.width > int(value.size()))
    {
        auto const total_padding = args.width - value.size();
        switch (args.align)
        {
        case '<':
        {
            ss.reserve(total_padding + value.size());
            ss << value;
            for (auto i = 0u; i < total_padding; ++i)
                ss << cc::string_view(&args.fill, 1);
        }
        break;
        case '>':
        {
            for (auto i = 0u; i < total_padding; ++i)
                ss << cc::string_view(&args.fill, 1);
            ss << value;
        }
        break;
        case '^':
        {
            auto const padding_right = total_padding / 2;
            auto const padding_left = padding_right + (total_padding % 2 == 1);
            for (auto i = 0u; i < padding_left; ++i)
                ss << cc::string_view(&args.fill, 1);
            ss << value;
            for (auto i = 0u; i < padding_right; ++i)
                ss << cc::string_view(&args.fill, 1);
        }
        break;
        }
    }
}
void cc::to_string(cc::string_stream& ss, nullptr_t, cc::string_view fmt_str)
{
    CC_ASSERT(fmt_str.empty()); // for now
    ss << "[nullptr]";
}
void cc::to_string(cc::string_stream& ss, void* value, cc::string_view fmt_str)
{
    CC_ASSERT(fmt_str.empty()); // for now
    if (value)
    {
        // for now print as hex value
        cc::to_string(ss, intptr_t(value), "#x");
    }
    else
    {
        ss << "[nullptr]";
    }
}
void cc::to_string(cc::string_stream& ss, std::byte value, cc::string_view fmt_str)
{
    CC_ASSERT(fmt_str.empty()); // for now
    ss << to_string(value);
}
void cc::to_string(cc::string_stream& ss, signed char value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    int_to_string_impl(ss, value, args);
}
void cc::to_string(cc::string_stream& ss, short value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    int_to_string_impl(ss, value, args);
}
void cc::to_string(cc::string_stream& ss, int value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    int_to_string_impl(ss, value, args);
}
void cc::to_string(cc::string_stream& ss, long value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    int_to_string_impl(ss, value, args);
}
void cc::to_string(cc::string_stream& ss, long long value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    int_to_string_impl(ss, value, args);
}
void cc::to_string(cc::string_stream& ss, unsigned char value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    unsigned_to_string_impl(ss, value, args);
}
void cc::to_string(cc::string_stream& ss, unsigned short value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    unsigned_to_string_impl(ss, value, args);
}
void cc::to_string(cc::string_stream& ss, unsigned int value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    unsigned_to_string_impl(ss, value, args);
}
void cc::to_string(cc::string_stream& ss, unsigned long value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    unsigned_to_string_impl(ss, value, args);
}
void cc::to_string(cc::string_stream& ss, unsigned long long value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    unsigned_to_string_impl(ss, value, args);
}
void cc::to_string(cc::string_stream& ss, float value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    to_string_float_impl(ss, value, args);
}
void cc::to_string(cc::string_stream& ss, double value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    to_string_float_impl(ss, value, args);
}
void cc::to_string(cc::string_stream& ss, long double value, cc::string_view fmt_str)
{
    auto const args = parse_args(fmt_str);
    to_string_float_impl(ss, value, args);
}
