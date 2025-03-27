#ifndef KEKEX_H
#define KEKEX_H
/**
 * @file kekex.h
 */
#include <string>
#include <vector>

namespace kekex {

class Pattern;
class Group;
class Match;

/**
 * @enum MatchOptions
 * @brief Allows to customize the behavior of Regular Expressions before
 * compilation.
 * @see kekex::compile
 */
enum MatchOptions {
    GLOBAL = 1,
    MULTI_LINE = 2,
    INSENSITIVE = 4,
};

class Pattern final {
    public:
        ~Pattern();
        std::vector<Match> match_against(const std::string &to_match);
        static Pattern compile(std::string &expression, int options);
    private:
        Pattern();
};
class Group final {
    public:
        int index();
        const std::string& substring();
    private:
        int mIndex;
        std::string& mPattern;
};

class Match final {
    public:
        std::size_t start();
        std::size_t end();
        Group& operator[](std::size_t idx) const;
    private:
        std::size_t mStart;
        std::size_t mEnd;
};

};
#endif