#include <iostream>
#include <vector>
#include "../lib/IDgenerator.h"

#define BOLD "\033[1m"
#define RESET "\033[0m"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"

class IdentityVerifier{
public:
    bool verifyCapCha();
};