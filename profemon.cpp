// This is an introductory comment

#include <string>
#include "skill.hpp"
#include "profemon.hpp"
#include <iostream>

 
Profemon::Profemon() : name("Undefined"), level(0), requiredexperience(50), currentexperience(0), max_health(0.0), specialty(ML) {
    for (int i = 0; i < 3; i++) {
        learnedSkills[i] = nullptr;
    }
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty)
    : name(name), level(0), requiredexperience(50), currentexperience(0), max_health(max_health), specialty(specialty) {
    for (int i = 0; i < 3; i++) {
        learnedSkills[i] = nullptr;
    }
}


std::string Profemon::getName() { return name; }

Specialty Profemon::getSpecialty() {
    return specialty;
}

int Profemon::getLevel() { return level; }

double Profemon:: getMaxHealth() { return max_health; }


Skill Profemon::getSkill(int slot) {
    return (slot >= 0 && slot < 3 && learnedSkills[slot] != nullptr) ? *learnedSkills[slot] : Skill();
}

bool Profemon::setName(std::string name) {
    if (!name.empty() && isupper(name[0])) {
        this->name = name;
        return true;
    }
    return false;
}

void Profemon::levelUp(int exp) {
    currentexperience += exp;
    while (currentexperience >= requiredexperience) {
        level++;
        currentexperience -= requiredexperience;
        requiredexperience += (specialty == ML) ? 10 : ((specialty == SOFTWARE) ? 15 : 20);
    }
}

bool Profemon::learnSkill(int slot, Skill skill) {
    if (slot >= 0 && slot < 3 && skill.getSpecialty() == specialty) {
        learnedSkills[slot] = new Skill(skill);
        return true;
    }
    return false;
}

void Profemon::printProfemon(bool print_skills) {
std::string specialtyStr;
    switch (specialty) {
        case ML:
            specialtyStr = "ML";
            break;
        case SOFTWARE:
            specialtyStr = "SOFTWARE";
            break;
        case HARDWARE:
            specialtyStr = "HARDWARE";
            break;
        default:
            specialtyStr = "UNKNOWN";
            break;
    }
    std::cout << name << " (" << specialtyStr << ") | LVL " << level << " | EXP " << currentexperience << "/"
              << requiredexperience << " | HP " << max_health << std::endl;

    if (print_skills) {
        for (int i = 0; i < 3; i++) {
            Skill* skill = learnedSkills[i];
            if (skill != nullptr && skill->getName() != "Undefined") {
                std::cout << "    " << skill->getName() << " (" << skill->getTotalUses() << ") : "
                          << skill->getDescription() << std::endl;
            }
        }
    }
}