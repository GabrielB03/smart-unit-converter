#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <optional>
#include <utility>

class UnitConverter
{
public:
    std::optional<std::string> convert(const std::string &input);

private:
    std::string toLower(const std::string &str);
    std::string normalizeUnit(const std::string &unit);
    std::pair<double, std::string> parseInput(const std::string &input);

    std::string convertTemperature(double value, const std::string &unit);
    std::string convertLength(double value, const std::string &unit);
    std::string convertMass(double value, const std::string &unit);
    std::string convertTime(double value, const std::string &unit);
};

#endif