// This is an introductory comment

#ifndef SKILL_HPP
#define SKILL_HPP
#include <string>

class Skill {
    
private:
    std::string name;
    std::string description;
    int totalUses;
    int specialty;

public:
   
    Skill();

    Skill(std::string name, std::string description, int specialty, int uses);

    std::string getName();

    std::string getDescription();

    int getTotalUses();

    int getSpecialty();

    void setName(std::string name);

    bool setDescription(std::string description);

    bool setTotalUses(int uses);

    bool setSpecialty(int specialty);
    
};

#endif