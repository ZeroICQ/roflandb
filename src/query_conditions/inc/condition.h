#pragma once

#include <string>
#include <variant>
#include <utility>

namespace cond{

enum SimpleConditionType{
    EQUAl,
    NOT_EQUAL,
    GREATER,
    LESS,
    GREATER_EQUALS,
    LESS_EQUAL
};
//HOW TO USE DIS SHIT
//auto condOR = cond::Condition();
//auto cond = cond::Condition(cond::AND, "ababaca", 12);
//std::cout << std::get<int>(cond.value());

//between column and value
class Condition {
public:
    Condition() = default;
    Condition(SimpleConditionType type, std::string col_name, std::variant<int, std::string> value) :
            type_(type), column_name_(std::move(col_name)), value_(std::move(value)) {}

    void column_name(std::string name) { column_name_ = name; }
    std::string column_name() const { return column_name_; }

    void type(SimpleConditionType type) { type_ = type; }
    SimpleConditionType type() const { return type_; }

    void value(std::variant<int, std::string> value) { value_ = value; }
    std::variant<int, std::string> value() const { return value_; }


private:
    SimpleConditionType type_;
    std::string column_name_;
    std::variant<int, std::string> value_;

};

} //namespace cond