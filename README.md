# Merchant
program for a merchant


LE PROBLÈME
Écrire un programme permettant de faire des commandes de marchandises, avec gestion 
intégrée de l'inventaire. Une commande portera sur un seul produit à la fois. Des 
messages appropriés avertiront l'usager dans les cas où la commande ne peut pas être 
complétée. Vous calculerez la facture (si pertinent), et ferez la mise à jour de l’inventaire, 
de sorte que le niveau réel de l’inventaire de chaque produit soit exact à tout moment. 
2
Trois niveaux d’inventaire (la quantité en stock) sont possibles:
• un inventaire positif (>0) indique que nous avons ce produit en stock
• un inventaire nul (==0) indique que nous n’avons plus de ce produit
• un inventaire négatif (<0) indique que non seulement nous n’avons plus de ce 
produit, mais que des clients ont voulu commander de 
ce produit.
➔ La valeur absolue de ce nombre négatif indique 
combien d'exemplaires du produit n’ont pu être livrés 
aux clients.

QUELLES SONT LES GRANDES ÉTAPES DE TRAITEMENT?
1. La saisie d'une commande
La saisie d’une commande se fait en deux étapes:
a) la saisie du numéro du produit
➔Le numéro du produit doit exister dans notre liste des produits.
b) la saisie de la quantité désirée 
➔la quantité doit être supérieure à 0
→ Ne pas vérifier que c'est un nombre entier qui est entré ( pas de cin.fail(), on suppose 
qu'il n'y a pas d'erreur )
2. L'affichage de la facture, puis la mise à jour de l’inventaire
Suite à la validation du numéro du produit et la saisie de la quantité désirée, nous 
devons calculer le montant de la facture, avec les diverses taxes. Nous ne devons 
facturer que les produits livrés, bien entendu. Il faudra donc consulter l’inventaire. 
Trois cas sont possibles:
a) nous pouvons satisfaire la commande entièrement
b) nous ne pouvons satisfaire la commande que partiellement
c) nous ne pouvons pas satisfaire la commande du tout
Nous terminerons une commande par la mise à jour de l’inventaire.
3. L'arrêt du programme.
Suite à l’affichage de la facture (si pertinent) ou d’un message d’erreur, nous 
demanderons à l’usager s’il désire entrer une nouvelle commande ou non.
QUELLES SONT LES VALEURS CONNUES?
Le numéro du produit.
La quantité désirée.
L’inventaire de l’entreprise, provenant du fichier stock.
