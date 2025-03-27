#include "kekex.h"
#include <vector>

namespace kekex {



enum TokenType {
    LITERAL = 0,
    ALTERNATIVE,
    CLASS_OPEN,
    CLASS_CLOSE,
    QUANTIFIER_ZOM = 0b100,
    QUANTIFIER_ZOM_NONGREEDY,
    QUANTIFIER_OOM = 0b110,
    QUANTIFIER_OOM_NONGREEDY
};

class TokenTree {
    private:
        TokenType type;
        // TODO Make type concrete
        void* data;
        std::vector<TokenTree> children;
    public:
        // TODO Determine parameters
        void create_child();
};

class Token {
    public:
        union data {
            const char literal;
            const u_int16_t repetitions;
        };
        TokenType type;
};

Pattern Pattern::compile(std::string& expression, int options) {
    
}

}