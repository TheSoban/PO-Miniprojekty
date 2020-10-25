#ifndef BOARD_H
#define BOARD_H
#include <string>
#include "Date.h"
#include "Logger.h"
#include "Stopper.h"

class BoardOfDirectors : Logger, public Stopper {
  private:
    int* numberOfMembers;
    double* averageAmountOfResolutions;
    int* numberOfResolutionEnties;
    float* currentBudget;
    Date* scheduledAssembly;
    Date* lastAssembly;
    std::string* companyName;
  public:
    BoardOfDirectors();
    BoardOfDirectors(int);
    BoardOfDirectors(const BoardOfDirectors &board);
    BoardOfDirectors(BoardOfDirectors &&board);
    ~BoardOfDirectors();
    void setNumberOfMembers(int amount);
    void dismissNumberOfMembers(int amount);
    int getNumberOfMembers();
    void insertNewResolutionEntry(int value);
    double getAverageAmountOfResolutions();
    void increaseCurrentBudget(float increase);
    void decreaseCurrentBudget(float decrease);
    float getCurrentBudget();
    bool lastAssemblyExists();
    void setScheduledAssembly(std::string date);
    void overrideAssembly();
    Date getLastAssembly();
    void setCompanyName(std::string name);
    std::string getCompanyName();
};

#endif