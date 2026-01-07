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
- [ ] Calculer le `deltaTime`
- [ ] Afficher les FPS
- [ ] Vérifier la stabilité

### Jour 4
- [ ] Gérer les entrées clavier
- [ ] Déplacer un rectangle
- [ ] Mouvement indépendant du framerate

### Jour 5
- [ ] Créer une structure `Entity`
- [ ] Stocker position / taille
- [ ] Dessiner plusieurs entités

### Jour 6
- [ ] Séparer logique / rendu
- [ ] Créer `Game.h / Game.cpp`
- [ ] Nettoyage minimal

### Jour 7
- [ ] Intégrer ImGui
- [ ] Fenêtre debug
- [ ] Afficher FPS / position joueur

---

## 🟩 SEMAINE 2 — JEU MINIMAL

### Jour 8
- [ ] Créer le joueur (oiseau)
- [ ] Appliquer une gravité simple

### Jour 9
- [ ] Ajouter le saut (input)
- [ ] Ajuster la physique (vitesse, gravité)

### Jour 10
- [ ] Charger un sprite avec stb_image
- [ ] Remplacer le rectangle

### Jour 11
- [ ] Créer les tuyaux (obstacles)
- [ ] Défilement horizontal

### Jour 12
- [ ] Détection de collision (oiseau / tuyaux)
- [ ] Détection sol / plafond

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
⏱️ Temps : 20 min  
☑️ Tâches cochées :
- [X] Créer le repo / dossier projet
- [X] Compiler un `main.cpp`
- [X] Ouvrir une fenêtre SDL

🧠 Ce que j’ai appris :
- On libère les ressources (rendu, fenetre, SDL), dans l'ordre inverse de leur initialisation

⚠️ Difficulté :
- la seule difficulté était au niveau de la synthaxe qui n'est pas encore tres maîtrisé

➡️ Prochaine micro-action :
- [ ] Créer la boucle principale
- [ ] Gérer les événements (quit)
- [ ] Log simple dans la boucle