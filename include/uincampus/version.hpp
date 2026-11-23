#pragma once
#include <string>
#include <string_view>

namespace uin {

/// Numéro de version du projet (ex. "0.1.0").
[[nodiscard]] std::string_view version();

/// Projet, version, compilateur, norme, configuration.
[[nodiscard]] std::string informationsConstruction();

} // namespace uin
