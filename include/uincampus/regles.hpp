#pragma once
#include <cstddef>
#include <string_view>

namespace uin {

inline constexpr double noteMin = 0.0;
inline constexpr double noteMax = 20.0;
inline constexpr double seuilValidation = 10.0;
inline constexpr std::size_t nbMentions = 5;

enum class Mention { Ajourne, Passable, AssezBien, Bien, TresBien };

constexpr bool estNoteValide(double note)
{
    return note >= noteMin && note <= noteMax;
}

Mention mentionPour(double moyenne);
std::string_view libelle(Mention mention);

} // namespace uin
EOF

cat > src/regles.cpp << 'EOF'
#include "uincampus/regles.hpp"

namespace uin {

Mention mentionPour(double moyenne)
{
    if (moyenne < seuilValidation) { return Mention::Ajourne; }
    if (moyenne < 12.0) { return Mention::Passable; }
    if (moyenne < 14.0) { return Mention::AssezBien; }
    if (moyenne < 16.0) { return Mention::Bien; }
    return Mention::TresBien;
}

std::string_view libelle(Mention mention)
{
    using enum Mention;
    switch (mention) {
    case Ajourne: return "Ajourné";
    case Passable: return "Passable";
    case AssezBien: return "Assez bien";
    case Bien: return "Bien";
    case TresBien: return "Très bien";
    }
    return "Inconnue";
}

} // namespace uin
EOF