#include <iostream>
#include "BoardOfDirectors.h"
#include "Logger.h"
#include "Stopper.h"
using namespace std;

void loadBoard(BoardOfDirectors &board) {
  cout << "Insert number of members appointed by the general meeting: ";
  cout.flush();
  int numberOfMembers;
  cin >> numberOfMembers;
  cin.ignore();
  board.setNumberOfMembers(numberOfMembers);

  cout << "Insert number of members to dismiss: ";
  cout.flush();
  int numberOfMembersToDismiss;
  cin >> numberOfMembersToDismiss;
  cin.ignore();
  board.dismissNumberOfMembers(numberOfMembersToDismiss);
  
  cout << "Current number of members is " << board.getNumberOfMembers() << "." << endl;

  cout << "Insert over how many years were resolutions passed: ";
  cout.flush();
  int numberOfYears;
  cin >> numberOfYears;
  cin.ignore();
  for (int i = 1; i <= numberOfYears; i++) {
    cout << "Insert number of resolutions passed in year " << i << ": ";
    cout.flush();
    int numberOfResolutions;
    cin >> numberOfResolutions;
    cin.ignore();
    board.insertNewResolutionEntry(numberOfResolutions);
  }

  cout << "Average amount of resolutions passed over the years is " << board.getAverageAmountOfResolutions() << "." << endl;

  cout << "Insert increase in budget: ";
  cout.flush();
  float increaseInBudget;
  cin >> increaseInBudget;
  cin.ignore();
  board.increaseCurrentBudget(increaseInBudget);

  cout << "Insert decrease in budget: ";
  cout.flush();
  float decreaseInBudget;
  cin >> decreaseInBudget;
  cin.ignore();
  board.decreaseCurrentBudget(decreaseInBudget);

  cout << "Current budget is " << board.getCurrentBudget() << "." << endl;

  cout << "Insert date of future assembly in format yyyy-mm-dd: ";
  cout.flush();
  string date;
  cin >> date;
  cin.ignore();
  board.setScheduledAssembly(date);
  
  cout << "Insert another date of future assembly (next one) in format yyyy-mm-dd: ";
  cout.flush();
  string date2;
  cin >> date2;
  cin.ignore();
  board.setScheduledAssembly(date2);

  cout << "Last assembly happened: " << (board.lastAssemblyExists() ? board.getLastAssembly().toString() : "never") << "." << endl;
  
  cout << "Insert company name: ";
  cout.flush();
  string companyName;
  getline(cin, companyName);
  board.setCompanyName(companyName);

  cout << "Company name is '" << board.getCompanyName() << "'." << endl;
}

void hardCodeBoard(BoardOfDirectors &board) {
  board.setNumberOfMembers(20);
  board.insertNewResolutionEntry(15);
  board.insertNewResolutionEntry(3);
  board.insertNewResolutionEntry(17);
  board.insertNewResolutionEntry(4);
  board.increaseCurrentBudget(20);
  board.setScheduledAssembly("2020-10-10");
  board.setCompanyName("Company Name");
}

void readBoard(BoardOfDirectors &board) {
  cout << "Current number of members is " << board.getNumberOfMembers() << "." << endl;
  cout << "Average amount of resolutions passed over the years is " << board.getAverageAmountOfResolutions() << "." << endl;
  cout << "Current budget is " << board.getCurrentBudget() << "." << endl;
  cout << "Last assembly happened: " << (board.lastAssemblyExists() ? board.getLastAssembly().toString() : "never") << "." << endl;
  cout << "Company name is '" << board.getCompanyName() << "'." << endl;
}

// Zadanie 14
void foo(BoardOfDirectors board) {
  cout << "Current number of members is " << board.getNumberOfMembers() << "." << endl;
}

// Zadanie 18
void bar(const BoardOfDirectors &board) {
  cout << "Bar" << endl;
}

// Zadanie 20
void baz(BoardOfDirectors &board) {
  cout << "Current number of members is " << board.getNumberOfMembers() << "." << endl;
}

// Zadanie 22
void qux(BoardOfDirectors &&board) {
  cout << "Current number of members is " << board.getNumberOfMembers() << "." << endl;
}

int main() {
  BoardOfDirectors board;
  // loadBoard(board);
  hardCodeBoard(board);
  // readBoard(board);

  // Zadanie 15 - Został wykonany konstruktor kopiujący
  // foo(board);

  // Zadanie 16 - Został wykonany konstruktor przenoszący
  // foo(move(board));

  // Zadanie 17 - Został wykonany konstruktor konwertujący
  // foo(42);

  // Zadanie 19 - 15 - 
  // Nie wykonany konstruktor kopiujący przez to, że przekazujemy obiekt jako referencje,
  // po przekazaniu referencji obiekt jest stałą (const) nie możemy na nim wykonywać żadnych operacji ze względu na budowe obiektu. 
  // bar(board);

  // Zadanie 19 - 16 - 
  // Nie został wykonany konstruktor przenoszący przez to, że przekazujemy obiekt jako referencje i referencja ta wciąż musi do czegoś prowadzić, 
  // więc nie możemy usunąć obiektu, po przekazaniu referencji obiekt jest stałą (const) nie możemy na nim wykonywać żadnych operacji ze względu na budowe obiektu. 
  // bar(move(board));

  // Zadanie 19 - 17
  // Został wykonany konstruktor konwertujący aby można było wykonywać operacje na obiekcie wewnątrz funkcji (obiekt musi istnieć)
  // po utworzeniu obiekt jest stałą (const) nie możemy na nim wykonywać żadnych operacji ze względu na budowe obiektu, obiekt ten jest usuwany po zakończeniu funkcji. 
  // bar(42);

  // Zadanie 21 - 15
  // Nie został wykonany konstruktor kopiujący przez to, że przekazujemy obiekt jako referencje,
  // po przekazaniu referencji mamy dostęp do tych samych operacji co w funkcji, z której ta referencja została przekazana
  // baz(board);

  // Zadanie 21 - 16
  // Wystąpi błąd związany z brakiem możliwości przypisania wartości tymczasowej (stworzonej przez polecenie move) do referencji w funkcji nie będącej wartością const
  // dzieje się tak gdyż const pozwala przypisać do zmiennej referencyjnej tymczasowej wartości rvalue
  // baz(move(board));

  // Zadanie 21 - 17
  // Tak samo jak wyżej do zmiennej referencyjnej nie bedącej stałą (const) nie można przypisać tymczasowej wartości
  // baz(42);

  // Zadanie 23 - 15
  // Wystąpi bład związany z tym, że funkcja qux przyjmuje wartość rvalue (tymczasową) a zmienna board jest wartością lvalue (tj. nie tymczasową).
  // qux(board);

  // Zadanie 23 - 16
  // Nie zostanie wykonany konstruktor przenoszący
  // polecenie move utworzy wartość rvalue (tymczasową) z obiektu board, zostanie ona przekazana do funkcji która przyjmuje referencję tymczasową
  // qux(move(board));

  // Zadanie 23- 17
  // Został wykonany konstruktor konwertujący tworzący wartość obiektu jako rvalue
  // qux(42);

  // Zadanie 26
  // Domyślnym modyfikatorem w przypadku dziedziczenia jest private, ktory zmienia wszystkie metody z klasy Logger na private sprawia to, 
  // iż nie ma do nich dostępu w funkcji main lecz dostęp ten jest możliwy wewnątrz klasy BoardOfDirectors ponieważ na niej są poniekąd zdefiniowane (po dziedziczeniu)
  // board.log("text");

  // Zadanie 27
  // board.getNumberOfMembers();
  
  // Zadanie 29
  // Konstruktory BoardOfDirectors nie mają teraz domyślnego konstruktora Logger gdyż przy manualnym utworzenia konstruktora w klasie Logger domyślny konstruktor
  // bezargumentowy przestaje być dostępny, aby naprawić kod należy jako jedno z rozwiązań do klasy Logger dodać konstruktor bezargumentowy.

  // Zadanie 31
  // for(int i = 0; i < 30; i++) {
  //   board.increaseCurrentBudget(1);
  // }
  // board.print();

  // Zadanie 32
  // Przy dziedziczeniu z wielu klas jednocześnie wzrasta ryzyko problemu z utrzymaniem porządku w kodzie oraz z utrzymaniem unikatowego nazewnictwa.
  // Kod używający wielokrotnego dziedziczenia jest zazwyczaj także wysoce zależny od kodu znajdującego się w wielu różnych plikach co wprowadza zamęt.
  // Problem powstaje także wtedy kiedy obie klasy (z których dziedziczymy) posiadają tą samą metodę gdyż należy wtedy decydować, która z nich powinna zostać wykonana.
  // Java nie wspiera wielokrotnego dziedziczenia, ale umożliwia implementacje wielu interfejsów gdyż nie definiują one ciała funkcji lecz ich nazewnictwo,
  // interfejsy mogą mieć domyślne ciało funkcji lecz nawet w takiej sytuacji nadpisując metody interfejsu można w nich rozróżniać między kodem domyślnym 
  // pierwszego a drugiego interfejsu.
  return 0;
}