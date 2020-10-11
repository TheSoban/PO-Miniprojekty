package hello;

import java.util.Scanner;

public class World {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String fellow = "World";
        System.out.printf("Hello %s\n", fellow);
        while (fellow.equals("exit")) {
            System.out.printf("Introduce yourself: ");
            fellow = s.nextLine();
            System.out.printf("Hello %s\n", fellow);
        }
        s.close();
    }
}

/*
8 oraz 9.
Program nie działa zgodnie z oczekiwaniem gdyż w języku Java porównanie za pomocą operatorów "==" oraz "!=" sprawdza czy elementy na których operatory te zostały wykorzystane
są tą samą instancją klasy (czyli czy dzielą referencje do tego samego obiektu), w tym przypadku tak nie jest co zmusza nas do użycia metody klasy String "String.equals()", 
która porównuje jedynie wartość ciągu znaków.
*/