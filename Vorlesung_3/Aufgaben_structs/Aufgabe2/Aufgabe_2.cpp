
#include <iostream>
#include <vector>
#include <sstream>

typedef struct s_date {
	int day;
	int month;
	int year;
} t_date;

typedef struct s_time {
	int hour;
	int minute;
} t_time;

typedef struct s_appointment {
	t_date	date;
	t_time	time;
	std::string title;
} t_appointment;

void printCalendar(const std::vector<t_appointment> calendar) {
	std::vector<t_appointment>::const_iterator it;

	for (it = calendar.begin(); it != calendar.end(); ++it) {
		std::cout << "Termin: " << it->title << "\n"
				  << "Datum: " << it->date.day << "/" << it->date.month << "/" << it->date.year << "\n"
				  << "Uhrzeit: " << it->time.hour << ":" << it->time.minute << "\n\n";
	}
}

void createAppointment(std::vector<t_appointment> & calendar) {
	std::string input;
	t_appointment appointment;
	bzero(&appointment, sizeof(t_appointment));

	std::cout << "Name des Termin eingeben: ";
	std::getline(std::cin, appointment.title);
	std::cout << "Datum eingeben (DD MM YYYY): ";
	std::getline(std::cin, input);
	std::stringstream(input) >> appointment.date.day >> appointment.date.month >> appointment.date.year;
	std::cout << "Uhrzeit des Termins eingeben (HH MM SS): ";
	std::getline(std::cin, input);
	std::stringstream(input) >> appointment.time.hour >> appointment.time.minute;
	std::cout << "\n";
	calendar.push_back(appointment);
}

int main() {
	std::vector<t_appointment> calendar;
	std::string input;

	while (1) {
		if (calendar.size() >= 10) {
			std::cout << "Kalender ist voll, Termine: \n";
			printCalendar(calendar);
			return 0;
		}
		std::cout << "Um einen neuen Termin zu erstellen 'Y' eingeben, ansonsten wird der Kalender ausgegeben: ";
		std::getline(std::cin, input);
		if (input == "y" || input == "Y") {
			createAppointment(calendar);
		} else {
			printCalendar(calendar);
			return 0;
		}
	}
}
