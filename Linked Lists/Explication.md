Une liste chaînée est une structure de données pour laquelle :

* Les éléments qui se suivent sont liés par des pointeurs

* Le dernier élément pointe sur la valeur NULL

* On peut facilement augmenter ou réduire sa taille lors de l'exécution du programme (ajout/suppression d'éléments)

* Ne gâche pas d'espace mémoire (prend exactement la mémoire dont elle a besoin, mais un supplément est requis pour stocker les pointeurs)



Avantages des tableaux statiques :

* Simples et faciles à utiliser

* Puisqu'ils sont stockés de manière contigus, ils bénéficient d'une optimisation par les CPU

* Accès rapide et constant aux éléments car l'adresse mémoire de l'élément est calculée :
  
  * ```c
    int tab[5];
    
    // Adresse élément : tab + (sizeof(int) * 3)
    tab[3] = 1;
    ```

Inconvénients des tableaux statiques :

* Préalloue toute la mémoire nécessaire (selon la taille du tableau), peu importe que le tableau soit rempli ou non

* La taille est statique : on la spécifie avant de l'utiliser, et on ne peut pas la changer

* Allocation en un seul block : tous les éléments du tableau sont côte-à-côte en mémoire, ils sont contigus. Si le tableau est trop grand, il est possible qu'il n'y ait pas d'espace mémoire disponible pour le stocker puisqu'il ne peut pas être divisé en plusieurs fragments

* Insertion et suppression compliquées et coûteuses : pour insérer ou supprimer un élément à une position en particulier, il faudra décaler tous les éléments nécessaires



Pour résoudre certains inconvénients, il existe les tableaux dynamiques qui modifient leur taille en fonction du taux de remplissage : si le tableau est rempli à 35%, il va diviser sa taille par deux, ou s'il est rempli à 90%, il va mutliplier sa taille par 2 (en allouant de la mémoire et en faisant une copie des données).



Avantages des listes chaînées :

* On peut ajouter des éléments en un temps constant : O(1)



Inconvénients des listes chaînées :

* Le temps d'accès aux éléments individuels et lié à la position de l'élément : O(n)

* Compliquées à manipuler

* Gâchis de mémoire puisqu'il faut stocker les pointeurs, en plus des données


