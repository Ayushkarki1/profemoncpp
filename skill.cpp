// This is an introductory comment

#include "skill.hpp"

/*The Skill class must have the following in it's public access modifier:

    @post       :   Initializes the name and description of the skill as
                    "Undefined". Initializes the total uses of the skill
                    and the skill specialty as -1.
  
Skill();*/

class Skill;
Skill::Skill(){
    name = "Undefined";
    description = "Undefined";
    totalUses = -1;
    specialty = -1;
}

/**
    @post       :   Parameterized constructor sets the corresponding
                    data members equal to the respective parameters.
Skill(std::string name, std::string description, int specialty, int uses);*/

Skill::Skill(std::string name, std::string description, int specialty, int uses) {
    this->name = name;
    this->description = description;
    totalUses = uses;
    this->specialty = specialty;
}

/**
    return     :   name of the skill.
std::string getName();*/


std::string Skill::getName() {
    return name;
}
/**
    return     :   description of the skill.
std::string getDescription();*/
std::string Skill::getDescription() {
    return description;
}
/**
    return     :   total uses of the skill.
int getTotalUses();*/
int Skill::getTotalUses() {
    return totalUses;
}
/**
    return     :   specialty of the skill.
int getSpecialty();*/
int Skill::getSpecialty() {
    return specialty;
}
/**
    using void fuction type which results in no return
    post       :   set the name of the skill equal to the given parameter.
void setName(std::string name);*/
void Skill::setName(std::string name) {
    this->name = name;
}
/*using bool data for the coditional statement-Returns false if the description length is less then 25 else returns true*/
bool Skill::setDescription(std::string description) {
    if (description.length() >= 25) {
        this->description = description;
        return true;
    }
    return false;
}

bool Skill::setTotalUses(int uses) {
    if (uses <= 50) {
        totalUses = uses;
        return true;
    }
    return false;
}

bool Skill::setSpecialty(int specialty) {
    if (specialty >= 0 && specialty <= 2) {
        this->specialty = specialty;
        return true;
    }
    return false;
}
