#include "uincampus/regles.hpp"
#include "uincampus/saisie.hpp"
#include "uincampus/version.hpp"
#include <cstdlib>
#include <format>
#include <print>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace {

enum class Suite { Continuer, Terminer, Erreur };

void afficherAide() {
  std::println("Usage : uin-campus [--version] [--aide]");
  std::println("  --version  affiche la version");
  std::println("  --aide     affiche cette aide");
}

[[nodiscard]] Suite traiterOptions(std::span<char *> arguments) {
  if (arguments.size() <= 1) {
    return Suite::Continuer;
  }
  for (const std::string_view option : arguments.subspan(1)) {
    if (option == "--version") {
      std::println("uin-campus {}", uin::version());
      return Suite::Terminer;
    }
    if (option == "--aide") {
      afficherAide();
      return Suite::Terminer;
    }
    std::println(stderr, "Option inconnue : {}", option);
    afficherAide();
    return Suite::Erreur;
  }
  return Suite::Continuer;
}

} // namespace

int main(int argc, char *argv[]) {
  switch (traiterOptions(std::span{argv, static_cast<std::size_t>(argc)})) {
  case Suite::Terminer:
    return EXIT_SUCCESS;
  case Suite::Erreur:
    return EXIT_FAILURE;
  case Suite::Continuer:
    break;
  }

  std::println("UIN-Campus {} - Calcul de la moyenne d'un etudiant\n",
               uin::version());

  const std::string nom = uin::lireTexte("Nom de l'etudiant : ");
  const int nbNotes = uin::lireEntier("Nombre de notes : ", 1, 100);

  std::vector<double> notes;
  notes.reserve(static_cast<std::size_t>(nbNotes));
  for (int i{1}; i <= nbNotes; ++i) {
    notes.push_back(uin::lireNote(std::format("Note {} : ", i)));
  }

  double somme{0.0};
  for (double note : notes) {
    somme += note;
  }
  const double moyenne = somme / static_cast<double>(notes.size());
  const uin::Mention mention = uin::mentionPour(moyenne);

  std::println("\n{:-<40}", "");
  std::println("{:<20}{:>20}", "Etudiant", nom);
  std::println("{:<20}{:>20}", "Nombre de notes", notes.size());
  std::println("{:<20}{:>20.2f}", "Moyenne", moyenne);
  std::println("{:<20}{:>20}", "Mention", uin::libelle(mention));
  std::println("{:<20}{:>20}", "Decision",
               moyenne >= uin::seuilValidation ? "Valide" : "Non valide");
  std::println("{:-<40}", "");
  return EXIT_SUCCESS;
}