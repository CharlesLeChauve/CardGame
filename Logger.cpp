#include "Logger.hpp"
#include <stdexcept>
#include <iostream>

// Constructeur privé pour empêcher l'instanciation multiple
Logger::Logger(const std::string& file) : filename(file) {
    logFile.open(filename, std::ios::out | std::ios::app);
    if (!logFile.is_open()) {
        throw std::runtime_error("Unable to open log file: " + filename);
    }
}

// Méthode pour obtenir l'instance unique du logger (singleton)
Logger& Logger::getInstance(const std::string& file, bool console_output) {
    static Logger instance(file);  // Création unique de l'instance
    return instance;
}

// Méthode pour obtenir un flux vers le log
std::ostream& Logger::getOutputStream() {
    return logFile;
}

// Méthode pour obtenir un flux de lecture sur le fichier de log
std::ifstream Logger::getInputStream() const {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Unable to open log file for reading: " + filename);
    }
    return inputFile;  // Renvoie un flux ifstream
}

// Surcharge de l'opérateur << pour écrire à la fois dans le fichier et la console si nécessaire
template <typename T>
Logger& Logger::operator<<(const T& msg) {
    if (logFile.is_open()) {
        logFile << msg;
    }
    return *this;
}

void Logger::clearLog() {
    // Ouvrir le fichier en mode troncature pour effacer tout le contenu
    std::ofstream logfile(filename, std::ios::out | std::ios::trunc);
    if (!logfile.is_open()) {
        std::cerr << "Unable to open log file for clearing." << std::endl;
        return;
    }
    logfile.close();  // Fermer immédiatement après avoir tronqué le contenu
}


// Destructeur : ferme le fichier proprement
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}
