#pragma once
#include <fstream>
#include <string>

class Logger {
private:
    std::ofstream logFile;
    std::string filename;

    // Constructeur privé pour empêcher l'instanciation multiple
    Logger(const std::string& file);

public:
    // Méthode pour obtenir l'instance unique du logger (singleton)
    static Logger& getInstance(const std::string& file = "default_log.txt", bool console_output = false);

    // Méthode pour obtenir un flux vers le log
    std::ostream& getOutputStream();

    // Méthode pour obtenir un flux de lecture sur le fichier de log
    std::ifstream getInputStream() const;

	void clearLog();

    // Surcharge de l'opérateur << pour écrire à la fois dans le fichier et la console si nécessaire
    template <typename T>
    Logger& operator<<(const T& msg);

    // Destructeur : ferme le fichier proprement
    ~Logger();

    // Supprimer les méthodes de copie pour garantir l'unicité de l'instance
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};
