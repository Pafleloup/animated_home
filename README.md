# animated_home
animation vers le menu home

1  convertir la liste d'image en bg2.cpp :

requis avoir python , les modules tkinter et PIL

creer un dossier avec les images (uniquement) numérotés de 1.png a x.png  dans leur ordre d'apparition a l'ecran.
![alt text](https://github.com/Pafleloup/animated_home/assets/140179744/5b44820d-8cff-413f-b869-cdb6a9ad184e)
la taille importe peu mais seul les 320*240 premiers pixels seront convertis ( au moins 320 de long ou changer manuellement dans bg.cpp l.74)

Lancer le script conversion_to_anim_numworks.py , sera demandé de choisir le dossier avec les images, puis appuyé sur convertir, les images seront convertis en palette de 16 couleurs puis s'afficheront sur l'écran
( seul un appercu redimensionné est affiché donc pas le resultat final )

![alt text](https://github.com/Pafleloup/animated_home/assets/140179744/b382d4dd-c24f-4ea5-bb27-cc945141e887)

appuyer sur export et choisissez le dossier dans lequel l'exporter, y seront enregistré toutes les images sous le nom x_conv.png, et le fichier bg2.cpp

2 remplacer le dossier home dans le sdk :

Upsilon/apps/home par celui fourni et remplacer dedans bg2.cpp par le votre.

bg2.cpp contient une liste de chaque image sous format texte

si vous voulez le fond d ecran avec vous prenez la derniere image affichée x_conv.png et vous la redimmensionner en comptant les pixels de la barre en haut (28 je crois ) et vous l'installer

Aide conversion video to image :

Utiliser le script en python presque eponyme, modifié la variable l.9 pour definir le nombbre de frames passées (divise par x+1 le nb de fps)
Aide conversion gif -> liste image :
requis Scratch:

ouvrez scratch aller dans le costume du chat et cliquez sur importer un fichier et selectionner le gif ca peut lagger c normal
![alt text](https://github.com/Pafleloup/animated_home/assets/140179744/1d3b7eb7-570e-4e1f-af47-c00d64b6f32f)
![alt text](https://github.com/Pafleloup/animated_home/assets/140179744/b94819b2-faf2-4c7e-b5c8-5bf210340634)

ce sera ensuite convertis en une liste de sprites qu'il seras possible d'exporter


