#include <memory>
#include "Node.h"

using namespace std;

int main() {
  for (int i = 0; i < 10; i++) {
    // unique_ptr<Node>(new Node());
    // shared_ptr<Node> n1 = make_shared<Node>();

    shared_ptr<Node> n1 = make_shared<Node>();
    shared_ptr<Node> n2 = make_shared<Node>();
    n1->next = n2;
    n2->next = n1;
  }
  return 0;
  // Zadanie 4
  // W przeciwieństwie do metody finalize w języku Java, destruktory w języku c++ mają gwarancję uruchomienia, 
  // zatem przy 10 utworzonych obiektach wykonuję się 10 destruktorów.

  // Zadanie 6
  // unique_ptr działa tak, że nie można tworzyć dodatkowych dowiązań do pojedynczego wskaźnika a shared_ptr tak, że jest to jak najbardziej dozwolone.
  // W tej sytuacji jednak nie tworzymy dodatkowych dowiązań więc nie ma to różnicy.

  // Zadanie 7
  // Program nie zwalnia pamięci tak jak powinien. shared_ptr posiada licznik dowiązań zaczynający z wartością 1, ten licznik jest inkrementowany przy tworzeniu
  // nowych dowiązań oraz dekrementowany przy usuwaniu dowiązań lub wyjściu ich poza zasięg (scope). Przy osiągnięciu wartości 0 dane są usuwane.
  // W tym przypadku tworzymy dowiązanie do wskaźników nawzajem czyli licznik ich dowiązań równy jest 2. Przy wyjściu poza zasięg ilość dowiązań jest dekrementowana
  // do 1 i mimo braku dostępu do danych pamięć nie jest zwalniana. Można ten problem rozwiązać za pomocą użycia weak_ptr na jednym z węzłów.  
}