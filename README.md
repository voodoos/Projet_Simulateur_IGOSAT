Projet Simulateur IGOSAT
========================

## Documentation
http://voodoos.github.io/Projet_Simulateur_IGOSAT/IGOsim/doc/html/index.html

## Installation
Commencez par cloner le dépôt dans le dossier de votre choix via l'application github ou la commande:
```git clone https://github.com/VooDooS/Projet_Simulateur_IGOSAT.git```

Ensuite vous pouvez importer les sources, situées dans le dossier *IGOsim/src*, directement dans votre IDE (CodeBlocks, VisualC++, XCode..) et lancer la compilation. Ce faisant soyez attentifs à ne pas enregistrer sous git les différents fichiers de configurations propres au logiciel choisi (via le fichier .gitignore par exemple).

~~Il est également possible (ou presque.....), sous Linux, de compiler directement en invoquant la commande `make` depuis le dossier *src*.~~



## Génération de la documentation
Le projet utilise [*doxygen*](http://www.stack.nl/~dimitri/doxygen/index.html) pour générer sa documentation. Un fichier de configuration est fourni, nommé *doxy.conf*.

Pour générer manuellement la doc il suffit de se placer dans le répertoire *src* et de lancer la commande:
```doxygen doxy.conf```
