# Files-on-Pendrives-AiSD-Project-1


Files on pendrives (AiSD 2021 P1)
There are files on your disk. You have to copy as many files as possible into two pendrives. Files cannot be divided. Write a program that will select files. Your answer can be different from optimal result by 1.

Na Twoim dysku znajdują się pliki. Trzeba przekopiować jak najwięcej plików na dwa pendrajwy. Plików nie można dzielić. Napisz program, który wybierze pliki. Twoja odpowiedź może różnić się o maksymalnie 1 od optymalnego wyniku.

Input/Wejście
In the first line there are two numbers n p - number of files and pendrives' size.
In the next n lines there are two numbers id r - file identifier and file size.

W pierwszej linii znajdują się dwie liczby n p - liczba plików i rozmiar pendrajwów.
W kolejnych n liniach znajdują się po dwie liczby id r - identyfikator pliku i rozmiar pliku.

Output/Wyjście
In the first line write a number - total number of copied files. In the next two lines write '1:' or '2:' with lists of copied file's identifiers. The lists should be sorted in descending order.

W pierwszej linii liczba - ile plików zdołano skopiować, a następnie w dwóch liniach '1:' lub '2:' wraz z listami identyfikatorów plików, które zostały przekopiowane na odpowiadające pendrajwy. Identyfikatory powinny być posortowane od największej do najmniejszej.

Example/Przykład
Input/Wejście
4 7
323 1 
10 2 
87438 5 
99 6


Output/Wyjście
3
1: 323 10
2: 87438

or/lub
4
1: 323 99
2: 87438 10

or/lub
3
1: 323
2: 87438 10
