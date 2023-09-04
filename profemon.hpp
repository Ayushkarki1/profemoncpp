// This is an introductory comment
#ifndef PROFEMON_HPP
#define PROFEMON_HPP
#include <string>
enum Specialty { ML /*Machine Learning*/,SOFTWARE /* Software Development*/, HARDWARE /* Hardware Engineering*/};
class Skill;
class Profemon {

private:
    std::string name; int level; int requiredexperience; int currentexperience; double max_health; Specialty specialty; Skill* learnedSkills[3];
public:
    Profemon();
    Profemon(std::string name, double max_health, Specialty specialty);
    std::string getName();
    Specialty getSpecialty();
    int getLevel();
    double getMaxHealth();
    int getCurrentExp() { return currentexperience; }
    int getRequiredExp() { return requiredexperience; }  
    Skill getSkill(int slot);
    bool setName(std::string name);
    void levelUp(int exp);
    bool learnSkill(int slot, Skill skill);
    void printProfemon(bool print_skills);
};
#endif