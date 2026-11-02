ocat << 'EOF' > app/main.cpp
#include "uincampus/version.hpp"
#include <print>
int main()
{
    std::println("Bienvenue sur uin-campus !");
    std::println("Version {}", uin::version());
}
EOF
