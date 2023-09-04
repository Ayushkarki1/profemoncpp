#ifndef TRAINER_HPP
#define TRAINER_HPP

#include "profemon.hpp"
#include <vector>

class Trainer {
protected:
    std::vector<Profemon> profedex;
    Profemon team[4];
    Profemon* selectedProfemon;

public:
    Trainer();
    Trainer(std::vector<Profemon> profemons);
    bool contains(std::string name);
    bool addProfemon(Profemon profemon);
    bool removeProfemon(std::string name);
    void setTeamMember(int slot, std::string name);
    bool chooseProfemon(int slot);
    Profemon getCurrent();
    std::vector<Profemon> getProfedex();
    void printProfedex();
    void printTeam();
    std::string getSpecialtyString(int specialty);

};

#endif