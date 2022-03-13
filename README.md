# Introduction
Ce projet a pour but la création d'une main robotique, en s'inspirant du fonctionnement d'une main humaine.

## Objectifs
L'objectif principal est de pouvoir plier ou déplier complètement chacun des doigts, indépendamment les uns des autres. On peut alors implémenter différents gestes de la main, et par exemple programmer un jeu de pierre-feuille-ciseaux. Les objectifs secondaires incluent la capacité à attraper des objets, et la capacité à plier les doigts dans des positions intermédiaires (ce qui permettrait notamment de réguler la vitesse à laquelle les doigts se plient ou se déplient). À plus long terme, le projet pourrait évoluer pour permettre des mouvements plus complexes, par exemple en contrôlant chaque phalange de manière indépendante ou en permettant des mouvements latéraux.

# Principe de fonctionnement
Chez l'homme, les muscles qui permettent de plier les doigts ne se trouvent pas dans les doigts: la flexion est contrôlée par des tendons, sur lesquels tirent des muscles situés dans l'avant-bras (en particulier le muscle fléchisseur profond des doigts).  
Pour chaque phalange, il y a un tendon fléchisseur situé du côté intérieur, et un tendon extenseur situé du côté extérieur. En tirant sur le tendon extenseur, le doigt se déplie, et en tirant sur le tendon fléchisseur il se plie.  
![19-06-27-15-40-36_798959289_thumbnail_large2](https://user-images.githubusercontent.com/80780126/158025087-eb34a25f-8309-4e65-be1a-1292a8b9763c.png)  
De nombreux autres tendons sont présents dans la main, mais ceux-ci sont les plus importants pour notre projet.  
Pour reproduire plus fidèlement une main biologique, il faudrait deux tendons fléchisseurs (et deux moteurs-muscles) pour chaque doigt. Cependant, il est plus simple pour l’instant de se limiter à un seul moteur-muscle et une seule paire de tendons pour chaque doigt.
Pour fermer le doigt, le moteur tourne de manière à tirer sur le tendon fléchisseur et à détendre le tendon extenseur, ce qui plie le doigt. En tournant le moteur dans l’autre sens, le doigt s’ouvre.
<!-- insert schéma-->

# Difficultés rencontrées et solutions apportées
## Choix de l’architecture
Chaque doigt est composé de 3 phalanges identiques (à la taille près), sauf pour le pouce qui n’a que 2 phalanges. Elles sont reliées par des articulations pouvant se plier de 60°. Un tendon passe à l'intérieur des phalanges dans des tubes prévus à cet effet. Les doigts sont attachés à une paume fixe sans fonction mécanique, le pouce étant incliné par rapport aux autres doigts. Les tendons des doigts sont prolongés à travers la paume, et passent par le poignet pour arriver aux moteurs, situés au niveau de l’avant bras. Ces moteurs sont des servomoteurs (capables de s’orienter précisément vers une position entre 0 et 180°), et contrôlés par une carte Arduino.
<!-- insert schéma-->

## Choix des méthodes de fabrication
Les articulations sont constituées de tubes pivotant autour d’un cure-dent, à la manière d’une charnière.  
Les tendons sont des fils de pêche, fins et résistants.  
Les phalanges et le bloc moteur sont des pièces imprimées en 3D en résine, ce qui permet d’avoir une géométrie très complexe et très précise.  
La paume est imprimée en 3D en PLA, ce qui est moins précis mais permet d’imprimer des pièces plus grandes.

## Résistance
Avec notre premier prototype, la force nécessaire pour plier et déplier le doigt était beaucoup trop importante. Afin d'y remédier, nous avons éloigné les tendons de l'axe central. Ainsi, le couple exercé sur les phalanges est maximisé, ce qui diminue la force nécessaire pour plier ou déplier le doigt.  
De plus, nous avons creusé les phalanges, pour minimiser la longueur des tubes dans lesquels coulissent les tendons. Cela a eu pour effet de rendre la flexion et l'extension du doigt beaucoup plus faciles. Notre interprétation est que les frottements sont importants à l'intérieur du tube, et donc que creuser les phalanges a permis de limiter ces frottements.  
  
un des premiers prototypes, non creusé:  

https://user-images.githubusercontent.com/80780126/158057855-3dfe5ac6-8ccf-417b-b1d2-d2896950691f.mp4

version creusée:

https://user-images.githubusercontent.com/80780126/158057845-7c2cb7db-0f5b-4b4f-a2d3-dff57d0a04f6.mp4


https://user-images.githubusercontent.com/80780126/158057828-58122a84-5a8c-4427-a4ee-840eac7bf1b1.mp4
  

## Asymétrie
Nous avons remarqué qu'avec le prototype que nous avions à ce stade, il était impossible de tendre les tendons correctement: s'ils étaient tendus quand le doigt était déplié, le tendon extenseur était détendu quand le doigt était plié. Nous avons réalisé que cela était dû à l'éloignement des tendons à l'axe central: ils étaient jusque là placés à la même distance, mais en réalité le tendon fléchisseur aurait dû être moins éloigné d'un facteur cos(30°) pour que la distance dont le fil doit être rétracté (notée ΔL sur le schéma) soit la même des deux côtés.
![image](https://user-images.githubusercontent.com/80780126/158038113-9be2ada1-6aff-4f4f-887b-9ff3cfda53d6.png)

## Tension
Tendre les tendons s'est révélé être plus difficile que prévu. En effet, il est très difficile de coller le fil au moteur en le maintenant tendu. Nous avons donc décidé de mettre en place un système pour pouvoir régler la position du moteur après avoir collé les fils.  
<!-- insert photo -->
