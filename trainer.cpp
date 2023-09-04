// This is an introductory comment

#include "trainer.hpp"
#include <iostream>
#include "skill.hpp"

Trainer::Trainer() {
    selectedProfemon = nullptr;
}


// Trainer constructor
Trainer::Trainer(std::vector<Profemon> profemons) {
    selectedProfemon = nullptr;

    for (auto& profemon : profemons) {
        if (!contains(profemon.getName())) {
            // Add the profémon to the team if there's an empty slot
            for (auto& prof : team) {
                if (prof.getName() == "Undefined") {
                    
                    prof = profemon;
                    // profedex.push_back(profemon);
                    break;
                }
            }
            // set the profemon at 0 index of team array to accompany the Trainer
                            // team[0] = profemon;

            // Add the profémon to the profédex
            profedex.push_back(profemon);
        }
    }
    selectedProfemon = &team[0];
    // Set the profémon at the 0th index to accompany the trainer
    // for (auto& prof : team) {
    //     if (prof.getName() != "Undefined") {
    //         selectedProfemon = &team[0];
    //         std::cout << "***************" << std::endl;
    //         std::cout << selectedProfemon->getName()<< std::endl;

    //         break;
    //     }
    // }
}

bool Trainer::contains(std::string name) {
    for (auto& profemon : profedex) {
        if (profemon.getName() == name) {
            return true;
        }
    }
    for (auto& profemon : team) {
        if (profemon.getName() == name) {
            return true;
        }
    }
    return false;
}

bool Trainer::addProfemon(Profemon profemon) {
    if (!contains(profemon.getName())) {
        for (auto& prof : team) {
            if (prof.getName() == "Undefined") {
                prof = profemon;
                return true;
            }
        }
        profedex.push_back(profemon);
        return true;
    }
    return false;
}


bool Trainer::removeProfemon(std::string name) {
    for (auto& prof : team) {
        if (prof.getName() == name) {
            prof = Profemon();
            return true;
        }
    }
    for (auto it = profedex.begin(); it != profedex.end(); ++it) {
        if (it->getName() == name) {
            profedex.erase(it);
            return true;
        }
    }
    return false;
}

void Trainer::setTeamMember(int slot, std::string name) {
    if (slot < 0 || slot >= 4) {
        return;
    }
    for (auto& prof : team) {
        if (prof.getName() == name) {
            std::swap(prof, team[slot]);
            return;
        }
    }
    for (auto it = profedex.begin(); it != profedex.end(); ++it) {
        if (it->getName() == name) {
            std::swap(*it, team[slot]);
            profedex.erase(it);
            return;
        }
    }
}

bool Trainer::chooseProfemon(int slot) {
    if (slot >= 0 && slot < 4 && team[slot].getName() != "Undefined") {
        selectedProfemon = &team[slot];
        return true;
    }
    return false;
}

Profemon Trainer::getCurrent() {
    if (selectedProfemon == nullptr) {
        return Profemon();
    }
    return *selectedProfemon;
}

std::vector<Profemon> Trainer::getProfedex() {
    return profedex;
}

void Trainer::printProfedex() {
    for (auto& profemon : profedex) {
        profemon.printProfemon(false);
        std::cout << std::endl;
    }
    
}


std::string Trainer:: getSpecialtyString(int specialty) {
    switch (specialty) {
        case ML:
            return "ML";
        case SOFTWARE:
            return "SOFTWARE";
        case HARDWARE:
            return "HARDWARE";
        default:
            return "UNKNOWN";
    }
}

void Trainer::printTeam() {
    for (auto& profemon : team) {
        if (profemon.getName() != "Undefined") {
            profemon.printProfemon(true);
            std::cout << std::endl;
        }
    }
}
