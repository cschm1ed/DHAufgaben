
#include <iostream>

typedef struct s_point t_point;

typedef struct s_point {
	double x, y, z;
	t_point *next;
} t_point;

t_point *punkt_erzeugen(double x, double y, double z, t_point *punkt_ptr) {
	t_point *newPoint = (t_point*)calloc(sizeof(t_point), 1);

	newPoint->x = x;
	newPoint->y = y;
	newPoint->z = z;
	if (punkt_ptr) {
		punkt_ptr->next = newPoint;
	}
	return newPoint;
}

int anzahl_punkte(const t_point *punkt) {
	int i = 1;

	while (punkt->next) {
		i++;
		punkt = punkt->next;
	}
	return i;
}

void gebe_liste_aus(const t_point *point) {
	int i = 0;

	std::cout << "Anzahl der Elemente in Liste: " << anzahl_punkte(point) << "\n";
	while (point) {
		i ++;
		std::cout << "Element " << i << ": \n";
		std::cout << "X: " << point->x << " y: " << point->y << " z: " << point->z << "\n";
		point = point->next;
	}
	return ;
}

void punkt_am_anfang_einfügen(t_point **liste_ptr, t_point *neuer_ptr) {
	neuer_ptr->next = *liste_ptr;
	*liste_ptr = neuer_ptr;
	return ;
}

void punkt_an_index_einfuegen(t_point ** liste_ptr, t_point * neuer_punkt_ptr, unsigned index) {
	t_point *it = *liste_ptr;
	int i = 1;

	if (index == 0) {
		punkt_am_anfang_einfügen(liste_ptr, neuer_punkt_ptr);
		return ;
	}
	while (i < (int)index && it->next) {
		it = it->next;
		i++;
	}
	neuer_punkt_ptr->next = it->next;
	it->next = neuer_punkt_ptr;
	return ;
}

int main() {
	t_point *lst = punkt_erzeugen(1, 2, 3,  NULL);
	t_point *lst1 = punkt_erzeugen(4, 5, 6,  lst);
	t_point *lst2 = punkt_erzeugen(7, 8, 9, lst1);
	t_point *lst3 = punkt_erzeugen(10, 11, 12, lst2);

	std::cout << "Liste: \n";
	gebe_liste_aus(lst);
	std::cout << "\n---------------------------------------\n";
	std::cout << "Erstelle neuen Punkt am Anfang der Liste: \n";
	punkt_am_anfang_einfügen(&lst, punkt_erzeugen(0, 0, 0, NULL));
	std::cout << "Neue Liste: \n";
	gebe_liste_aus(lst);
	std::cout << "\n---------------------------------------\n";
	std::cout << "Erstelle neuen Punkt an index 3 der Liste: \n";
	punkt_an_index_einfuegen(&lst, punkt_erzeugen(9, 9, 9, NULL), 3);
	std::cout << "Neue Liste: \n";
	gebe_liste_aus(lst);
	std::cout << "\n---------------------------------------\n";
	(void)lst3;
}
