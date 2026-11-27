#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <vector>
#include <string>

// ================================
// Struttura contatto
// ================================
struct contact {
    std::string surname;
    std::string name;
    std::string phoneNumber;
};

// ================================
// Tipo phoneBook come vettore di contatti
// ================================
typedef std::vector<contact> phoneBook;

// ================================
// Prototipi delle funzioni
// ================================
void push_contact_in_phoneBook(phoneBook &B, const std::string &surname, const std::string &name,
                               const std::string &number);
void print_phoneBook(const phoneBook &B);
void read_phoneBook_from_file(phoneBook &B, const std::string &fileName);
void write_phoneBook_to_file(const phoneBook &B, const std::string &fileName);
void sort_phoneBook_by_surnames(phoneBook &B);
bool find_phoneBook_contact_by_surname(const phoneBook &B, const std::string &s, std::size_t &pos);
void shift_phoneBook(phoneBook &B, std::size_t pos);
void add_contact_to_phoneBook(phoneBook &B, const std::string &surname, const std::string &name,
                              const std::string &number);

#endif // PHONEBOOK_H
