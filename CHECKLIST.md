# ✅ Checklist Discipline – 30 Jours
## Projet : Flappy Bird-like (C++ / SDL3 / ImGui / stb_image)

⏱️ Temps minimum par jour : **15 minutes**  
🎯 Objectif : **cocher une case chaque jour**

---

## 🟦 SEMAINE 1 — LANCEMENT

### Jour 1
- [X] Créer le repo / dossier projet
- [X] Compiler un `main.cpp`
- [X] Ouvrir une fenêtre SDL

📝 Note du jour : Pas motivé, mais j’ai quand même codé 20 min.


### Jour 2
- [X] Créer la boucle principale
- [X] Gérer les événements (quit)
- [X] Log simple dans la boucle

### Jour 3
- [X] Calculer le `deltaTime`
- [X] Afficher les FPS
- [X] Vérifier la stabilité

📝 Note du jour : à present je comprend mieux l'utilité du calcul du deltaTime 

### Jour 4
- [X] Gérer les entrées clavier
- [X] Déplacer un rectangle
- [X] Mouvement indépendant du framerate

### Jour 5
- [X] Créer une structure `Entity`
- [X] Stocker position / taille
- [X] Dessiner plusieurs entités

📝 Note du jour : J'apprends la discipline en m'abstenant de faire des amélioration à mon projet tôt mais en suivant le programme de la CHECKLIST.

### Jour 6
- [X] Séparer logique / rendu
- [X] Créer `Game.h / Game.cpp`
- [X] Nettoyage minimal

### Jour 7
- [X] Intégrer ImGui
- [X] Fenêtre debug
- [X] Afficher FPS / position joueur

---

## 🟩 SEMAINE 2 — JEU MINIMAL

### Jour 8
- [X] Créer le joueur (oiseau)
- [X] Appliquer une gravité simple

### Jour 9
- [X] Ajouter le saut (input)
- [X] Ajuster la physique (vitesse, gravité)

### Jour 10
- [X] Charger un sprite avec stb_image
- [X] Remplacer le rectangle

### Jour 11
- [X] Créer les tuyaux (obstacles)
- [X] Défilement horizontal

### Jour 12
- [ ] Détection de collision (oiseau / tuyaux)
- [X] Détection sol / plafond

### Jour 13
- [ ] Condition de défaite
- [ ] Reset du jeu

### Jour 14
- [ ] Debug ImGui :
  - [ ] gravité
  - [ ] force du saut
  - [ ] vitesse tuyaux

---

## 🟨 SEMAINE 3 — DISCIPLINE & STRUCTURE

### Jour 15
- [ ] Nettoyage de code léger
- [ ] Renommer variables / fonctions

### Jour 16
- [ ] Créer un `InputManager`
- [ ] Centraliser les inputs

### Jour 17
- [ ] Créer un `TimeManager`
- [ ] Supprimer les dépendances directes

### Jour 18
- [ ] Génération procédurale des tuyaux
- [ ] Espacement aléatoire

### Jour 19
- [ ] États du jeu :
  - [ ] Playing
  - [ ] Game Over

### Jour 20
- [ ] Simplifier une mécanique
- [ ] Supprimer du code inutile

### Jour 21
- [ ] Review hebdomadaire
- [ ] Notes personnelles

---

## 🟥 SEMAINE 4 — OUTILS RÉUTILISABLES

### Jour 22
- [ ] Créer un `Renderer2D`
- [ ] Centraliser le rendu

### Jour 23
- [ ] Créer un `World` / `Scene`
- [ ] Stocker les entités

### Jour 24
- [ ] Système d’update générique
- [ ] Boucle commune aux entités

### Jour 25
- [ ] Inspecteur ImGui (entités)
- [ ] Modifier valeurs en live

### Jour 26
- [ ] Gestionnaire de textures
- [ ] API `GetTexture(name)`

### Jour 27
- [ ] README simple
- [ ] Instructions de build

### Jour 28
- [ ] Session de jeu complète
- [ ] Corriger UN bug maximum

---

## 🏁 JOURS 29 & 30 — CLÔTURE

### Jour 29
- [ ] Lister les outils créés
- [ ] Identifier le code réutilisable

### Jour 30
- [ ] Marquer le projet TERMINÉ
- [ ] Ne rien refactor
- [ ] Célébrer la discipline 🎉


## 📓 Journal quotidien

### 📅 Jour 1 — 2026-01-07
⏱️ Temps : 30 min - 45 min  
☑️ Tâches cochées :
- [X] Créer le repo / dossier projet
- [X] Compiler un `main.cpp`
- [X] Ouvrir une fenêtre SDL

- [X] Créer la boucle principale
- [X] Gérer les événements (quit)
- [X] Log simple dans la boucle

🧠 Ce que j’ai appris :
- On libère les ressources (rendu, fenetre, SDL), dans l'ordre inverse de leur initialisation

⚠️ Difficulté :
- la seule difficulté était au niveau de la synthaxe qui n'est pas encore tres maîtrisé

➡️ Prochaine micro-action :
- [ ] Calculer le `deltaTime`
- [ ] Afficher les FPS
- [ ] Vérifier la stabilité

### 📅 Jour 2 — 2026-01-08
⏱️ Temps : 20 min  
☑️ Tâches cochées :
- [X] Calculer le `deltaTime`
- [X] Afficher les FPS
- [X] Vérifier la stabilité

🧠 Ce que j’ai appris : Astuce pour afficher les FPS en console à intervalle de temps régulier. 
```cpp
double fpsTimer = 0.0;
int frameCount = 0;

fpsTimer += deltaTime;
frameCount++;

if (fpsTimer >= 1.0)
{
    double fps = frameCount / fpsTimer;
    std::cout << "FPS: " << fps << std::endl;

    fpsTimer -= 1.0; // au lieu de = 0.0
    frameCount = 0;
}
```

⚠️ Difficulté : obtenir les bonnes valeurs de FPS par calcul.

➡️ Prochaine micro-action :
- [ ] Gérer les entrées clavier
- [ ] Déplacer un rectangle
- [ ] Mouvement indépendant du framerate

### 📅 Jour 3 — 2026-01-09
⏱️ Temps : 30 min - 45 min 
☑️ Tâches cochées :
- [X] Gérer les entrées clavier
- [X] Déplacer un rectangle
- [X] Mouvement indépendant du framerate

- [X] Créer une structure `Entity`
- [X] Stocker position / taille
- [X] Dessiner plusieurs entités

🧠 Ce que j’ai appris : SDL_PollEvent met à jour j'etat des inputs doit venir avant SDL_GetKeyboardState (retourne un pointeur) qui fait la lecture de l'etat encours du clavier. 
SDL_GetKeyboardState = lecture passive
SDL_PollEvent = mise à jour active

⚠️ Difficulté : s'en tenir au programme sans ajouter d'autres fonctionnalitées.

➡️ Prochaine micro-action :
- [ ] Séparer logique / rendu
- [ ] Créer `Game.h / Game.cpp`
- [ ] Nettoyage minimal

### 📅 Jour 4 — 2026-01-10
⏱️ Temps : 50 min - 60 min 
☑️ Tâches cochées :
- [X] Séparer logique / rendu
- [X] Créer `Game.h / Game.cpp`
- [X] Nettoyage minimal

🧠 Ce que j’ai appris :
⚠️ Difficulté :
➡️ Prochaine micro-action :

### 📅 Jour 5 — 2026-01-11
⏱️ Temps : 20 min 
☑️ Tâches cochées :
- [X] Intégrer ImGui
- [X] Fenêtre debug
- [X] Afficher FPS / position joueur

🧠 Ce que j’ai appris :
⚠️ Difficulté :
➡️ Prochaine micro-action :

### 📅 Jour 6 — 2026-01-12
⏱️ Temps : 15 min - 20 min 
☑️ Tâches cochées :
- [X] Créer le joueur (oiseau)
- [X] Appliquer une gravité simple
- [X] Ajouter le saut (input)
- [X] Ajuster la physique (vitesse, gravité)

🧠 Ce que j’ai appris :
⚠️ Difficulté :
➡️ Prochaine micro-action :
- [ ] Charger un sprite avec stb_image
- [ ] Remplacer le rectangle