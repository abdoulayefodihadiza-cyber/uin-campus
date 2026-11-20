#include "uincampus/regles.hpp"
#include "uincampus/saisie.hpp"
#include "uincampus/version.hpp"
#include <format>
#include <print>
#include <string>
#include <vector>

int main() {
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
}