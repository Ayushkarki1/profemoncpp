
#include "department.hpp"
#include "trainer.hpp"
#include "profemon.hpp"

// MLDepartment implementation
MLDepartment::MLDepartment(std::vector<Profemon> profemons) : Trainer() {
    for (auto& profemon : profemons) {
        if (profemon.getSpecialty() == ML) {
            addProfemon(profemon);
        }
    }
}

bool MLDepartment::addProfemon(Profemon profemon) {
    if (profemon.getSpecialty() == ML) {
        return Trainer::addProfemon(profemon);
    }
    return false;
}

// SoftwareDepartment implementation
SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons) : Trainer() {
    for (auto& profemon : profemons) {
        if (profemon.getSpecialty() == SOFTWARE) {
            addProfemon(profemon);
        }
    }
}

bool SoftwareDepartment::addProfemon(Profemon profemon) {
    if (profemon.getSpecialty() == SOFTWARE) {
        return Trainer::addProfemon(profemon);
    }
    return false;
}

// HardwareDepartment implementation
HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons) : Trainer() {
    for (auto& profemon : profemons) {
        if (profemon.getSpecialty() == HARDWARE) {
            addProfemon(profemon);
        }
    }
}

bool HardwareDepartment::addProfemon(Profemon profemon) {
    if (profemon.getSpecialty() == HARDWARE) {
        return Trainer::addProfemon(profemon);
    }
    return false;
}
