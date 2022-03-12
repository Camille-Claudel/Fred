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
[insert schéma]

# Difficultés rencontrées et solutions apportées
## Choix de l’architecture
Chaque doigt est composé de 3 phalanges identiques (à la taille près), sauf pour le pouce qui n’a que 2 phalanges. Elles sont reliées par des articulations pouvant se plier de 60°. Les doigts sont attachés à une paume fixe sans fonction mécanique, le pouce étant incliné par rapport aux autres doigts. Les tendons des doigts sont prolongés à travers la paume, et passent par le poignet pour arriver aux moteurs, situés au niveau de l’avant bras. Ces moteurs sont des servomoteurs (capables de s’orienter précisément vers une position entre 0 et 180°), et contrôlés par une carte Arduino.
[insert schémas]

## Choix des méthodes de fabrication
Les articulations sont constituées de tubes pivotant autour d’un cure-dent, à la manière d’une charnière.  
Les tendons sont des fils de pêche, fins et résistants.  
Les phalanges et le bloc moteur sont des pièces imprimées en 3D en résine, ce qui permet d’avoir une géométrie très complexe et très précise.  
La paume est imprimée en 3D en PLA, ce qui est moins précis mais permet d’imprimer des pièces plus grandes.

## Asymétrie

## Résistance

## Tension
