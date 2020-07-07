#pragma once

#include <clean-core/fwd.hh>

namespace cc
{
string to_string(char value);
string to_string(bool value);
string to_string(char const* value);
string to_string(string_view value);
string to_string(nullptr_t);

string to_string(void* value);

string to_string(std::byte value);

string to_string(signed char value);
string to_string(short value);
string to_string(int value);
string to_string(long value);
string to_string(long long value);
string to_string(unsigned char value);
string to_string(unsigned short value);
string to_string(unsigned int value);
string to_string(unsigned long value);
string to_string(unsigned long long value);

string to_string(float value);
string to_string(double value);
string to_string(long double value);

string to_string(char value, string_view fmt_str);
string to_string(bool value, string_view fmt_str);
string to_string(char const* value, string_view fmt_str);
string to_string(string_view value, string_view fmt_str);
string to_string(nullptr_t, string_view fmt_str);

string to_string(void* value, string_view fmt_str);

string to_string(std::byte value, string_view fmt_str);

string to_string(signed char value, string_view fmt_str);
string to_string(short value, string_view fmt_str);
string to_string(int value, string_view fmt_str);
string to_string(long value, string_view fmt_str);
string to_string(long long value, string_view fmt_str);
string to_string(unsigned char value, string_view fmt_str);
string to_string(unsigned short value, string_view fmt_str);
string to_string(unsigned int value, string_view fmt_str);
string to_string(unsigned long value, string_view fmt_str);
string to_string(unsigned long long value, string_view fmt_str);

string to_string(float value, string_view fmt_str);
string to_string(double value, string_view fmt_str);
string to_string(long double value, string_view fmt_str);

void to_string(stream_ref<char> ss, char value);
void to_string(stream_ref<char> ss, bool value);
void to_string(stream_ref<char> ss, char const* value);
void to_string(stream_ref<char> ss, string_view value);
void to_string(stream_ref<char> ss, nullptr_t);

void to_string(stream_ref<char> ss, void* value);

void to_string(stream_ref<char> ss, std::byte value);

void to_string(stream_ref<char> ss, signed char value);
void to_string(stream_ref<char> ss, short value);
void to_string(stream_ref<char> ss, int value);
void to_string(stream_ref<char> ss, long value);
void to_string(stream_ref<char> ss, long long value);
void to_string(stream_ref<char> ss, unsigned char value);
void to_string(stream_ref<char> ss, unsigned short value);
void to_string(stream_ref<char> ss, unsigned int value);
void to_string(stream_ref<char> ss, unsigned long value);
void to_string(stream_ref<char> ss, unsigned long long value);

void to_string(stream_ref<char> ss, float value);
void to_string(stream_ref<char> ss, double value);
void to_string(stream_ref<char> ss, long double value);

void to_string(stream_ref<char> ss, char value, string_view fmt_str);
void to_string(stream_ref<char> ss, bool value, string_view fmt_str);
void to_string(stream_ref<char> ss, char const* value, string_view fmt_str);
void to_string(stream_ref<char> ss, string_view value, string_view fmt_str);
void to_string(stream_ref<char> ss, nullptr_t, string_view fmt_str);

void to_string(stream_ref<char> ss, void* value, string_view fmt_str);

void to_string(stream_ref<char> ss, std::byte value, string_view fmt_str);

void to_string(stream_ref<char> ss, signed char value, string_view fmt_str);
void to_string(stream_ref<char> ss, short value, string_view fmt_str);
void to_string(stream_ref<char> ss, int value, string_view fmt_str);
void to_string(stream_ref<char> ss, long value, string_view fmt_str);
void to_string(stream_ref<char> ss, long long value, string_view fmt_str);
void to_string(stream_ref<char> ss, unsigned char value, string_view fmt_str);
void to_string(stream_ref<char> ss, unsigned short value, string_view fmt_str);
void to_string(stream_ref<char> ss, unsigned int value, string_view fmt_str);
void to_string(stream_ref<char> ss, unsigned long value, string_view fmt_str);
void to_string(stream_ref<char> ss, unsigned long long value, string_view fmt_str);

void to_string(stream_ref<char> ss, float value, string_view fmt_str);
void to_string(stream_ref<char> ss, double value, string_view fmt_str);
void to_string(stream_ref<char> ss, long double value, string_view fmt_str);
}
