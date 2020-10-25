#include "BoardOfDirectors.h"
#include <iostream>
#include <string>

BoardOfDirectors::BoardOfDirectors():
  numberOfMembers(nullptr), 
  averageAmountOfResolutions(nullptr), 
  numberOfResolutionEnties(nullptr), 
  currentBudget(nullptr), 
  scheduledAssembly(nullptr),
  lastAssembly(nullptr),
  companyName(nullptr) {
    this->reset();
    this->log("Default Constructor");
  };

BoardOfDirectors::BoardOfDirectors(int numberOfMembers): 
  numberOfMembers(nullptr), 
  averageAmountOfResolutions(nullptr), 
  numberOfResolutionEnties(nullptr), 
  currentBudget(nullptr), 
  scheduledAssembly(nullptr),
  lastAssembly(nullptr),
  companyName(nullptr) {
    this->reset();
    this->log("Parameterized Constructor");
    this->numberOfMembers = new int(numberOfMembers);
}

BoardOfDirectors::~BoardOfDirectors() {
  this->log("Destructor");
  if(this->numberOfMembers != nullptr) delete numberOfMembers;
  if(this->averageAmountOfResolutions != nullptr) delete averageAmountOfResolutions;
  if(this->numberOfResolutionEnties != nullptr) delete numberOfResolutionEnties;
  if(this->currentBudget != nullptr) delete currentBudget;
  if(this->scheduledAssembly != nullptr) delete scheduledAssembly;
  if(this->lastAssembly != nullptr) delete lastAssembly;
  if(this->companyName != nullptr) delete companyName;
}

BoardOfDirectors::BoardOfDirectors(const BoardOfDirectors &board) {
  this->log("Copy Constructor");
  this->numberOfMembers = (board.numberOfMembers == nullptr ? nullptr : new int(*board.numberOfMembers));
  this->averageAmountOfResolutions = (board.averageAmountOfResolutions == nullptr ? nullptr : new double(*board.averageAmountOfResolutions));
  this->numberOfResolutionEnties = (board.numberOfResolutionEnties == nullptr ? nullptr : new int(*board.numberOfResolutionEnties));
  this->currentBudget = (board.currentBudget == nullptr ? nullptr : new float(*board.currentBudget));
  this->scheduledAssembly = (board.scheduledAssembly == nullptr ? nullptr : new Date(*board.scheduledAssembly));
  this->lastAssembly = (board.lastAssembly == nullptr ? nullptr : new Date(*board.lastAssembly));
  this->companyName = (board.companyName == nullptr ? nullptr : new std::string(*board.companyName));
};

BoardOfDirectors::BoardOfDirectors(BoardOfDirectors &&board) {
  this->log("Move Constructor");
  this->numberOfMembers = std::move(board.numberOfMembers);
  this->averageAmountOfResolutions = std::move(board.averageAmountOfResolutions);
  this->numberOfResolutionEnties = std::move(board.numberOfResolutionEnties);
  this->currentBudget = std::move(board.currentBudget);
  this->scheduledAssembly = std::move(board.scheduledAssembly);
  this->lastAssembly = std::move(board.lastAssembly);
  this->companyName = std::move(board.companyName);
  board.numberOfMembers = nullptr;
  board.averageAmountOfResolutions = nullptr;
  board.numberOfResolutionEnties = nullptr;
  board.currentBudget = nullptr;
  board.scheduledAssembly = nullptr;
  board.lastAssembly = nullptr;
  board.companyName = nullptr;
}

int BoardOfDirectors::getNumberOfMembers() {
  this->start();
  this->log("Get Number Of Members");
  this->stop();
  return *(this->numberOfMembers);
}

void BoardOfDirectors::setNumberOfMembers(int amount) {
  this->start();
  this->log("Set Number Of Members");
  if(this->numberOfMembers == nullptr) this->numberOfMembers = new int(amount);
  else *(this->numberOfMembers) = amount;
  this->stop();
}

void BoardOfDirectors::dismissNumberOfMembers(int amount) {
  this->start();
  this->log("Dismiss Number Of Members");
  if(amount > this->getNumberOfMembers()) std::cout << "You can't dismiss more members then the board contains." << std::endl;
  else this->setNumberOfMembers(this->getNumberOfMembers() - amount);
  this->stop();
}

void BoardOfDirectors::insertNewResolutionEntry(int value) {
  this->start();
  this->log("Insert New Resolution Entry");
  if(this->averageAmountOfResolutions == nullptr) {
    this->averageAmountOfResolutions = new double(value);
    this->numberOfResolutionEnties = new int(1);
  } else {
    *(this->averageAmountOfResolutions) = (*(this->averageAmountOfResolutions) * *(this->numberOfResolutionEnties) + value)/(++*(this->numberOfResolutionEnties));
  }
  this->stop();
}

double BoardOfDirectors::getAverageAmountOfResolutions() {
  this->start();
  this->log("Get Average Amount Of Resolutions");
  this->stop();
  return *(this->averageAmountOfResolutions);
}

void BoardOfDirectors::increaseCurrentBudget(float increase) {
  this->start();
  this->log("Increase Current Budget");
  if(this->currentBudget == nullptr) this->currentBudget = new float(increase);
  else *(this->currentBudget) += increase;
  this->stop();
}

void BoardOfDirectors::decreaseCurrentBudget(float decrease) {
  this->start();
  this->log("Decrease Current Budget");
  if(this->currentBudget == nullptr) this->currentBudget = new float(-1.0f * decrease);
  else *(this->currentBudget) -= decrease;
  this->stop();
}

float BoardOfDirectors::getCurrentBudget() {
  this->start();
  this->log("Get Current Budget");
  this->stop();
  return *(this->currentBudget);
}

bool BoardOfDirectors::lastAssemblyExists() {
  this->start();
  this->log("If Last Assembly Exists");
  this->overrideAssembly();
  this->stop();
  return this->lastAssembly != nullptr;
}

void BoardOfDirectors::overrideAssembly() {
  this->start();
  this->log("Override Last Assembly Date");
  if (this->scheduledAssembly != nullptr) {
    this->lastAssembly = this->scheduledAssembly;
    this->scheduledAssembly = nullptr;
  }
  this->stop();
}

void BoardOfDirectors::setScheduledAssembly(std::string date) {
  this->start();
  this->log("Set Scheduled Assembly");
  this->overrideAssembly();
  if(Date::validate(date)) {
  Date parsed = Date::parseDate(date);
    if ((this->scheduledAssembly == nullptr && this->lastAssembly == nullptr) || parsed.isAfter(*(this->lastAssembly))) {
      this->scheduledAssembly = new Date(parsed);
    } else {
      std::cout << "You cannot schedule assembly further or equal in the past then the last held assembly." << std::endl;
    }
  }
  else {
    std::cout << "This date is invalid" << std::endl;
  }
  this->stop();
}

Date BoardOfDirectors::getLastAssembly() {
  this->start();
  this->log("Get Scheduled Assembly");
  this->overrideAssembly();
  this->stop();
  return *(this->lastAssembly);
}

void BoardOfDirectors::setCompanyName(std::string name) {
  this->start();
  this->log("Set Company Name");
  if(this->companyName == nullptr) this->companyName = new std::string(name);
  *(this->companyName) = name;
  this->stop();
}

std::string BoardOfDirectors::getCompanyName() {
  this->start();
  this->log("Get Company Name");
  this->stop();
  return *(this->companyName);
}