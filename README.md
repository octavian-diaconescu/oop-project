# ___Showly___ (inspired by the real mobile app)

## ___Functionality___:
    - Create a watchlist (a list of movies or tv shows/series)
    - Add content to that watchlist with the possibilty of marking it as watched / rating it
    - Print the contents of a chosen watchlist
    - Print a list of episodes from a chosen tv show
    - Update the status of a content after adding it in a watchlist
    - Delete an item from a watchlist / delete a watchlist entirely
    - Sort the contents of a watchlist by category and print the results
    - Register a new user
    
## ___Restrictions___
   - The C++ code does not provide a real connection with a database. Instead, I have opted for simulating a database for the movies and series with txt files.  
   - The program was built with a sole user in mind; that is, only one user can exist at a time. Registering a user will also save the watchlists and its contents for future use. After registration, the program will load the files from storage for proper functionality.  
       - Interaction through CLI as a proper front end is not implemented. 
   

# Nu primesc notă pentru că nu am pus titlu și descriere

## Cerințe obligatorii

Nerespectarea duce la nepunctarea proiectului

  - programul va fi scris în C++
  - programul va avea un meniu interactiv (doar pentru ilustrarea funcționalității)
  - programul nu are erori de compilare
  - fară variabile globale
  - datele membre private(sau protected)
  - GitHub Actions trecute
  - commit-uri pe Git adecvate si punctuale
  - folosirea a funcționalităților limbajului fără sens
  - folosirea a funcționlităților limbajului cu scopul de a încălca "legal" o altă regulă
      - folosirea excesivă a claselor friend
      - folosirea excesviă a elementelor statice
  - fiecare cerinta va fi punctate 1/2 pe implementare + 1/2 pe faptul ca a fost implementata cu sens

## Cerințe
- [x] definirea a minim **2-3 ieararhii de clase** care sa interactioneze in cadrul temei alese (fie prin compunere, agregare sau doar sa apeleze metodele celeilalte intr-un mod logic) (6p)
  - minim o clasa cu:
    - [x] constructori de inițializare
    - [x] constructor supraîncărcat
    - [x] constructori de copiere
    - [x] `operator=` de copiere
    - [x] destructor
    - [x] `operator<<` pentru afișare (std::ostream)
    - [x] `operator>>` pentru citire (std::istream)
    - [x] alt operator supraîncărcat ca funcție membră
    - [x] alt operator supraîncărcat ca funcție non-membră
  - in derivate
      - [x] implementarea funcționalităților alese prin [upcast](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding) și [downcast](https://github.com/Ionnier/poo/tree/main/labs/L04#smarter-downcast-dynamic-cast)
        - aceasta va fi făcută prin **2-3** metode specifice temei alese
        - funcțiile pentru citire / afișare sau destructorul nu sunt incluse deși o să trebuiască să le implementați 
      - [x] apelarea constructorului din clasa de bază din [constructori din derivate](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-la-derivare)
      - [x] suprascris [cc](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-de-copiere-la-derivare)/op= pentru copieri/atribuiri corecte
      - [x] destructor [virtual](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding)
  - pentru celelalte clase se va definii doar ce e nevoie
  - minim o ierarhie mai dezvoltata (cu 2-3 clase dintr-o clasa de baza)
  - ierarhie de clasa se considera si daca exista doar o clasa de bază însă care nu moștenește dintr-o clasă din altă ierarhie
- [x] cât mai multe `const` [(0.25p)](https://github.com/Ionnier/poo/tree/main/labs/L04#reminder-const-everywhere)
- [x] funcții și atribute `static` (în clase) [0.5p](https://github.com/Ionnier/poo/tree/main/labs/L04#static)
  - [x] 1+ atribute statice non-triviale 
  - [x] 1+ funcții statice non-triviale
- [ ] excepții [0.5p](https://github.com/Ionnier/poo/tree/main/labs/L04#exception-handling)
  - porniți de la `std::exception`
  - ilustrați propagarea excepțiilor
  - ilustrati upcasting-ul în blocurile catch
  - minim folosit într-un loc în care tratarea erorilor în modurile clasice este mai dificilă
- [x] folosirea unei clase abstracte [(0.25p)](https://github.com/Ionnier/poo/tree/main/labs/L04#clase-abstracte)
 - [x] clase template
   - [x] crearea unei clase template [(1p)](https://github.com/Ionnier/poo/tree/main/labs/L08)
   - [x] 2 instanțieri ale acestei clase (0.5p)
 - STL [(0.25p)](https://github.com/Ionnier/poo/tree/main/labs/L07#stl)
   - [x] utilizarea a două structuri (containere) diferite (vector, list sau orice alt container care e mai mult sau mai putin un array)
   - [x] utilizarea a unui algoritm cu funcție lambda (de exemplu, sort, transform)
 - Design Patterns [(0.75p)](https://github.com/Ionnier/poo/tree/main/labs/L08)
   - [x] utilizarea a două șabloane de proiectare

### Observații

* Pot exista depunctări până la 2p pentru diferite aspecte precum:
  - memory leak-uri
  - nefolosirea destructorului virtual la nevoie
  - abuzarea de diferite concepte (toate funcțiile declarate virtual)
  - apelarea de funcții virtual în constructori

* În general, acestea sunt prezente în [CppCoreGuideline](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md), dar nu e nevoie să parcurgeți documentul, doar să scrieți codul suficient de organizat
